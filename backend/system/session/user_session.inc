<?
	class SOU {

		static $user_cmodel				= null;

		private $_user_id 				= null;
		private $_settings				= array();
		private $_roles					= array();
		private $_impersonate_user_id	= null;
	
		function get_user_id() 						{ return $this->_user_id; }
		function get_roles() 						{ return $this->_roles; }
		function get_username() 					{ return $this->_username; }
		function get_setting($key) 					{ return get_value($this->_settings,$key); }
		function get_impersonate_user_id() 			{ return $this->_impersonate_user_id; }
		function remove_setting($key) 				{ unset($this->_settings[$key]); return $this; }

		function set_user_id($value) 				{ $this->_user_id = $value;  return $this; }
		function set_roles($value) 					{ $this->_roles = $value;  return $this; }
		function set_username($value) 				{ $this->_username = $value;  return $this; }
		function set_impersonate($value) 			{ $this->_is_impersonate = $value;  return $this; }
		function set_setting($key,$value) 			{ $this->_settings[$key] = $value;  return $this; }
		function set_impersonate_user_id($value) 	{ $this->_impersonate_user_id = $value;  return $this; }

		function is_logged_in() 					{ return $this->_user_id!=null; }
		function has_user() 						{ return $this->_user_id!=null; }

		function get_user() {
			 
			 if(!self::$user_cmodel && $this->_user_id)
			  	self::$user_cmodel = HMODEL_USER::get($this->_user_id);

			return self::$user_cmodel;
		}		
	}

	class USER_SESSION extends SESSION {

		protected function get_default_session_object() { return new SOU(); }

		public static function destroy() { SESSION_MANAGER::destroy(__CLASS__); }

		public static function has_session() { return SESSION_MANAGER::has_session(__CLASS__); }

		static function get_instance($reference=true) {
			$session_obj = new USER_SESSION();
			return $session_obj->get_session_object_by_ref($reference);
		}
	}	