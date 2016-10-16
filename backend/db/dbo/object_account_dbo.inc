<?
	class DBO_OBJECT_ACCOUNT extends DBO {

		function __construct() {
			$this->_tablename = "object_accounts";
			$this->_columns["object_account_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["account_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["object_id"] = new DBO_COLUMN("int",11,false,false);
		}
	}