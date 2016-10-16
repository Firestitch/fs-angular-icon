<?

	class DBQ_SURVEY_SESSION extends DBQ {

		public function __construct() {
			parent::__construct("survey_sessions", "survey_session_id");
		}
	}