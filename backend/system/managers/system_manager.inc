<?
	class SYSTEM_MANAGER extends BASE_SYSTEM_MANAGER {

		static function get_restricted_view() 			{ return APPLICATION::get_view_instance("application","restricted"); }
		static function get_login_view()				{ return APPLICATION::get_view_instance("user","spreadsheet"); }
		static function get_index_view()				{ return self::get_login_view(); }
		static function get_session_timeout_minutes()	{ return 60 * 12; }
		static function get_temporary_directory()		{ return MODEL_PATH::get_temporary_directory(); }
		static function get_system_name() 				{ return self::$_SYSTEM_NAME; }
		static function get_controller_js_names() 		{ return array("user"); }
		static function get_controller_css_names() 		{ return array("manage"); }
		static function get_timezone() 					{ return "UTC"; }
		static function	get_logger()					{ return self::is_system_mode_production() ? parent::get_logger() : null; }
		static function requires_session() 				{ return !APPLICATION::instance()->get_uri()->is_controller("api"); }
		static function get_public_domain()				{ return CMODEL_SETTING::get_s3_bucket_domain(); }
		static function get_public_root() 				{ return CMODEL_SETTING::get_s3_bucket(); }
		static function get_public_path() 				{ return "/pub/"; }
		static function storage()						{ return CMODEL_STORAGE_S3::create(CMODEL_AMAZON_AWS::create(array( "key"=>CMODEL_SETTING::get_aws_access_key_id(),
																															"secret"=>CMODEL_SETTING::get_aws_secret_access_key())),
																							array(	"bucket"=>CMODEL_SETTING::get_s3_bucket(),
																									"public_path"=>"/pub",
																									"public_acl"=>"public-read")); }
		static function initialize() {

			parent::initialize();

			HTML_UTIL::set_defaults(array(	"input"=>array("class"=>"form-control"),
											"button"=>array("class"=>"btn btn-default"),
											"textarea"=>array("class"=>"form-control"),
											"dropdown"=>array("class"=>"form-control")));

			HTML_TABLE_UTIL::set_defaults("table table-striped table-bordered" ,"","");

			if(APPLICATION::get_instance()->is_web() && APPLICATION::get_instance()->get_uri()->is_controller(["api","manage"]))
				REGISTRY::get_instance()
					->set_posts(XSS_UTIL::decode(REGISTRY::get_instance()->posts()))
					->set_gets(XSS_UTIL::decode(REGISTRY::get_instance()->gets()))
					->set_requests(XSS_UTIL::decode(REGISTRY::get_instance()->requests()));
		}

		static function get_not_found_view() {

			$view = null;

			if(APPLICATION::get_instance()->get_uri()->is_controller("api"))
				$view = APPLICATION::get_view("api","base");

			if(!$view)
				$view = APPLICATION::get_view_instance("application","notfound");

			return $view;
		}

		static function get_email($subject="",$body="",$from_email="",$from_name="") {

			$from_name 	= $from_name ? $from_name : CMODEL_SETTING::get_instance()->get_smtp_from_name();
			$from_email = $from_email ? $from_email : CMODEL_SETTING::get_instance()->get_smtp_from_email();

			return CMODEL_EMAIL::create($subject,$body,$from_email,$from_name)
						->set_smtp_host(CMODEL_SETTING::get_instance()->get_smtp_host())
						->set_smtp_user(CMODEL_SETTING::get_instance()->get_smtp_user())
						->set_smtp_pass(CMODEL_SETTING::get_instance()->get_smtp_password())
						->set_smtp_port(CMODEL_SETTING::get_instance()->get_smtp_port());
		}

		static function has_access($roles,$permissions) {

			$user_cmodel = USER_SESSION::get_instance()->get_user();

			if(!$user_cmodel)
				return false;

			if(!$roles && !$permissions)
				return true;

			$roles = (array)($roles);

			foreach($permissions as $permission)
				if(in_array($permission,$user_cmodel->get_permissions()))
					return true;

			return false;
		}

		static function get_task_roles() {

			$file = FILE_UTIL::get_file_contents(MODEL_PATH::get_application_dir()."models/complex/user_complex_model.inc");

			preg_match_all('/const\s+(PERMISSION_[A-Z_0-9]*)/', $file, $matches);

			$roles = [];
			foreach(value($matches,1,[]) as $role) {
				$roles["CMODEL_USER::".$role] = "CMODEL_USER::".$role;
			}

			return $roles;
		}
	}