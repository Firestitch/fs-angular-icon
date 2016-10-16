<?

	class ACTION_USER_RESETCODE extends ACTION_JSON {

		function __construct() {
			parent::__construct()->disable_authorization();
		}

		function process() {

			$user_password_reset_cmodel = HMODEL_USER_PASSWORD_RESET::create()
												->where("guid","=",$this->post("guid"))
												->get();

			if($user_password_reset_cmodel) {

				try {

					$has_success = $user_password_reset_cmodel->validate();

					$this->success(true);

					$url = "/user/reset/".$user_password_reset_cmodel->get_guid();

					$this->data("url",$url);

				} catch(Exception $e) {
					$this->error($e);
				}

			} else
				$this->error("There was a problem trying to load the reset request");
		}
	}