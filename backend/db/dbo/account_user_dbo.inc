<?
	class DBO_ACCOUNT_USER extends DBO {

		function __construct() {
			$this->_tablename = "account_users";
			$this->_columns["account_user_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["root_account_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["account_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["user_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["state"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["roles"] = new DBO_COLUMN("varchar",200,true,false);
			$this->_columns["premissions"] = new DBO_COLUMN("varchar",200,true,false);
			$this->_columns["defaut"] = new DBO_COLUMN("char",1,true,false);
		}
	}