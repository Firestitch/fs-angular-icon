<?
	class ACTION_MANAGE_ACCOUNTORDER extends ACTION {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			$account_ids	= is_array($this->post("aids")) ? $this->post("aids") : array();

			$response_cmodel = new BASE_CMODEL_RESPONSE();

			DB::start_transaction();

			foreach($account_ids as $index=>$account_id) {
				$account_dbq= new DBQ_ACCOUNT();
				$account_dbq->add_where("account_id","=",$account_id);
				$account_dbq->update(array("priority"=>$index));
			}

			$has_success = DB::has_transaction_success();
			DB::complete_transaction();

			$response_cmodel->success($has_success);
			$response_cmodel->render();
		}
	}


