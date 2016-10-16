<?
	class HMODEL_FIELD_VALUE_OPTION extends MODEL_HANDLER {
	
		protected $_select_fields = array("field_value_options.*");
		
		function get_dbq() {
			return $this->apply_constraints(DBQ_FIELD_VALUE_OPTION::create());
		}
		
		function gets() {			
			$field_value_options = $this->get_dbq()->select($this->_select_fields);

			$field_value_option_cmodels = array();			
			foreach($field_value_options as $field_value_option) {
				$field_value_option_cmodel = new CMODEL_FIELD_VALUE_OPTION();
				$field_value_option_cmodel->populate($field_value_option,true,false);
				$this->apply_properties($field_value_option_cmodel,$field_value_option);
				$field_value_option_cmodels[] = $field_value_option_cmodel;
			}
			
			if(!$field_value_option_cmodels)
				return array();
			
			return $field_value_option_cmodels;
		}
		
				function get_count($field=null) 		{ return $this->get_dbq()->count($field); }
		function exists($field=null)			{ return $this->get_dbq()->exists($field); }
		function set_field_value_option_ids($values)	{ return $this->where("field_value_options.field_value_option_id","IN",$values); }
		function set_field_value_option_id($value)	{ return $this->where("field_value_options.field_value_option_id","=",$value); }
		function set_field_id($value)	{ return $this->where("field_value_options.field_id","=",$value); }
		function set_field_ids($values)	{ return $this->where("field_value_options.field_id","IN",$values); }
		function set_field_option_id($value)	{ return $this->where("field_value_options.field_option_id","=",$value); }
		function set_field_option_ids($values)	{ return $this->where("field_value_options.field_option_id","IN",$values); }
		function set_field_value_id($value)	{ return $this->where("field_value_options.field_value_id","=",$value); }
		function set_field_value_ids($values)	{ return $this->where("field_value_options.field_value_id","IN",$values); }
	
		function get_default_handler() {
			return HMODEL_FIELD_VALUE_OPTION::create();		}
	}
	