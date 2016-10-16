<?

	class ACTION_MANAGE_DEIMPERSONATE extends ACTION {

		function process() {
			
			
			$user_session = USER_SESSION::get_instance();
			
			$user_id = $user_session->get_impersonate_user_id();
			
			$view = null;
			
			if($user_id) {
			
				$user_cmodel = HMODEL_USER::get($user_id);

				if($user_cmodel) {

					$login_cmodel = new CMODEL_LOGIN();
					$has_success = $login_cmodel->process($user_cmodel);

					if($has_success) {
						APPLICATION::add_notify_message("Sucessfully de-impersonated the user");

						$user_session->set_impersonate_user_id(null);

						//if($uri) {
						//	$uri = new URI($uri);
						//	$view = APPLICATION::get_view_instance($uri->get_controller(),$uri->get_task());
						//}
					}
				}
			}
			
			if(!$view)
				$view = APPLICATION::get_view_instance("manage","users");
			
			$this->set_view($view);
		}
	}

