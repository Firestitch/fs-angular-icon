<?
	class DBO_CONVERSATION_MESSAGE extends DBO {

		function __construct() {
			$this->_tablename = "conversation_messages";
			$this->_columns["conversation_message_id"] = new DBO_COLUMN("int",11,false,true);
			$this->_columns["message_queue_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["conversation_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["object_id"] = new DBO_COLUMN("int",11,false,false);
			$this->_columns["state"] = new DBO_COLUMN("char",1,true,false);
		}
	}