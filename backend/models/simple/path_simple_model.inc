<?

	class MODEL_PATH extends BASE_MODEL_PATH {

		static function get_content_dir()						{ return MODEL_PATH::get_web_dir(); }
		static function get_content_url()						{ return "/"; }	
	}