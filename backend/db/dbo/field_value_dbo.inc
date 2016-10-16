<?
	class DBO_FIELD_VALUE extends DBO {

		function __construct() {
			$this->_tablename = "field_values";
			$this->_columns["field_value_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["field_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["string"] = new DBO_COLUMN("varchar",1000,true,false);
			$this->_columns["integer"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["metas"] = new DBO_COLUMN("varchar",500,true,false);
			$this->_columns["amount"] = new DBO_COLUMN("decimal",null,true,false);
		}
	}