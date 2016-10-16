<?
	class ACTION_MANAGE_ACCOUNTUSERADD extends ACTION_JSON {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			$account_id	= $this->post("aid");
			$user_id	= $this->post("uid");

			$account_cmodel = HMODEL_ACCOUNT::get($account_id);

			$user_cmodel = HMODEL_USER::get($user_id);

			if(!$user_cmodel)
				$this->error("Invalid user");

			elseif(!$account_cmodel)
				$this->error("Invalid account");

			else {

				try {

					$has_success = $account_cmodel->add_user($user_cmodel);
					$this->success($has_success);

				} catch(Exception $e) {
					$this->error($e);
				}
			}
		}
	}


