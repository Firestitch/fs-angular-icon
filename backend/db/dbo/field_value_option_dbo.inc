<?
	class DBO_FIELD_VALUE_OPTION extends DBO {

		function __construct() {
			$this->_tablename = "field_value_options";
			$this->_columns["field_value_option_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["field_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["field_option_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["field_value_id"] = new DBO_COLUMN("int",11,false,false);
		}
	}