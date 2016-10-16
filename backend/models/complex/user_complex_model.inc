<?
	class CMODEL_USER extends CMODEL_OBJECT {

		const PERMISSION_BACKEND			= "backend";

		const STATE_ACTIVE					= CMODEL_OBJECT::STATE_ACTIVE;
		const STATE_DELETED					= CMODEL_OBJECT::STATE_DELETED;
		const STATE_DRAFT					= CMODEL_OBJECT::STATE_DRAFT;

		static function get_permission_list() 			{ return [self::PERMISSION_BACKEND=>"Backend"]; }
		static function get_grouped_permission_list() 	{ return ["Backend Permissions"=>[self::PERMISSION_BACKEND=>"Backend"]]; }
		static function get_state_list() 				{ return array(	self::STATE_ACTIVE=>"Active", self::STATE_DELETED=>"Deleted", self::STATE_DRAFT=>"Draft"); }

		public function __construct() {
			parent::__construct();
			$this->register_dbo(DBO_USER::create())
					->register_delimited("permissions");
		}

		public function describe() {
			return [
				"user_id"=>["diff"=>false],
				"object_id"=>["diff"=>false],
				"object_type"=>[
					"diff"=>false,
					"default"=>CMODEL_OBJECT::TYPE_USER,
					"diff-value"=>["value"=>["CMODEL_OBJECT","get_types"]]
				],
				"create_date"=>[
					"diff"=>false,
					"default"=>"datetime",
					"sanitize"=>"time"
				],
				"state"=>[
					"default"=>CMODEL_USER::STATE_ACTIVE,
					"diff-value"=>["value"=>["CMODEL_USER","get_state_list"]]
				],
				"image_time"=>[
					"diff"=>false,
					"sanitize"=>"time"
				],
				"guid"=>[
					"diff"=>false,
					"default"=>"guid"
				],
				"configs"=>[],
				"email"=>[
					"validations"=>[
						"required"=>true,
						"duplicate"=>function($value) {
							$user_hmodel = HMODEL_USER::create()
								->where('state', '=', CMODEL_USER::STATE_ACTIVE)
								->where('email', '=', $value);

							if (!is_null($this->get_user_id()))
								$user_hmodel->where('users.user_id', '<>', $this->get_user_id());

							if ($user_hmodel->count())
								throw new Exception('Email already exists');

						},
						"email"=>true,
					]
				],
				"password"=>[
					"validations"=>[
						"required"=>true,
						"minlength"=>5,
						"custom"=>function($value) {
							if(preg_match("/123/",$value))
								throw new Exception("This password is too simple");
						}
					],
					"encode"=>function($value) {
						return CMODEL_USER::encrypt_password($value);
					}
				],
				"first_name"=>[
					"validations"=>[ "required"=>true ]
				],
				"last_name"=>[
					"validations"=>[ "required"=>true ]
				],
				"phone"=>[],
				"avatar_time"=>[
					"diff"=>false,
					"sanitize"=>"time"
				],
				"permissions"=>[],
/*				"address_id"=>[
					"diff"=>false,
                    "default" => function(){
                        $this->set_address(CMODEL_ADDRESS::create());
                    }
				],
				"get_address"=>[
					"source"=>"object",
					"diff"=>["label"=>"Address"]
				],*/
				"last_login"=>[
					"diff"=>false,
					"sanitize"=>"time"
				],
				"type"=>[],
			];
		}



		public function get_state_name()						{ return get_value(CMODEL_USER::get_state_list(),$this->get_state()); }
		public function get_name()				 				{ return $this->get_first_name().($this->get_last_name() ? " ".$this->get_last_name() : ""); }
		public function get_manage_url()		 				{ return "/manage/user/uid:".$this->get_user_id()."/"; }
		public function delete() 								{ return $this->set_state(CMODEL_USER::STATE_DELETED)->save(); }
		public function get_short_name()				 		{ return $this->get_first_name().($this->get_last_name() ? " ".substr($this->get_last_name(),0,1) : ""); }
		public function has_permission_backend()				{ return $this->has_permission(self::PERMISSION_BACKEND); }
		public function has_permission($permission)				{ return in_array($permission, $this->get_permissions()); }
		static public function encrypt_password($password,$salt='')	{ return md5(sha1(md5(base64_decode($password.$salt)).$salt).$password); }

		public function create_api_token() {
			return CMODEL_API_TOKEN::create()
						->set_user_id($this->get_user_id())
						->set_ip(SERVER_UTIL::get_remote_ip())
						->set_user_agent(SERVER_UTIL::get_user_agent())
						->save();
		}

		public function get_avatar() {

			$arry["large"] = $this->get_avatar_image_url("large");
			$arry["small"] = $this->get_avatar_image_url("small");
			$arry["tiny"] = $this->get_avatar_image_url("tiny");
			$arry["actual"] = $this->get_avatar_image_url("actual");

			return $arry;
		}

		public function arry() {

			return BASE_CMODEL_OBJECTER::create($this,
												array(	"id"=>"get_user_id",
														"get_short_name",
														"get_email",
														"get_first_name",
														"get_avatar",
														"get_last_name"))->arry();
		}

		public function get_avatar_tiny_image($attribs=array()) {
			return $this->get_avatar_image()->exists("tiny") ? $this->get_avatar_image()->img("tiny",$attribs) : HTML_UTIL::get_image("/images/avatar.png",$attribs);
		}

		public function get_avatar_small_image($attribs=array()) {
			return $this->get_avatar_image()->exists("small") ? $this->get_avatar_image()->img("small",$attribs) : HTML_UTIL::get_image("/images/avatar.png",$attribs);
		}

		public function validate() {

			BCMODEL_VALIDATE::create($this->get_email(),true)->email();

			$user_dbq = DBQ_USER::create()
							->inner("objects","object_id")
							->where("email","=",$this->get_email())
							->where("state","=",CMODEL_USER::STATE_ACTIVE);

			if($this->get_user_id())
				$user_dbq->where("user_id","<>",$this->get_user_id());

			if($user_dbq->exists())
				throw new Exception("Email already exists");

			return $this;
		}

		public function get_avatar_image($cache=true) {
			if(!$cache || !$this->has_data("avatar_image"))
				$this->data("avatar_image",CMODEL_IMAGE::create(	"/pub/us/av/",
																	"/pub/us/av/",$this->get_guid(),
																	"png",
																	array("tiny"=>"s25","small"=>"s100","medium"=>"s300","large"=>"600","actual"),
																	$this->get_avatar_time()));
			return $this->data("avatar_image");
		}

		public function commit_avatar($file) {
			$this->get_avatar_image()->purge($this->get_avatar_image()->filename());
			$this->set_avatar_time(time());
			$this->get_avatar_image(false)->process($file);
			return $this->save();
		}

		public function get_avatar_image_url($name) { return $this->get_avatar_image()->url($name, true, CMODEL_IMAGE::BLANK_IMAGE); }


		public function save() {

			DB::start_transaction();

			if(parent::save(array("type"=>self::TYPE_USER,"state"=>CMODEL_USER::STATE_ACTIVE))) {

				$has_success = false;
				if(is_numeric(self::get_user_id())) {
					$has_success = $this->dbo("user")->update();

				} else {
					$has_success = $this->dbo("user")
											->set_address_id(CMODEL_ADDRESS::create()->save()->get_address_id())
											->set_object_id(parent::get_object_id())
											->insert();
				}
			}

			if(!DB::complete_transaction())
				throw new Exception("Error Processing Request");

			return $this;
		}


		public function audit($api_token_cmodel, $action) {
			$meta = $this->end_diff();
			if(!$meta)
				return;

			CMODEL_AUDIT::create()
				->set_user_id($api_token_cmodel->get_user_id())
				->set_type(CMODEL_AUDIT::TYPE_USER)
				->set_action($action)
				->set_meta($meta)
				->save();

			return $this;
		}

	}