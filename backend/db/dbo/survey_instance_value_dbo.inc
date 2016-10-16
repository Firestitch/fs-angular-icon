<?
	class DBO_SURVEY_INSTANCE_VALUE extends DBO {

		function __construct() {
			$this->_tablename = "survey_instance_values";
			$this->_columns["survey_instance_value_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["survey_instance_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["field_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["field_value_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["amount"] = new DBO_COLUMN("decimal",null,true,false);
			$this->_columns["survey_field_id"] = new DBO_COLUMN("int",11,false,false);
		}
	}