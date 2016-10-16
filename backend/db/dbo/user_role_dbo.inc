<?
	class DBO_USER_ROLE extends DBO {

		function __construct() {
			$this->_tablename = "user_roles";
			$this->_columns["user_role_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["role_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["user_id"] = new DBO_COLUMN("int",11,false,false);
		}
	}