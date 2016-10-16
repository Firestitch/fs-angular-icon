<?

	class ACTION_MANAGE_IMPERSONATE extends ACTION {

		function __construct() {
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			$user_cmodel = HMODEL_USER::get($this->get(0));

			if(!$user_cmodel)
				throw new Exception("Invalid user");

			$impersonate_cmodel = CMODEL_IMPERSONATE::create()
									->set_user_id(USER_SESSION::get_instance()->get_user_id())
									->set_impersonated_user_id($user_cmodel->get_user_id())
									->save();

			$app_url = CMODEL_SETTING::get_app_url();

			if(!$app_url) {
				APPLICATION::add_error("The App URL needs to be set to impersonate users");
				$view = APPLICATION::get_view_instance("manage","settings");
				$this->set_view($view);
			}

			HTTP_UTIL::redirect($app_url."impersonate/".$impersonate_cmodel->get_guid());
		}
	}

