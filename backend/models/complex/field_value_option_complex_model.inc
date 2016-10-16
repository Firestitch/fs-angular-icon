<?
	class CMODEL_FIELD_VALUE_OPTION extends MODEL_COMPLEX {
	
		public function __construct() {
			$this->register_dbo(new DBO_FIELD_VALUE_OPTION);
		}
		
		public function save() {
			
			DB::start_transaction();
			
			$has_success = false;
			if(is_numeric(self::get_field_value_option_id())) {
				$has_success = $this->get_dbo("field_value_option")->update();
				
			} else {
				$has_success = $this->get_dbo("field_value_option")->insert();
			}
			
			$has_success = DB::has_transaction_success();
			DB::complete_transaction();
			
			return $has_success;
		}
	}