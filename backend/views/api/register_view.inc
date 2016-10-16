<?
	class VIEW_API_REGISTER extends VIEW_API_BASE {

		public function require_api_token() { return false; }

		public function register($user_id=null,$action=null) {

			if($this->is_post()) {

				if(!$this->post("email"))
					throw new Exception("Please provide an email address.");

				if(!$this->post("password"))
					throw new Exception("Please provide an email password.");

				if(!$this->post("first_name") || !$this->post("last_name"))
					throw new Exception("Please provide a first and last name.");

				$email_found = HMODEL_USER::create()
									->where("email","=",$this->post("email"))
									->exists();

				if($email_found)
					throw new Exception("Email already used.");

				$user_cmodel = CMODEL_USER::create()
									->set_first_name($this->post("first_name"))
									->set_last_name($this->post("last_name"))
									->set_email($this->post("email"))
									->set_password($this->post("password"),true)
									->validate()
									->save();

				$user_cmodel->create_api_token()->save();
					
				$this->data("user",$user_cmodel->arry());

			} elseif($this->is_delete()) {


			}
		}

		public function wsdl() {
			return array(	"endpoints"=>array(
												array(	"path"=>"register",
														"method"=>"post",
														"parms"=>array(	"first_name"=>"",
																		"last_name"=>"",
																		"email"=>"",
																		"password"=>"",
																		),
														"response"=>array("user"=>"")
														),
												));
		}
	}


