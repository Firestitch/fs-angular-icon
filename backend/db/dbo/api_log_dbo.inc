<?
	class DBO_API_LOG extends DBO {

		function __construct() {
			$this->_tablename = "api_logs";
			$this->_columns["api_log_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["create_date"] = new DBO_COLUMN("datetime",null,true,false);
			$this->_columns["request"] = new DBO_COLUMN("text",null,true,false);
			$this->_columns["response"] = new DBO_COLUMN("text",null,true,false);
			$this->_columns["state"] = new DBO_COLUMN("varchar",15,true,false);
			$this->_columns["headers"] = new DBO_COLUMN("text",null,true,false);
			$this->_columns["url"] = new DBO_COLUMN("varchar",400,true,false);
			$this->_columns["code"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["direction"] = new DBO_COLUMN("varchar",15,true,false);
			$this->_columns["reference"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["message"] = new DBO_COLUMN("varchar",300,true,false);
			$this->_columns["type"] = new DBO_COLUMN("varchar",20,true,false);
			$this->_columns["length"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["method"] = new DBO_COLUMN("varchar",10,true,false);
		}
	}