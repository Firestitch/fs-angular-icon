<?
	class ACTION_MANAGE_ACCOUNTACCOUNTREMOVE extends ACTION_JSON {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			if($account_id=$this->post("aid")) {

				if($account_cmodel=HMODEL_ACCOUNT::get($account_id)) {

					try {
						$this->success($account_cmodel->delete());
					} catch(Exception $e) {
						$this->error($e);
					}
				}
			}

			if(!$this->has_success())
				$this->error("There was a problem trying to remove the account");
		}
	}