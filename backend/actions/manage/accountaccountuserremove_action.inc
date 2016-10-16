<?
	class ACTION_MANAGE_ACCOUNTACCOUNTUSERREMOVE extends ACTION_JSON {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			if($account_user_id=$this->post("auid")) {

				if($account_user_cmodel=HMODEL_ACCOUNT_USER::get($account_user_id))
					$has_success = $account_user_cmodel->delete();

				$this->success($has_success);
			}

			if(!$this->has_success())
				$this->error("There was a problem trying to remove the account user");
		}
	}