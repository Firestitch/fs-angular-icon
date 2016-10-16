<?
	class DBO_ACCOUNT extends DBO {

		function __construct() {
			$this->_tablename = "accounts";
			$this->_columns["account_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["root_account_id"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["parent_account_id"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["state"] = new DBO_COLUMN("char",40,false,false);
			$this->_columns["name"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["priority"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["type"] = new DBO_COLUMN("char",1,false,false);
			$this->_columns["configs"] = new DBO_COLUMN("text",null,true,false);
			$this->_columns["guid"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["image_time"] = new DBO_COLUMN("int",11,true,false);
		}
	}