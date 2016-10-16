<?
	class DBO_GRAPH_CONDITION extends DBO {

		function __construct() {
			$this->_tablename = "graph_conditions";
			$this->_columns["graph_condition_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["graph_path_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["state"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["object"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["configs"] = new DBO_COLUMN("text",null,true,false);
			$this->_columns["value"] = new DBO_COLUMN("text",null,true,false);
			$this->_columns["unit"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["graph_object_id"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["priority"] = new DBO_COLUMN("int",11,true,false);
		}
	}