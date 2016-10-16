<?
	class DBO_CONTACT extends DBO {

		function __construct() {
			$this->_tablename = "contacts";
			$this->_columns["contact_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["parent_contact_id"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["first_name"] = new DBO_COLUMN("varchar",20,true,false);
			$this->_columns["last_name"] = new DBO_COLUMN("varchar",20,true,false);
			$this->_columns["email"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["mobile"] = new DBO_COLUMN("varchar",20,true,false);
			$this->_columns["address"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["city"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["region"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["zip"] = new DBO_COLUMN("varchar",10,true,false);
			$this->_columns["country"] = new DBO_COLUMN("char",2,true,false);
			$this->_columns["dob"] = new DBO_COLUMN("date",null,true,false);
			$this->_columns["pwd"] = new DBO_COLUMN("varchar",200,true,false);
			$this->_columns["registered"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["optin"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["account_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["object_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["type"] = new DBO_COLUMN("char",1,true,false);
		}
	}