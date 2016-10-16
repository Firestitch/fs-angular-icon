<?
	class DBO_AUDIT extends DBO {

		function __construct() {
			$this->_tablename = "audits";
			$this->_columns["audit_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["create_date"] = new DBO_COLUMN("datetime",null,true,false);
			$this->_columns["type"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["user_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["action"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["meta"] = new DBO_COLUMN("varchar",3000,true,false);
		}
	}