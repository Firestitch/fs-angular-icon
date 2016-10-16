<?
	class DBO_GRAPH extends DBO {

		function __construct() {
			$this->_tablename = "graphs";
			$this->_columns["graph_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["object_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["state"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["name"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["type"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["template"] = new DBO_COLUMN("text",null,true,false);
		}
	}