<?

	class DBQ_site_session extends DBQ {

		const LOGIN_FACEBOOK 	= "F";
		const LOGIN_EMAIL 		= "E";
		const LOGIN_SMS 		= "S";

		public function __construct() {
			parent::__construct("site_sessions", "site_session_id");
		}
	}