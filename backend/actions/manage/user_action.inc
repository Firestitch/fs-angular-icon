<?
	class ACTION_MANAGE_USER extends ACTION_JSON {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			$password	= $this->post("password");
			$user_id	= $this->post("uid");

			$user_cmodel = HMODEL_USER::get($user_id);

			$user_cmodel = $user_cmodel ? $user_cmodel : CMODEL_USER::create();

			$user_cmodel
				->populate($this->post("form"))
				->set_permissions((array)$this->post("form","permissions"));

			if($password)
				$user_cmodel->set_password($password,true);

			$user_cmodel->save();

			if(!$user_id) {
				APPLICATION::add_persistent_notify("Successfully added the user");
				$this->data("url",$user_cmodel->get_manage_url());
			}

			$this->success();
		}
	}


