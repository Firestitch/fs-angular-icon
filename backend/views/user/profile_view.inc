<?
	class VIEW_USER_PROFILE extends VIEW {

		function __construct() {
			parent::__construct("user","profile",[],"user-profile-form");
		}

		function init() {
			$this->add_js_lib("upload/upload.js");
			$this->set_var("user",USER_SESSION::get_instance()->get_user());
		}
	}