<?
	class CMODEL_ACCOUNT extends MODEL_COMPLEX {
		
		protected $_parent_account_cmodel 	= null;
		protected $_account_cmodels 		= array();
		protected $_account_user_cmodels 	= array();
		
		public function __construct() {
			$this->register_dbo(new DBO_ACCOUNT);
		}

		public function set_account_users($value) { $this->_account_user_cmodels = $value; return $this; }

		public function get_account_users($load=false,$account_user_hmodel=null) {
			if($load && !$this->_account_user_cmodels) {
				if(!$account_user_hmodel)
					$account_user_hmodel = HMODEL_ACCOUNT_USER::get_default_handler();
				$account_user_hmodel->where("account_id","=",$this->get_account_id());
				$this->_account_user_cmodels = $account_user_hmodel->gets();
			}
			return $this->_account_user_cmodels;
		}
		public function set_accounts($value) { $this->_account_cmodels = $value; return $this; }

		public function get_accounts($load=false,$account_hmodel=null) {
			if($load && !$this->_account_cmodels) {
				$account_hmodel = $account_hmodel ? $account_hmodel : new HMODEL_ACCOUNT();
				$account_hmodel->where("parent_account_id","=",$this->get_account_id());
				$this->_account_cmodels = $account_hmodel->gets();
			}
			return $this->_account_cmodels;
		}

		public function set_parent_account($value) { $this->_parent_account_cmodel = $value; }

		public function get_parent_account($load=true) {
			if($load && !$this->_parent_account_cmodel) $this->_parent_account_cmodel = $this->get_parent_account_id() ? HMODEL_PARENT_ACCOUNT::get($this->get_parent_account_id()) : null;
			return $this->_parent_account_cmodel;
		}
		
		public function is_state_active()	{ return $this->get_state()==DBQ_ACCOUNT::STATE_ACTIVE; }
		public function is_state_deleted()	{ return $this->get_state()==DBQ_ACCOUNT::STATE_DELETED; }
		public function is_type_default()	{ return $this->get_type()==DBQ_ACCOUNT::TYPE_DEFAULT; }
		public function get_state_name()	{ return get_value(DBQ_ACCOUNT::get_state_list(),$this->get_state()); }
		public function get_type_name()		{ return get_value(DBQ_ACCOUNT::get_type_list(),$this->get_type()); }
		public function get_manage_url()	{ return "/manage/account/aid:".$this->get_account_id()."/"; }

		public function delete() {
			$this->set_state(DBQ_ACCOUNT::STATE_DELETED);
			return $this->get_dbo("account")->update();
		}

		public function get_subordinate_accounts() {
			return $this->_get_subordinate_accounts($this);			
		}		

		public function _get_subordinate_accounts($account_cmodel) {	

			$account_cmodels = $account_cmodel->get_accounts(true);

			foreach($account_cmodel->get_accounts(true) as $child_account_cmodel)
				$account_cmodels = array_merge($account_cmodels,$this->_get_subordinate_accounts($child_account_cmodel));

			return $account_cmodels;
		}

		public function add_account($account_cmodel) {

			if(!$this->get_parent_account_id())
				$account_cmodel->set_root_account_id($this->get_account_id());
			else
				$account_cmodel->set_root_account_id($this->get_root_account_id());

			$account_cmodel->set_parent_account_id($this->get_account_id());
			return $account_cmodel->save();		
		}

		public function add_user($user_cmodel) {

			if(HMODEL_ACCOUNT_USER::create()
					->filter_state_active()
					->set_user_id($user_cmodel->get_user_id())
					->set_account_id($this->get_account_id())
					->exists())
				throw new Exception("The user already exists");				
		
			$account_user_cmodel = new CMODEL_ACCOUNT_USER();
			$account_user_cmodel->set_user_id($user_cmodel->get_user_id());
			
			if(!$this->get_parent_account_id())
				$account_user_cmodel->set_root_account_id($this->get_account_id());
			else
				$account_user_cmodel->set_root_account_id($this->get_root_account_id());

			$account_user_cmodel->set_account_id($this->get_account_id());
			$account_user_cmodel->set_state(DBQ_ACCOUNT_USER::STATE_ACTIVE);
			return $account_user_cmodel->save();
		}

		public function user_default($user_cmodel) {
			
			DB::start_transaction();

			DBQ_ACCOUNT_USER::create()
					->where("user_id","=",$user_cmodel->get_user_id())
					->update(array("default"=>CONSTANT::FALSE));

			CMODEL_ACCOUNT_USER::create()
					->set_user_id($user_cmodel->get_user_id())
					->set_account_id($this->get_account_id())
					->set_default(CONSTANT::TRUE)
					->save();

			$has_success = DB::has_transaction_success();
			DB::complete_transaction();

			return $has_success;
		}

		public function save() {

			if(!$this->get_account_id() && !$this->get_parent_account_id()) {
				
				$exists = DBQ_ACCOUNT::create()
							->where("root_account_id","=",$this->get_account_id())
							->where("parent_account_id","IS",null)
							->exists();

				if($exists)
					return false;
			}
			
			$has_success = false;
			if(is_numeric(self::get_account_id())) {
				$has_success = $this->get_dbo("account")->update();
				
			} else {
				if(!$this->get_state())
					$this->set_state(DBQ_ACCOUNT::STATE_ACTIVE);

				if(!$this->get_guid())
					$this->set_guid(MISC_UTIL::get_guid());
					
				$has_success = $this->get_dbo("account")->insert();
			}
			
			return $has_success;
		}


		function populate_accounts($account_hmodel=null) {

			$account_hmodel = $account_hmodel ? $account_hmodel : HMODEL_ACCOUNT::create()->filter_state_active();

			$root_account_hmodel = clone $account_hmodel;

			$account_hmodel->order("priority");
			$account_hmodel->where("root_account_id","=",$this->get_account_id());
			$account_hmodel->where("parent_account_id","IS NOT",null);
			
			$account_cmodels = ARRAY_UTIL::index($account_hmodel->gets(),"get_account_id");

			self::build_account($this,$account_cmodels);
		}

		function build_account($parent_account_cmodel,$account_cmodels) {

			$tmp_account_cmodels = array();
			foreach($account_cmodels as $account_cmodel) {
				if($account_cmodel->get_parent_account_id()==$parent_account_cmodel->get_account_id())
					$tmp_account_cmodels[] = $account_cmodel;
			}	

			if($parent_account_cmodel) {
				$parent_account_cmodel->set_accounts($tmp_account_cmodels);

				foreach($parent_account_cmodel->get_accounts() as $account_cmodel)
					self::build_account($account_cmodel,$account_cmodels);
			}
		}		
	}