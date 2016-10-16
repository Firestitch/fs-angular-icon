<?
	class ACTION_MANAGE_ACCOUNTACCOUNTORDER extends ACTION_JSON {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			$nodes		= is_array($this->post("nested")) ? $this->post("nested") : array();
			$account_id = $this->post("aid");

			$root_account_cmodel = HMODEL_ACCOUNT::get($account_id);

			if($root_account_cmodel) {

				DB::start_transaction();

				foreach($nodes as $index=>$node) {

					$item_id 			= (int)get_value($node,"item_id");
					$parent_account_id 	= (int)get_value($node,"parent_id");
					$parent_account_id 	= $parent_account_id ? $parent_account_id : $root_account_cmodel->get_account_id();

					if(!$item_id)
						continue;

					$account_cmodel = HMODEL_ACCOUNT::get($item_id);

						$account_cmodel
							->set_parent_account_id($parent_account_id)
							->set_priority($index)
							->save();
				}

				$has_success = DB::has_transaction_success();
				DB::complete_transaction();

				$this->success($has_success);
			}
		}
	}


