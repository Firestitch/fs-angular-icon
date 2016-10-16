<?
	class HMODEL_API_TOKEN extends HMODEL {

		protected $_user_hmodel = null;

		public function get_dbq() {
			return $this->apply_constraints(DBQ_API_TOKEN::create());
		}
		
		public function gets() {			
			$api_tokens = $this->get_dbq()->select($this->_select_fields);

			$api_token_cmodels = array();			
			foreach($api_tokens as $api_token) {
				$api_token_cmodel = CMODEL_API_TOKEN::create()->populate($api_token,true,false);
				$this->apply_properties($api_token_cmodel,$api_token);
				$api_token_cmodels[] = $api_token_cmodel;
			}
			
			if(!$api_token_cmodels)
				return array();

			return $api_token_cmodels;
		}
		
		public function where_state_active()			{ return $this->set_state(DBQ_API_TOKEN::STATE_ACTIVE); }
		public function set_api_token_ids($values)	{ return $this->where("api_tokens.api_token_id","IN",$values); }
		public function set_api_token_id($value)	{ return $this->where("api_tokens.api_token_id","=",$value); }
		public function set_user_id($value)		{ return $this->where("api_tokens.user_id","=",$value); }
		public function set_user_ids($values)			{ return $this->where("api_tokens.user_id","IN",$values); }
		public function set_state($value)		{ return $this->where("api_tokens.state","=",$value); }
		public function set_states($values)			{ return $this->where("api_tokens.state","IN",$values); }
	
		public static function create($defaults=true) {
			return $defaults ? parent::create()->where_state_active() : parent::create();
		}
	}