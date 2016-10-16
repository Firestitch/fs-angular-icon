<?
	class DBO_FACEBOOK_USER extends DBO {

		function __construct() {
			$this->_tablename = "facebook_users";
			$this->_columns["facebook_user_id"] = new DBO_COLUMN("bigint",20,false,true);
			$this->_columns["email"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["first_name"] = new DBO_COLUMN("varchar",20,true,false);
			$this->_columns["last_name"] = new DBO_COLUMN("varchar",20,true,false);
			$this->_columns["state"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["website"] = new DBO_COLUMN("varchar",40,true,false);
			$this->_columns["locale"] = new DBO_COLUMN("varchar",6,true,false);
			$this->_columns["gender"] = new DBO_COLUMN("varchar",8,true,false);
			$this->_columns["birthday"] = new DBO_COLUMN("date",null,true,false);
			$this->_columns["offline_access"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["manage_pages"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["languages"] = new DBO_COLUMN("varchar",150,true,false);
		}
	}