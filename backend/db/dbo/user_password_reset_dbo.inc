<?
	class DBO_USER_PASSWORD_RESET extends DBO {

		function __construct() {
			$this->_tablename = "user_password_resets";
			$this->_columns["user_password_reset_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["user_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["create_date"] = new DBO_COLUMN("datetime",null,true,false);
			$this->_columns["activate_date"] = new DBO_COLUMN("datetime",null,true,false);
			$this->_columns["guid"] = new DBO_COLUMN("varchar",45,true,false);
			$this->_columns["state"] = new DBO_COLUMN("varchar",45,true,false);
			$this->_columns["email"] = new DBO_COLUMN("varchar",30,true,false);
			$this->_columns["phone"] = new DBO_COLUMN("varchar",20,true,false);
			$this->_columns["ip"] = new DBO_COLUMN("varchar",20,true,false);
		}
	}