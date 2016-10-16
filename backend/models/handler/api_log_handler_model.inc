<?
	class HMODEL_API_LOG extends HMODEL {
	
		protected $_select_fields = array("api_logs.*");
		
		public function __construct() {
			return $this->register_dbq(DBQ_API_LOG::create());
		}
		
		public function gets() {			
			$api_logs = $this->get_dbq()->select($this->_select_fields);

			$api_log_cmodels = array();			
			foreach($api_logs as $api_log) {
				$api_log_cmodel = CMODEL_API_LOG::create()->populate($api_log,true,false);
				$this->apply_properties($api_log_cmodel,$api_log);
				$api_log_cmodels[] = $api_log_cmodel;
			}
			
			if(!$api_log_cmodels)
				return array();
			
			return $api_log_cmodels;
		}
		
		public function set_api_log_ids($values)	{ return $this->where("api_logs.api_log_id","IN",$values); }
		public function set_api_log_id($value)	{ return $this->where("api_logs.api_log_id","=",$value); }
		public function set_state($value)		{ return $this->where("api_logs.state","=",$value); }
		public function set_states($values)			{ return $this->where("api_logs.state","IN",$values); }
		
		public static function create($defaults=true) {
			return $defaults ? parent::create() : parent::create();
		}		
	}
	