<?
	class ACTION_USER_FORGOT extends ACTION_JSON {

		function __construct() {
			parent::__construct()->disable_authorization();
		}

		function process() {

			$email = $this->request("email");

			try {
				CMODEL_USER_PASSWORD_RESET::create()->request_email($email);
				$this->success();
			} catch(Exception $e) {
				$this->error($e);
			}

		}
	}