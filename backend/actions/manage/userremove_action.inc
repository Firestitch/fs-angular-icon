<?
	class ACTION_MANAGE_USERREMOVE extends ACTION {

		function __construct() {
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			$has_success = false;

			$response_cmodel = new BCMODEL_RESPONSE();

			if(is_numeric($user_id=$this->get_post_parm("uid"))) {
				$user_hmodel = new HMODEL_USER();
				$user_hmodel->set_user_id($user_id);

				if($user_cmodel=get_value($user_hmodel->get_users(),0))
					$has_success = $user_cmodel->delete();

				$response_cmodel->success($has_success);
			}

			if(!$has_success)
				$response_cmodel->add_error("There was a problem trying to remove the user");

			$response_cmodel->render();
		}
	}