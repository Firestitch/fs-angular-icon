<?
	class DBO_SITE_SESSION extends DBO {

		function __construct() {
			$this->_tablename = "site_sessions";
			$this->_columns["site_session_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["contact_id"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["site_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["create_date"] = new DBO_COLUMN("datetime",null,true,false);
			$this->_columns["id"] = new DBO_COLUMN("varchar",60,true,false);
			$this->_columns["new_contact"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["existing_contact"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["login"] = new DBO_COLUMN("char",1,true,false);
			$this->_columns["entry"] = new DBO_COLUMN("varchar",400,true,false);
			$this->_columns["views"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["referer"] = new DBO_COLUMN("varchar",1000,true,false);
			$this->_columns["purl_id"] = new DBO_COLUMN("int",11,true,false);
		}
	}