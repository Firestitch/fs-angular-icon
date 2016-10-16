<?
	class CMODEL_SESSION extends MODEL_COMPLEX {
		
		public static $instance = null;

		public function __construct() {
			parent::__construct(new DBO_SESSION);
		}
		
		public function get_manage_url()	{ return "/manage/session/sid:".$this->get_session_id()."/"; }
		
		public function get_instance() {

			if(!self::$instance)
				self::$instance = HMODEL_SESSION::get(USER_SESSION::get_instance()->get_setting("session_id"));

			if(!self::$instance)
				self::$instance = self::create_instance();

			return self::$instance;			
		}

		public static function create_instance() {
			
			$session_cmodel = CMODEL_SESSION::create();

			$session_cmodel->save();

			USER_SESSION::get_instance()->set_setting("session_id",$session_cmodel->get_session_id());

			return $session_cmodel;
		}

		public function save() {
			
			DB::start_transaction();
			
			$has_success = false;
			if(is_numeric(self::get_session_id())) {
				$has_success = $this->get_dbo("session")->update();
				
			} else {
				if(!$this->get_created_date())
					$this->set_created_date(DB::get_date_time());
					
				$has_success = $this->get_dbo("session")->insert();
			}
			
			$has_success = DB::has_transaction_success();
			DB::complete_transaction();
			
			return $has_success;
		}
	}