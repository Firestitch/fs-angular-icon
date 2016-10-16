<?
	class ACTION_USER_LOGIN extends ACTION_JSON {

		function __construct() {
			parent::__construct()->disable_authorization();
		}

		function process() {

			$password 		= $this->post("form","password");
			$email 			= $this->post("form","email");

			$user_cmodel = HMODEL_USER::create(false)
								->set_password($password,true)
								->where("email","=",$email)
								->set_state(CMODEL_USER::STATE_ACTIVE)
								->get();

			if($user_cmodel) {

				CMODEL_LOGIN::create()->login($user_cmodel);

				$this->redirect("/");
				if($redirect=$this->post("redirect"))
					$this->redirect($redirect);

				elseif($view=APPLICATION::get_view("user","home"))
					$this->redirect($view->get_url());

				$this->success();

			} else
				$this->error("There was a problem trying to login the user");
		}

	}