<?

	class DBQ_USER_PASSWORD_RESET extends DBQ {

		public function __construct() {
			parent::__construct("user_password_resets", "user_password_reset_id");
		}
	}