<?
	class DBO_CONVERSATION extends DBO {

		function __construct() {
			$this->_tablename = "conversations";
			$this->_columns["conversation_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["create_object_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["state"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["create_date"] = new DBO_COLUMN("datetime",null,true,false);
			$this->_columns["guid"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["subject"] = new DBO_COLUMN("varchar",200,true,false);
		}
	}