<?
	class ACTION_USER_PROFILE extends ACTION_JSON {

		function process() {

			$password 			= $this->post("password");
			$password_confirm 	= $this->post("password_confirm");

			$user_cmodel = USER_SESSION::get_instance()->get_user()
								->set_email($this->post("form","email"));

			try {

				$user_cmodel->validate();

				if($password && $password!=$password_confirm)
					throw new Exception("The passwords do not match");

				if($password)
					$user_cmodel->set_password($password,true);

				$this->success();

			} catch(Exception $e) {
				$this->error($e);
			}
		}
	}