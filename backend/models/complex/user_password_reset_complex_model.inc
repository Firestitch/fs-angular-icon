<?
	class CMODEL_USER_PASSWORD_RESET extends MODEL_COMPLEX {

		const STATE_ACTIVE 		= "active";
		const STATE_RESET 		= "reset";

		public function __construct() {
			$this->register_dbo(DBO_USER_PASSWORD_RESET::create());
		}

		public function set_user($value) { return $this->data("user",$value); }

		public function get_user($hmodel=true) {
			if($hmodel && !$this->has_data("user") && $this->get_user_id()) {
				$hmodel = is_a($hmodel,"HMODEL") ? $hmodel : HMODEL_USER::create(false);
				$this->data("user",$hmodel->get($this->get_user_id()));
			}
			return $this->data("user");
		}

		public function save() {

			$has_success = false;

			if(is_numeric($this->get_user_password_reset_id())) {
				$has_success = $this->dbo("user_password_reset")->update();
			} else {

				if(!$this->get_guid())
					$this->set_guid(MISC_UTIL::get_random_uid());

				$this
					->set_create_date(DB::get_date_time())
					->set_state(self::STATE_ACTIVE);

				$has_success = $this->dbo("user_password_reset")->insert();
			}

			if(!$has_success)
				throw new Exception("Error saving ".get_class());

			return $this;
		}

		public function populate($data,$untag=false) {
			return $this->populate_dbo($data,$untag);
		}

		function request_email($email) {

			$user_cmodel = HMODEL_USER::create()
								->where("email","=",$email)
								->get();

			return $this
					->set_email($email)
					->request($user_cmodel,self::REQUEST_TYPE_EMAIL);
		}

		function request_phone($phone) {

			$user_cmodel = HMODEL_USER::create()
								->where("phone","=",$phone)
								->get();

			return $this
					->set_phone($phone)
					->request($user_cmodel,self::REQUEST_TYPE_PHONE);
		}

		const REQUEST_TYPE_EMAIL = "email";
		const REQUEST_TYPE_PHONE = "phone";

		function request($user_cmodel,$type) {

			if(!$user_cmodel)
				throw new Exception("The account could not be found");

			$this
				->set_ip(SERVER_UTIL::get_remote_ip())
				->set_user_id($user_cmodel->get_user_id())
				->save();

			$message_cmodel = CMODEL_MESSAGE::get(CMODEL_MESSAGE::TAG_USER_PASSWORD_RESET);

			if(!$message_cmodel)
				throw new Exception("Failed to load password reset email event");

			$message_cmodel
				->set_user_email($user_cmodel->get_email())
				->set_reset_url($this->get_request_url())
				->set_reset_guid($this->get_guid());

			if($type==self::REQUEST_TYPE_EMAIL)
				$message_cmodel->send_email($user_cmodel->get_email());

			if($type==self::REQUEST_TYPE_PHONE)
				$message_cmodel->send_sms($user_cmodel->get_phone_mobile());

			return $this;
		}

		function validate() {

			if(!$this->get_guid() || !$this->get_user_id())
				throw new Exception("The password request is invalid");

			return $this;
		}

		function reset($password) {

			$this->validate();

			if(!$password)
				throw new Exception("The new password selected is invalid");

			$user_cmodel = $this->get_user();

			if(!$user_cmodel)
				throw new Exception("Invalid user");

			DB::start_transaction();

			$user_cmodel
				->set_password(CMODEL_USER::encrypt_password($password))
				->validate()
				->save();

			$this
				->set_state(self::STATE_RESET)
				->set_activate_date(DB::get_date_time())
				->save();

			if(!DB::complete_transaction())
				throw new Exception("Failed to process the reset");

			return $this;
		}

		static function get($guid) {
			return HMODEL_USER_PASSWORD_RESET::create(false)
						->set_guid($guid)
						->set_state(self::STATE_ACTIVE)
						->get();
		}

		function get_request_url() {
			return "http://".SERVER_UTIL::get_server_host()."/user/reset/".$this->get_guid()."/";
		}
	}