<?
	class DBO_ROLE extends DBO {

		function __construct() {
			$this->_tablename = "roles";
			$this->_columns["role_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["role"] = new DBO_COLUMN("char",2,false,false);
			$this->_columns["name"] = new DBO_COLUMN("varchar",40,true,false);
		}
	}