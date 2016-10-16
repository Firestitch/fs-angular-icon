<?
	class CMODEL_API_TOKEN extends CMODEL {
		protected $_user_cmodel = null;
		protected $__cmodel = null;
	
		public function __construct() {
			parent::__construct(DBO_API_TOKEN::create());
		}

		public function set_($value) { $this->__cmodel = $value; return $this; }

		public function get_($load=true) {
			if($load && !$this->__cmodel) $this->__cmodel = $this->get__id() ? HMODEL_USER::get($this->get__id()) : null;
			return $this->__cmodel;
		}

		public function set_user($value) { $this->_user_cmodel = $value; return $this; }

		public function get_user($load=true) {
			if($load && !$this->_user_cmodel) $this->_user_cmodel = $this->get_user_id() ? HMODEL_USER::get($this->get_user_id()) : null;
			return $this->_user_cmodel;
		}
		
		public function is_state_active()	{ return $this->get_state()==DBQ_API_TOKEN::STATE_ACTIVE; }
		public function is_state_deleted()	{ return $this->get_state()==DBQ_API_TOKEN::STATE_DELETED; }
		public function get_manage_url()	{ return "/manage/apitoken/atid:".$this->get_api_token_id()."/"; }
		public function get_state_name()	{ return get_value(DBQ_API_TOKEN::get_state_list(),$this->get_state()); }
		public function delete()			{ return $this->set_state(DBQ_API_TOKEN::STATE_DELETED)->save(); }		
		public function deactivate()		{ return $this->set_state(DBQ_API_TOKEN::STATE_INACTIVE)->save(); }
		public function get_expiry_iso8601(){ return CMODEL_TIME::create($this->get_expiry_time())->iso8601(); }
		public function get_expiry_time()	{ return CMODEL_TIME::create($this->get_create_date())->add_hour(24)->time(); }

		public function reset_expiry_date() {
			return $this
					->set_expiry_date(DB::get_date_time())
					->save();
		}

		public static function create_instance($user_cmodel) {

			$api_token_cmodel = CMODEL_API_TOKEN::create()
									->set_expiry_date(CMODEL_TIME::create(time())->add_week()->db())
									->set_user_id($user_cmodel->get_user_id())
									->set_ip(SERVER_UTIL::get_remote_ip())
									->set_mask_ip(self::mask_ip(SERVER_UTIL::get_remote_ip()))
									->set_user_agent(SERVER_UTIL::get_user_agent());

			return $api_token_cmodel->save();
		}
		
		public function session($options = []) {
			$defaults = [
						    "user"=>$this->get_user()->arry(),
						    "token"=>$this->arry()
                        ];

            return array_merge_recursive($defaults, $options);
		}

		public function save() {
			
			$has_success = false;
			if(is_numeric(self::get_api_token_id())) {
				$has_success = $this->dbo("api_token")->update();
				
			} else {
				if(!$this->get_state())
					$this->set_state(DBQ_API_TOKEN::STATE_ACTIVE);
					
				if(!$this->get_create_date())
					$this->set_create_date(DB::get_date_time());

				if(!$this->get_key())
					$this->set_key(MISC_UTIL::guid());
					
				$has_success = $this->dbo("api_token")->insert();
			}

			if(!$has_success)
				throw new Exception("Error saving ".get_class());				
			
			return $this;
		}

		public function arry($arry=array()) {

			$arry = CMODEL_OBJECTER::create($this,
											array(	"get_key",
													"expires"=>"get_expiry_iso8601"
													))->arry();

			return $arry;
		}		
	}