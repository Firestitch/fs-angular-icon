<?
	class DBO_DOMAIN extends DBO {

		function __construct() {
			$this->_tablename = "domains";
			$this->_columns["domain_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["object_id"] = new DBO_COLUMN("int",11,false,false);
		}
	}