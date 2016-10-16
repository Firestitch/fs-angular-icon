<?

	class DBQ_AUDIT extends DBQ {

		public function __construct() {
			parent::__construct("audits", "audit_id");
		}
	}