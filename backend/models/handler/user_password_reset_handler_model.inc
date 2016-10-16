<?
	class HMODEL_USER_PASSWORD_RESET extends HMODEL {
	
		protected $_select_fields = array("user_password_resets.*");
		
		public function __construct() {
			return $this->register_dbq(DBQ_USER_PASSWORD_RESET::create());
		}
		
		public function gets() {			
			$user_password_resets = $this->get_dbq()->select($this->_select_fields);

			$user_password_reset_cmodels = array();			
			foreach($user_password_resets as $user_password_reset) {
				$user_password_reset_cmodel = CMODEL_USER_PASSWORD_RESET::create()->populate($user_password_reset,true,false);
				$this->apply_properties($user_password_reset_cmodel,$user_password_reset);
				$user_password_reset_cmodels[] = $user_password_reset_cmodel;
			}
			
			if(!$user_password_reset_cmodels)
				return array();
			
			$this->map_one($user_password_reset_cmodels,$this->handler("user_handler"),"user","user","user");

			return $user_password_reset_cmodels;
		}
		
		public function where_state_active()			{ return $this->set_state(CMODEL_USER_PASSWORD_RESET::STATE_ACTIVE); }
		public function set_user_password_reset_ids($values)	{ return $this->where("user_password_resets.user_password_reset_id","IN",$values); }
		public function set_user_password_reset_id($value)	{ return $this->where("user_password_resets.user_password_reset_id","=",$value); }
		public function set_user_id($value)		{ return $this->where("user_password_resets.user_id","=",$value); }
		public function set_user_ids($values)			{ return $this->where("user_password_resets.user_id","IN",$values); }
		public function set_guid($value)		{ return $this->where("user_password_resets.guid","=",$value); }
		public function set_guids($values)			{ return $this->where("user_password_resets.guid","IN",$values); }
		public function set_state($value)		{ return $this->where("user_password_resets.state","=",$value); }
		public function set_states($values)			{ return $this->where("user_password_resets.state","IN",$values); }
		
		public static function create($defaults=true) {
			return $defaults ? parent::create()->where_state_active() : parent::create();
		}		
	
		public function load_users($user_hmodel=null) {
			return $this->handler("user_handler",$user_hmodel ? $user_hmodel : HMODEL_USER::create());
		}
	}