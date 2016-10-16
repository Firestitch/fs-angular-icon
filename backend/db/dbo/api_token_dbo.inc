<?
	class DBO_API_TOKEN extends DBO {

		function __construct() {
			$this->_tablename = "api_tokens";
			$this->_columns["api_token_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["user_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["create_date"] = new DBO_COLUMN("datetime",null,true,false);
			$this->_columns["expiry_date"] = new DBO_COLUMN("datetime",null,true,false);
			$this->_columns["key"] = new DBO_COLUMN("varchar",100,true,false);
			$this->_columns["state"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["ip"] = new DBO_COLUMN("varchar",20,true,false);
			$this->_columns["user_agent"] = new DBO_COLUMN("varchar",250,true,false);
		}
	}