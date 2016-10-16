<?
	class DBO_SESSION extends DBO {

		function __construct() {
			$this->_tablename = "sessions";
			$this->_columns["session_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["contact_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["id"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["create_date"] = new DBO_COLUMN("varchar",40,true,false);
		}
	}