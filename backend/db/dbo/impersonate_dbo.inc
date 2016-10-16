<?
	class DBO_IMPERSONATE extends DBO {

		function __construct() {
			$this->_tablename = "impersonates";
			$this->_columns["impersonate_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["state"] = new DBO_COLUMN("varchar",15,true,false);
			$this->_columns["ip"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["user_agent"] = new DBO_COLUMN("varchar",400,true,false);
			$this->_columns["create_date"] = new DBO_COLUMN("datetime",null,true,false);
			$this->_columns["guid"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["activate_date"] = new DBO_COLUMN("datetime",null,true,false);
			$this->_columns["user_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["impersonated_user_id"] = new DBO_COLUMN("int",11,false,false);
		}
	}