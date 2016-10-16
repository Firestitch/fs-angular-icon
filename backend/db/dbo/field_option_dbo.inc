<?
	class DBO_FIELD_OPTION extends DBO {

		function __construct() {
			$this->_tablename = "field_options";
			$this->_columns["field_option_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["field_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["state"] = new DBO_COLUMN("char",1,false,false);
			$this->_columns["guid"] = new DBO_COLUMN("varchar",40,false,false);
			$this->_columns["label"] = new DBO_COLUMN("varchar",200,true,false);
			$this->_columns["configs"] = new DBO_COLUMN("varchar",500,true,false);
			$this->_columns["amount"] = new DBO_COLUMN("decimal",null,true,false);
		}
	}