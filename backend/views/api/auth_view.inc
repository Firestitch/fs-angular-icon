<?
	class VIEW_API_AUTH extends VIEW_API_BASE {

		public function require_api_token() { return false; }

		public function login() {

			if($this->is_post()) {

				$api_token_cmodel = CMODEL_LOGIN::login_api($this->post("email"),$this->post("password"));

				$this->data("session",$api_token_cmodel->session());
			}
		}

		public function logout() {

			if($this->is_post()) {

				if($api_token_cmodel=$this->get_api_token()) {
					$api_token_cmodel->deactivate();
				}			
			}			
		}

		public function impersonate() {

			if($this->is_post()) {

				$impersonate_cmodel = HMODEL_IMPERSONATE::create()
											->set_guid($this->post("guid"))
											->get();

				if(!$impersonate_cmodel)
					throw new Exception("Invalid impersonation token");
				
				$impersonated_user_cmodel = $impersonate_cmodel->get_impersonated_user();

				if(!$impersonated_user_cmodel)
					throw new Exception("Failed to load the user");					

				$impersonate_cmodel
					->set_ip(SERVER_UTIL::get_remote_ip())
					->set_user_agent(SERVER_UTIL::get_user_agent())
					->set_activate_date(DB::get_date_time())
					->set_state(CMODEL_IMPERSONATE::STATE_ACTIVATED)
					->save();

				$api_token_cmodel = $impersonated_user_cmodel->create_api_token();

				$this->data("session",$api_token_cmodel->session());
			}
		}

		public function wsdl() {
			return array(	"name"=>"Authentication",
							"description"=>"For protected APIs you must first request a API token provided by the auth endpoint. Depending on the level of access you will target the /auth/login or /auth/token endpoints.",
							"endpoints"=>array(array(	"path"=>"login",
														"description"=>"Use account credentials and receive an api token",
														"method"=>"post",
														"parms"=>array("email","password"),
														"response"=>array("user","token")),
										array(	"path"=>"auth/token",
														"method"=>"post",
														"parms"=>array(),
														"response"=>array("token")),
										array(	"path"=>"auth/impersonate",
														"method"=>"post",
														"parms"=>array("guid"=>"The guid associated with the user to be impersonated"),
														"response"=>array("user","token")),
										array(	"path"=>"auth/logout",
														"method"=>"post",
														"parms"=>array(),
														"response"=>array())
			));
		}		
	}