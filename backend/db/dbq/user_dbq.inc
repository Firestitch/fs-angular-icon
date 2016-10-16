<?

	class DBQ_USER extends DBQ {
		
		public function __construct() {
			parent::__construct("users", "user_id");
		}
	}