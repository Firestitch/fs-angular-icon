<?
	class DBO_GRAPH_VALUE extends DBO {

		function __construct() {
			$this->_tablename = "graph_values";
			$this->_columns["graph_value_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["graph_object_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["graph_node_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["values"] = new DBO_COLUMN("text",null,true,false);
			$this->_columns["session_id"] = new DBO_COLUMN("int",11,false,false);
		}
	}