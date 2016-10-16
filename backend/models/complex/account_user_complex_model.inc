<?
	class CMODEL_ACCOUNT_USER extends MODEL_COMPLEX {
		protected $_user_cmodel = null;
	
		public function __construct() {
			$this->register_dbo(new DBO_ACCOUNT_USER);
		}

		public function set_user($value) { $this->_user_cmodel = $value; }

		public function get_user($load=true) {
			if($load && !$this->_user_cmodel) $this->_user_cmodel = $this->get_user_id() ? HMODEL_USER::get($this->get_user_id()) : null;
			return $this->_user_cmodel;
		}
		
		public function is_state_active()	{ return $this->get_state()==DBQ_ACCOUNT_USER::STATE_ACTIVE; }
		public function is_state_deleted()	{ return $this->get_state()==DBQ_ACCOUNT_USER::STATE_DELETED; }
		public function get_state_name()	{ return get_value(DBQ_ACCOUNT_USER::get_state_list(),$this->get_state()); }
		public function get_manage_url()	{ return "/manage/accountuser/auid:".$this->get_account_user_id()."/"; }

		public function delete() {
			$this->set_state(DBQ_ACCOUNT_USER::STATE_DELETED);
			return $this->save();
		}
		
		public function save() {

			$this->set_account_user_id(DBQ_ACCOUNT_USER::create()
											->where("user_id","=",$this->get_user_id())
											->where("account_id","=",$this->get_account_id())
											->one("account_user_id"));
			
			$has_success = false;
			if(is_numeric(self::get_account_user_id())) {
				$has_success = $this->get_dbo("account_user")->update();
				
			} else {
				if(!$this->get_state())
					$this->set_state(DBQ_ACCOUNT_USER::STATE_ACTIVE);
					
				$has_success = $this->get_dbo("account_user")->insert();
			}
			
			return $has_success;
		}
	};