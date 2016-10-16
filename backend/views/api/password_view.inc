<? 
	class VIEW_API_PASSWORD extends VIEW_API_BASE {

		public function require_api_token() 	{ return false; }
		public function skip_group() 			{ return true; }

		public function request($guid=null,$action=null) {

			if($this->is_post()) {

				$user_cmodel = HMODEL_USER::create(false)
									->where("email","=",$this->post("email"))
									->set_state(CMODEL_USER::STATE_ACTIVE)
									->get();

				if(!$user_cmodel)
					throw new Exception("Failed to find the email");

				$user_password_reset_cmodel = CMODEL_USER_PASSWORD_RESET::create()
														->set_guid(MISC_UTIL::guid())
														->request_email($user_cmodel);

				$this->data("code",$user_password_reset_cmodel->get_guid());
			}
		}

		public function reset() {

			if($this->is_post()) {
				
				$user_password_reset_cmodel = CMODEL_USER_PASSWORD_RESET::get($this->post("code"));

				if(!$user_password_reset_cmodel)
					throw new Exception("Invalid reset code");

				$user_password_reset_cmodel->reset($this->post("password"));
			}
		}

		public function wsdl() {
			return array(	"endpoints"=>array(	array(	"path"=>"password/request",
														"method"=>"post",
														"description"=>"Request a password change",
														"parms"=>array("email"=>"Associated email address to reset password for"),
														"response"=>array(),
														),
												array(	"path"=>"password/reset",
														"method"=>"post",
														"description"=>"Change password with code",
														"parms"=>array("password","code"),
														"response"=>array(),
														),
				),
			);
		}
	}
