<?
	class DBO_USER extends DBO {

		function __construct() {
			$this->_tablename = "users";
			$this->_columns["user_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["object_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["email"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["password"] = new DBO_COLUMN("varchar",40,false,false);
			$this->_columns["first_name"] = new DBO_COLUMN("varchar",20,true,false);
			$this->_columns["last_name"] = new DBO_COLUMN("varchar",20,true,false);
			$this->_columns["phone"] = new DBO_COLUMN("varchar",15,true,false);
			$this->_columns["avatar_time"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["permissions"] = new DBO_COLUMN("varchar",500,true,false);
			$this->_columns["address_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["last_login"] = new DBO_COLUMN("datetime",null,true,false);
			$this->_columns["type"] = new DBO_COLUMN("varchar",10,true,false);
		}
	}