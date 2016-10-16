<?
	class DBO_SURVEY_GRAPH_NODE extends DBO {

		function __construct() {
			$this->_tablename = "survey_graph_nodes";
			$this->_columns["survey_graph_node_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["survey_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["height"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["width"] = new DBO_COLUMN("int",11,true,false);
		}
	}