<?
	class DBO_OBJECT extends DBO {

		function __construct() {
			$this->_tablename = "objects";
			$this->_columns["object_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["state"] = new DBO_COLUMN("varchar",15,true,false);
			$this->_columns["name"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["create_date"] = new DBO_COLUMN("datetime",null,true,false);
			$this->_columns["object_type"] = new DBO_COLUMN("char",1,false,false);
			$this->_columns["image_time"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["guid"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["configs"] = new DBO_COLUMN("text",null,true,false);
		}
	}