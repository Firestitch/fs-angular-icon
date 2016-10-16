<?
	class CMODEL_FIELD_VALUE extends MODEL_COMPLEX {
		
		protected $_field_value_option_cmodels = array();
		protected $_field_cmodel = null;
	
		public function __construct() {
			$this->register_dbo(new DBO_FIELD_VALUE);
		}

		public function set_field($value) { $this->_field_cmodel = $value; return $this; }

		public function get_field($load=true) {
			if($load && !$this->_field_cmodel) $this->_field_cmodel = $this->get_field_id() ? HMODEL_FIELD::get($this->get_field_id()) : null;
			return $this->_field_cmodel;
		}

		public function set_field_value_options($value) { $this->_field_value_option_cmodels = $value; return $this; }

		public function get_field_value_options($load=false,$field_value_option_hmodel=null) {
			if($load && !$this->_field_value_option_cmodels) {
				if(!$field_value_option_hmodel)
					$field_value_option_hmodel = HMODEL_FIELD_VALUE_OPTION::get_default_handler();
				$field_value_option_hmodel->where("field_value_id","=",$this->get_field_value_id());
				$this->_field_value_option_cmodels = $field_value_option_hmodel->gets();
			}
			return $this->_field_value_option_cmodels;
		}
		
		public function save_value($value) {

			if($this->get_field()->is_interface_rating()) {
				
				$field_option_cmodel = HMODEL_FIELD_OPTION::get($value);

				if($field_option_cmodel)
					$this->set_integer($field_option_cmodel->get_label());

			} elseif($this->get_field()->is_interface_sentiment() || $this->get_field()->is_interface_yes_no()) {
				$this->set_integer($value);

			} elseif(	$this->get_field()->is_interface_single_line_text() || $this->get_field()->is_interface_multi_line_text() || 
						$this->get_field()->is_interface_date_select())
				$this->set_string($value);

			self::save();
			
			return $this;
		}

		public function get_value() {
			
			$value = null;
			
			if(	$this->get_field()->is_interface_multi_select_checkboxes() || $this->get_field()->is_interface_single_select_dropdown() || 
				$this->get_field()->is_interface_single_select_radio() || $this->get_field()->is_interface_optin() || $this->get_field()->is_interface_rating()) {

				$value = array();

				$field_option_cmodels = $this->get_field_value_options(true);

				foreach($field_option_cmodels as $field_option_cmodel)
					$value[] = $field_option_cmodel->get_field_option_id();
			}

			if($this->get_field()->is_interface_text())
				$value = $this->get_string();

			if($this->get_field()->is_interface_sentiment() || $this->get_field()->is_interface_yes_no())
				$value = $this->get_integer();

			if($this->get_field()->is_interface_rating())
				$value = get_value($value,0);

			return $value;			
		}

		public function save() {
			
			$has_success = false;
			if(is_numeric(self::get_field_value_id())) {
				$has_success = $this->get_dbo("field_value")->update();
				
			} else {
				$has_success = $this->get_dbo("field_value")->insert();
			}
			
			return $has_success;
		}
	}