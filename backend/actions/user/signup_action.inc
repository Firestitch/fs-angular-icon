<?
	class ACTION_USER_SIGNUP extends ACTION_JSON {

		function __construct() {
			parent::__construct()->disable_authorization();
		}

		function process() {

			$email 				= $this->post("email");
			$password 			= $this->post("password");
			$password_confirm 	= $this->post("password_confirm");

			$user_cmodel = CMODEL_USER::create()->set_email($email);

			try {

				$user_cmodel->validate();

				if(!$password)
					throw new Exception("The password is invalid");
				elseif($password!=$password_confirm)
					throw new Exception("The passwords do not match");

				$user_cmodel
					->set_password($password,true)
					->save()
					->apply_frontend_role();

				CMODEL_LOGIN::create()->login($user_cmodel);

				$this->success()->redirect("/user/home");

			} catch(Exception $e) {
				$this->error($e);
			}
		}
	}