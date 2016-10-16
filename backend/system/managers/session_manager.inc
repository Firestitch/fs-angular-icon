<?

	class SESSION_MANAGER extends BASE_SESSION_MANAGER {
		
		static function get_session_class_mapping() {
			$class_list["SOU"] = "user_session";	
			
			return $class_list;
		}

		public function create_dbq()	{ return new DBQ("user_sessions","user_session_id"); }
		
		static function unserialize_callback($class) {

			$class_list = self::get_session_class_mapping();
			
			if($object=get_value($class_list,$class)) {
				$session_file = APPLICATION::get_main_application_directory()."system/session/".$object.".inc";
				include_once($session_file);
			}
		}
	}
	