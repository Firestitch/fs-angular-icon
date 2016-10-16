<?

	class DBQ_LOGIN extends DBQ {

		public function __construct() {
			parent::__construct("logins", "login_id");
		}
	}