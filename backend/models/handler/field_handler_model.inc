<?
	class HMODEL_FIELD extends MODEL_HANDLER {
	
		protected $_select_fields = array("fields.*");
		
		protected $_field_option_hmodel = null;

		function get_dbq() {
			$field_dbq = new DBQ_FIELD();
			$this->apply_constraints($field_dbq);
			return $field_dbq;
		}
		
		function gets() {
			$field_dbq = $this->get_dbq();
			$fields = $field_dbq->select($this->_select_fields);
			$field_cmodels = array();
			
			foreach($fields as $field) {
				$field_cmodel = new CMODEL_FIELD();
				$field_cmodel->populate($field,true,false);
				$this->apply_properties($field_cmodel,$field);
				$field_cmodels[] = $field_cmodel;
			}
			
			if(!$field_cmodels)
				return array();
			
			
			if($this->_field_option_hmodel) {
				$field_ids = array_unique(MISC_UTIL::get_list_from_object_function($field_cmodels, "get_field_id"));
				$field_option_hmodel = $this->_field_option_hmodel;
				$field_option_hmodel->add_filter("field_id","IN",$field_ids);
				$field_option_cmodels = $field_option_hmodel->gets();

				foreach($field_cmodels as $field_cmodel) {
					$field_options = array();
					foreach($field_option_cmodels as $index=>$field_option_cmodel) {
						if($field_cmodel->get_field_id()==$field_option_cmodel->get_field_id()) {
							$field_options[] = $field_option_cmodel;
						}
					}
					$field_cmodel->set_field_options($field_options);
				}
			}

			return $field_cmodels;
		}
		
		function filter_state_active()			{ return $this->set_state(DBQ_FIELD::STATE_ACTIVE); }
		function load_field_options($field_option_hmodel=null) {
			$this->_field_option_hmodel = $field_option_hmodel ? $field_option_hmodel : new HMODEL_FIELD_OPTION();
			return $this;
		}

		function get_count($field=null) 		{ return $this->get_dbq()->count($field); }
		function exists($field=null)			{ return $this->get_dbq()->exists($field); }
		function set_field_ids($values)	{ return $this->add_filter("fields.field_id","IN",$values); }
		function set_field_id($value)	{ return $this->add_filter("fields.field_id","=",$value); }
		function set_state($value)	{ return $this->add_filter("fields.state","=",$value); }
		function set_states($values)	{ return $this->add_filter("fields.state","IN",$values); }
	
		function get_default_handler() {
			HMODEL_FIELD::create()->filter_state_active();
		}
	}
	