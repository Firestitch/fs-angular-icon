<?
	class HMODEL_FIELD_VALUE extends MODEL_HANDLER {
	
		protected $_select_fields = array("field_values.*");
		
		protected $_field_value_option_hmodel = null;

		protected $_field_hmodel = null;

		function get_dbq() {
			return $this->apply_constraints(DBQ_FIELD_VALUE::create());
		}
		
		function gets() {			
			$field_values = $this->get_dbq()->select($this->_select_fields);

			$field_value_cmodels = array();			
			foreach($field_values as $field_value) {
				$field_value_cmodel = new CMODEL_FIELD_VALUE();
				$field_value_cmodel->populate($field_value,true,false);
				$this->apply_properties($field_value_cmodel,$field_value);
				$field_value_cmodels[] = $field_value_cmodel;
			}
			
			if(!$field_value_cmodels)
				return array();
			
			
			if($this->_field_value_option_hmodel) {
				$field_value_ids = array_unique(MISC_UTIL::get_list_from_object_function($field_value_cmodels, "get_field_value_id"));
				$field_value_option_hmodel = $this->_field_value_option_hmodel;
				$field_value_option_hmodel->add_filter("field_value_id","IN",$field_value_ids);
				$field_value_option_cmodels = $field_value_option_hmodel->gets();

				foreach($field_value_cmodels as $field_value_cmodel) {
					$field_value_options = array();
					foreach($field_value_option_cmodels as $index=>$field_value_option_cmodel) {
						if($field_value_cmodel->get_field_value_id()==$field_value_option_cmodel->get_field_value_id()) {
							$field_value_options[] = $field_value_option_cmodel;
						}
					}
					$field_value_cmodel->set_field_value_options($field_value_options);
				}
			}

			
			if($this->_field_hmodel) {
				$field_ids = array_unique(MISC_UTIL::get_list_from_object_function($field_value_cmodels, "get_field_id"));
				$field_hmodel = $this->_field_hmodel;
				$field_hmodel->add_filter("field_id","IN",$field_ids);
				$field_cmodels = $field_hmodel->gets();

				foreach($field_value_cmodels as $field_value_cmodel)
					foreach($field_cmodels as $field_cmodel)
						if($field_value_cmodel->get_field_id()==$field_cmodel->get_field_id())
							$field_value_cmodel->set_field($field_cmodel);
			}

			return $field_value_cmodels;
		}
		
				function load_field_value_options($field_value_option_hmodel=null) {
			$this->_field_value_option_hmodel = $field_value_option_hmodel ? $field_value_option_hmodel : HMODEL_FIELD_VALUE_OPTION::get_default_handler();
			return $this;
		}

		function load_fields($field_hmodel=null) {
			$this->_field_hmodel = $field_hmodel ? $field_hmodel : HMODEL_FIELD::get_default_handler();
			return $this;
		}

		function get_count($field=null) 		{ return $this->get_dbq()->count($field); }
		function exists($field=null)			{ return $this->get_dbq()->exists($field); }
		function set_field_value_ids($values)	{ return $this->where("field_values.field_value_id","IN",$values); }
		function set_field_value_id($value)	{ return $this->where("field_values.field_value_id","=",$value); }
		function set_field_id($value)	{ return $this->where("field_values.field_id","=",$value); }
		function set_field_ids($values)	{ return $this->where("field_values.field_id","IN",$values); }
	
		function get_default_handler() {
			return HMODEL_FIELD_VALUE::create();		}
	}
	