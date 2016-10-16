<?
	class DBO_ADDRESS extends DBO {

		function __construct() {
			$this->_tablename = "addresses";
			$this->_columns["address_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["state"] = new DBO_COLUMN("varchar",20,true,false);
			$this->_columns["address1"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["address2"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["city"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["region"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["zip"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["country"] = new DBO_COLUMN("varchar",2,true,false);
			$this->_columns["lat"] = new DBO_COLUMN("decimal",null,true,false);
			$this->_columns["lng"] = new DBO_COLUMN("decimal",null,true,false);
			$this->_columns["create_date"] = new DBO_COLUMN("datetime",null,true,false);
			$this->_columns["modify_date"] = new DBO_COLUMN("datetime",null,true,false);
			$this->_columns["guid"] = new DBO_COLUMN("varchar",40,true,false);
		}
	}