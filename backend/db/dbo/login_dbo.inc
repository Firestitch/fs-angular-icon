<?
	class DBO_LOGIN extends DBO {

		function __construct() {
			$this->_tablename = "logins";
			$this->_columns["login_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["create_date"] = new DBO_COLUMN("datetime",null,true,false);
			$this->_columns["ip"] = new DBO_COLUMN("varchar",20,true,false);
			$this->_columns["user_id"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["email"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["user_agent"] = new DBO_COLUMN("varchar",200,true,false);
		}
	}