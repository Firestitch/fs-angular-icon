<?
	class DBO_SURVEY_FIELD extends DBO {

		function __construct() {
			$this->_tablename = "survey_fields";
			$this->_columns["survey_field_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["survey_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["field_id"] = new DBO_COLUMN("int",11,false,false);
		}
	}