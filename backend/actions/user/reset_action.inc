<?

	class ACTION_USER_RESET extends ACTION_JSON {

		function __construct() {
			parent::__construct()->disable_authorization();
		}

		function process() {

			$password 			= $this->post("password");
			$password_confirm 	= $this->post("password_confirm");

			$user_password_reset_cmodel = HMODEL_USER_PASSWORD_RESET::create()
												->add_filter("guid","=",$this->post("guid"))
												->get();

			if($user_password_reset_cmodel) {

				try {

					$has_success = $user_password_reset_cmodel->reset($password,$password_confirm);

					$this->success(true);

					$url = "/user/login/email:".$user_password_reset_cmodel->get_user()->get_email();

					$this->data("url",$url);

					APPLICATION::add_persistent_notify("Your password has been successfully changed. Please use you new password to login with.");

				} catch(Exception $e) {
					$this->error($e);
				}
			} else
				$this->error("There was a problem trying to load the reset request");

		}
	}