<?
	class DBO_SURVEY extends DBO {

		function __construct() {
			$this->_tablename = "surveys";
			$this->_columns["survey_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["object_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["graph_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["height"] = new DBO_COLUMN("varchar",7,true,false);
			$this->_columns["width"] = new DBO_COLUMN("varchar",7,true,false);
			$this->_columns["css"] = new DBO_COLUMN("mediumtext",null,true,false);
			$this->_columns["css_modified_time"] = new DBO_COLUMN("int",11,true,false);
		}
	}