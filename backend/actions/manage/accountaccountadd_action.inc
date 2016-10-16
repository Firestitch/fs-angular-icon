<?
	class ACTION_MANAGE_ACCOUNTACCOUNTADD extends ACTION_JSON {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			$parent_account_id	= $this->post("paid");
			$name				= $this->post("name");

			$parent_account_cmodel = HMODEL_ACCOUNT::get($parent_account_id);

			if($parent_account_cmodel)  {

				DB::start_transaction();

				$names = explode(",",$name);

				foreach($names as $name) {
					$name = trim($name);

					if(!$name) continue;

					try {

						$parent_account_cmodel->add_account(CMODEL_ACCOUNT::create()
																->set_name($name));
					} catch(Exception $e) {
						DB::fail_transaction();
						$this->error($e);
					}
				}

				$has_success = DB::has_transaction_success();
				DB::complete_transaction();

				$this->success($has_success);
			}

			if(!$this->has_success())
				$this->error("There was a problem trying to add the account");
		}
	}


