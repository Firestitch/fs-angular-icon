<?
	class DBO_FIELD extends DBO {

		function __construct() {
			$this->_tablename = "fields";
			$this->_columns["field_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["name"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["interface"] = new DBO_COLUMN("char",1,false,false);
			$this->_columns["state"] = new DBO_COLUMN("char",1,false,false);
			$this->_columns["tag"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["guid"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["configs"] = new DBO_COLUMN("varchar",200,true,false);
		}
	}