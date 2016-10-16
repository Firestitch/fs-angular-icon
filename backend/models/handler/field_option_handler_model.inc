<?
	class HMODEL_FIELD_OPTION extends MODEL_HANDLER {
	
		protected $_select_fields = array("field_options.*");
		
		function get_dbq() {
			$field_option_dbq = new DBQ_FIELD_OPTION();
			$this->apply_constraints($field_option_dbq);
			return $field_option_dbq;
		}
		
		function gets() {
			$field_option_dbq = $this->get_dbq();
			$field_options = $field_option_dbq->select($this->_select_fields);
			$field_option_cmodels = array();
			
			foreach($field_options as $field_option) {
				$field_option_cmodel = new CMODEL_FIELD_OPTION();
				$field_option_cmodel->populate($field_option,true,false);
				$this->apply_properties($field_option_cmodel,$field_option);
				$field_option_cmodels[] = $field_option_cmodel;
			}
			
			if(!$field_option_cmodels)
				return array();
			
			return $field_option_cmodels;
		}
		
		public function filter_state_active()			{ return $this->set_state(DBQ_FIELD_OPTION::STATE_ACTIVE); }
		public function get_count($field=null) 			{ return $this->get_dbq()->count($field); }
		public function exists($field=null)				{ return $this->get_dbq()->exists($field); }
		public function set_field_option_ids($values)	{ return $this->add_filter("field_options.field_option_id","IN",$values); }
		public function set_field_option_id($value)		{ return $this->add_filter("field_options.field_option_id","=",$value); }
		public function set_field_id($value)			{ return $this->add_filter("field_options.field_id","=",$value); }
		public function set_field_ids($values)			{ return $this->add_filter("field_options.field_id","IN",$values); }
		public function set_state($value)				{ return $this->add_filter("field_options.state","=",$value); }
		public function set_states($values)				{ return $this->add_filter("field_options.state","IN",$values); }
		public function set_guid($value)				{ return $this->add_filter("field_options.guid","=",$value); }
		public function set_guids($values)				{ return $this->add_filter("field_options.guid","IN",$values); }
	
		public static function create() {
			return parent::create()->filter_state_active();
		}
	}
	