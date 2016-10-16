<?
	class CMODEL_OBJECT_ACCOUNT extends CMODEL_OBJECT {
	
		public function __construct($dbo=null) {
			parent::__construct(new DBO_OBJECT_ACCOUNT);

			if($dbo)
				$this->register_dbo($dbo);
		}
		
		public function save() {
			
			DB::start_transaction();

			if(parent::save()) {

				if(is_numeric(self::get_object_account_id())) {
					$has_success = $this->get_dbo("object_account")->update();
					
				} else {
					$has_success = $this->get_dbo("object_account")
											->set_object_id(parent::get_object_id())
											->insert();
				}
			}
			
			$has_success = DB::has_transaction_success();
			DB::complete_transaction();
			
			return $has_success;
		}
	}