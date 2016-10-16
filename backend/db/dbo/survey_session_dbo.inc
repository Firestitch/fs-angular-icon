<?
	class DBO_SURVEY_SESSION extends DBO {

		function __construct() {
			$this->_tablename = "survey_sessions";
			$this->_columns["survey_session_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["survey_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["create_date"] = new DBO_COLUMN("datetime",null,true,false);
			$this->_columns["id"] = new DBO_COLUMN("varchar",60,true,false);
			$this->_columns["site_session_id"] = new DBO_COLUMN("int",11,false,false);
		}
	}