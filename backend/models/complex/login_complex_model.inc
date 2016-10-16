<?
	class CMODEL_LOGIN extends CMODEL {

		public function __construct() {
			return parent::__construct(DBO_LOGIN::create());
		}

		public function set_user($value) { return $this->data("user",$value); }

		public function get_user($hmodel=true) {
			if($hmodel && !$this->has_data("user") && $this->get_user_id()) {
				$hmodel = is_a($hmodel,"HMODEL") ? $hmodel : HMODEL_USER::create(false);
				$this->data("user",$hmodel->get($this->get_user_id()));
			}
			return $this->data("user");
		}

		public function get_manage_url()	{ return "/manage/login/lid:".$this->get_login_id()."/"; }
		public function get_url()			{ return "/logins/login/lid:".$this->get_login_id()."/"; }

		public function save() {

			if(is_numeric(self::get_login_id())) {
				if(!$this->dbo("login")->update())
					throw new Exception("Error updating ".get_class());

			} else {
				if(!$this->get_create_date())
					$this->set_create_date(DB::get_date_time());

				if(!$this->dbo("login")->insert())
					throw new Exception("Error inserting ".get_class());
			}

			return $this;
		}

		public function login_api($email, $password) {

			$user_cmodel = HMODEL_USER::create()
									->where("state","=",CMODEL_USER::STATE_ACTIVE)
									->where("email","=",$email)
									->set_password($password,true)
									->get();

			$time_cmodel = CMODEL_TIME::create(time())->subtract_minute("5");

			if($user_cmodel) {
				$login_cmodel = HMODEL_LOGIN::create()
									->where("user_id","=",$user_cmodel->get_user_id())
									->order("create_date","DESC")
									->get();

				if($login_cmodel)
					$time_cmodel = CMODEL_TIME::create($login_cmodel->get_create_date());
			}

			$count = DBQ_LOGIN::create()
						->where("email","=",$email)
						->where("ip","=",SERVER_UTIL::get_remote_ip())
						->where("create_date",">",$time_cmodel->db())
						->count();

			if($count>5)
				throw new Exception("You have exceeded the maximum login attempts. Please try again in 5 minutes");

			$login_cmodel = CMODEL_LOGIN::create()
							->set_ip(SERVER_UTIL::get_remote_ip())
							->set_user_agent(SERVER_UTIL::get_user_agent())
							->set_email($email)
							->save();

			if(!$user_cmodel)
				throw new Exception("The email and password you entered don't match.");

			$login_cmodel
				->set_user_id($user_cmodel->get_user_id())
				->save();

			$user_cmodel
				->set_last_login(DB::get_date_time())
				->save();

			$api_token_cmodel = $user_cmodel->create_api_token();

			return $api_token_cmodel;
		}

		public function login($user_cmodel) {

			$user_cmodel
				->set_last_login(DB::get_date_time())
				->save();

			USER_SESSION::get_instance()
				->set_user_id($user_cmodel->get_user_id())
				->set_roles($user_cmodel->get_permissions());

			return $this;
		}

		public function logout() {
			USER_SESSION::destroy();
		}

		public static function is_logged_in() { return USER_SESSION::get_instance()->is_logged_in(); }
		public function arry($arry=array()) {

			$arry = CMODEL_OBJECTER::create($this,
											array(	"id"=>"get_login_id",
													"get_create_date",
													"get_ip",
													"get_user_id",
													"get_email",
													"get_user_agent",
													))->arry();

			if($user_cmodel=$this->get_user(false))
				$arry["user"] = $user_cmodel->arry();

			return $arry;
		}
	}