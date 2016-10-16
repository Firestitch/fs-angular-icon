<?
	class DBO_GRAPH_NODE extends DBO {

		function __construct() {
			$this->_tablename = "graph_nodes";
			$this->_columns["graph_node_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["graph_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["state"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["type"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["title"] = new DBO_COLUMN("varchar",500,true,false);
			$this->_columns["next_url"] = new DBO_COLUMN("varchar",100,true,false);
			$this->_columns["next_label"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["x"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["y"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["name"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["path"] = new DBO_COLUMN("varchar",100,true,false);
			$this->_columns["template"] = new DBO_COLUMN("text",null,true,false);
			$this->_columns["default"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["guid"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["preview"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["tag"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["preview_time"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["configs"] = new DBO_COLUMN("text",null,true,false);
		}
	}