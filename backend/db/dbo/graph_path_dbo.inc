<?
	class DBO_GRAPH_PATH extends DBO {

		function __construct() {
			$this->_tablename = "graph_paths";
			$this->_columns["graph_path_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["target_graph_node_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["source_graph_node_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["graph_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["state"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["configs"] = new DBO_COLUMN("text",null,true,false);
			$this->_columns["priority"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["trigger"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["label"] = new DBO_COLUMN("varchar",200,true,false);
		}
	}