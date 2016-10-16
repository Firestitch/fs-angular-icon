<?

	class DBQ_API_LOG extends DBQ {

		public function __construct() {
			parent::__construct("api_logs", "api_log_id");
		}
	}