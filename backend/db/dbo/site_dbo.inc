<?
	class DBO_SITE extends DBO {

		function __construct() {
			$this->_tablename = "sites";
			$this->_columns["site_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["object_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["domain_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["graph_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["subdomain"] = new DBO_COLUMN("varchar",40,true,false);
		}
	}