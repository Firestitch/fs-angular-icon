<?
	class DBO_SURVEY_INSTANCE extends DBO {

		function __construct() {
			$this->_tablename = "survey_instances";
			$this->_columns["survey_instance_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["survey_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["create_date"] = new DBO_COLUMN("datetime",null,true,false);
			$this->_columns["session_id"] = new DBO_COLUMN("int",11,false,false);
		}
	}