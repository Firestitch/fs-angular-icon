<?
	class DBO_CONVERSATION_OBJECT extends DBO {

		function __construct() {
			$this->_tablename = "conversation_objects";
			$this->_columns["conversation_object_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["conversation_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["object_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["start_conversation_message_id"] = new DBO_COLUMN("int",11,true,false);
			$this->_columns["state"] = new DBO_COLUMN("char",1,true,false);
		}
	}