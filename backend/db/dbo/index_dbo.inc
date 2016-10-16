<?
	class DBO_INDEX extends DBO {

		function __construct() {
			$this->_tablename = "indexes";
			$this->_columns["index_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["name"] = new DBO_COLUMN("varchar",300,true,false);
			$this->_columns["primary_keyword"] = new DBO_COLUMN("varchar",100,true,false);
			$this->_columns["secondary_keyword"] = new DBO_COLUMN("varchar",1000,true,false);
			$this->_columns["image_url"] = new DBO_COLUMN("varchar",200,true,false);
			$this->_columns["customer_user_id"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["type"] = new DBO_COLUMN("varchar",20,true,false);
			$this->_columns["icon"] = new DBO_COLUMN("varchar",20,true,false);
			$this->_columns["icon_color"] = new DBO_COLUMN("varchar",10,true,false);
			$this->_columns["account_id"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["state"] = new DBO_COLUMN("varchar",20,true,false);
		}
	}