<?
	class ACTION_MANAGE_ACCOUNTREMOVE extends ACTION_JSON {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			if($account_id=$this->post("aid")) {

				if($account_cmodel=HMODEL_ACCOUNT::get($account_id))
					$has_success = $account_cmodel->delete();

				$this->success($has_success);
			}

			if(!$this->has_success())
				$this->error("There was a problem trying to remove the account");
		}
	}