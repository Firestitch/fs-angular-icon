<?
	class HMODEL_IMPERSONATE extends HMODEL {
	
		protected $_select_fields = array("impersonates.*");
		
		public function __construct() {
			return $this->register_dbq(DBQ_IMPERSONATE::create());
		}
		
		public function gets() {			
			$impersonates = $this->get_dbq()->select($this->_select_fields);

			$impersonate_cmodels = array();			
			foreach($impersonates as $impersonate) {
				$impersonate_cmodel = CMODEL_IMPERSONATE::create()->populate($impersonate,true,false);
				$this->apply_properties($impersonate_cmodel,$impersonate);
				$impersonate_cmodels[] = $impersonate_cmodel;
			}
			
			if(!$impersonate_cmodels)
				return array();
			
			$this->map_one($impersonate_cmodels,$this->handler("impersonated_user_handler"),"impersonated_user","impersonated_user","user");

			return $impersonate_cmodels;
		}
		
		public function where_state_active()			{ return $this->set_state(CMODEL_IMPERSONATE::STATE_ACTIVE); }
		public function set_impersonate_ids($values)	{ return $this->where("impersonates.impersonate_id","IN",$values); }
		public function set_impersonate_id($value)	{ return $this->where("impersonates.impersonate_id","=",$value); }
		public function set_state($value)		{ return $this->where("impersonates.state","=",$value); }
		public function set_states($values)			{ return $this->where("impersonates.state","IN",$values); }
		public function set_guid($value)		{ return $this->where("impersonates.guid","=",$value); }
		public function set_guids($values)			{ return $this->where("impersonates.guid","IN",$values); }
		public function set_user_id($value)		{ return $this->where("impersonates.user_id","=",$value); }
		public function set_user_ids($values)			{ return $this->where("impersonates.user_id","IN",$values); }
		public function set_impersonated_user_id($value)		{ return $this->where("impersonates.impersonated_user_id","=",$value); }
		public function set_impersonated_user_ids($values)			{ return $this->where("impersonates.impersonated_user_id","IN",$values); }
		
		public static function create($defaults=true) {
			return $defaults ? parent::create()->where_state_active() : parent::create();
		}		
	
		public function load_impersonated_users($impersonated_user_hmodel=null) {
			return $this->handler("impersonated_user_handler",$impersonated_user_hmodel ? $impersonated_user_hmodel : HMODEL_USER::create());
		}
	}