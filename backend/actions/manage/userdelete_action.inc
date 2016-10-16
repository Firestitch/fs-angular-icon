<?

	class ACTION_MANAGE_USERDELETE extends ACTION_JSON {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			$user_id 	= $this->request("uid");

			$user_cmodel = HMODEL_USER::get($user_id);

			if($user_cmodel) {
				$has_success = $user_cmodel->delete();

				$this->success($has_success);
			}

		}
	}