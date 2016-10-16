<?

	class DBQ_IMPERSONATE extends DBQ {

		public function __construct() {
			parent::__construct("impersonates", "impersonate_id");
		}
	}