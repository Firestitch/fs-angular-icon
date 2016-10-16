<?
	class ACTION_MANAGE_ACCOUNTACCOUNT extends ACTION_JSON {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			$account_id			= $this->post("aid");
			$form				= $this->post("form");
			$parent_account_id	= $this->post("paid");

			$account_cmodel = null;

			if($account_id)
				$account_cmodel = HMODEL_ACCOUNT::get($account_id);

			$account_cmodel = $account_cmodel ? $account_cmodel : new CMODEL_ACCOUNT();
			$account_cmodel->populate($form);

			if($parent_account_id)
				$account_cmodel->set_parent_account_id($parent_account_id);

			if($this->is_form_valid($account_cmodel)) {

				try {
					$this->success($account_cmodel->save());
				} catch(Exception $e) {
					$this->error($e);
				}
			}
		}

		function is_form_valid($account_cmodel) {

			if(!$account_cmodel->get_name())
				$this->error("Please supply an account name");

			return !$this->has_error();
		}
	}


