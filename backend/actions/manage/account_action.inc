<?
	class ACTION_MANAGE_ACCOUNT extends ACTION_JSON {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			$account_id		= $this->post("aid");
			$form			= $this->post("form");
			$account_cmodel = null;

			if($account_id)
				$account_cmodel = HMODEL_ACCOUNT::get($account_id);

			$account_cmodel = $account_cmodel ? $account_cmodel : new CMODEL_ACCOUNT();
			$account_cmodel->populate($form);


			if($this->is_form_valid($account_cmodel)) {
				$has_success = $account_cmodel->save();

				if($has_success) {

					$this->data("aid",$account_cmodel->get_account_id());

					if(!$account_id) {
						APPLICATION::add_persistent_notify("Successfully added the account");
						$this->redirect($account_cmodel->get_manage_url());
					}
				}

				$this->success($has_success);
			}

			if(!$this->has_success() && !$this->has_error())
				$this->error("There was a problem trying to save the account");
		}

		function is_form_valid($account_cmodel) {
			return !$this->has_error();
		}
	}


