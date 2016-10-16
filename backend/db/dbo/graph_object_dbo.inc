<?
	class DBO_GRAPH_OBJECT extends DBO {

		function __construct() {
			$this->_tablename = "graph_objects";
			$this->_columns["graph_object_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["graph_node_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["next_graph_node_id"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["state"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["label"] = new DBO_COLUMN("varchar",500,true,false);
			$this->_columns["type"] = new DBO_COLUMN("char",2,true,false);
			$this->_columns["next_url"] = new DBO_COLUMN("varchar",300,true,false);
			$this->_columns["priority"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["configs"] = new DBO_COLUMN("text",null,true,false);
			$this->_columns["tag"] = new DBO_COLUMN("varchar",40,true,false);
		}
	}