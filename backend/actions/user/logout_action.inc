<?
	class ACTION_USER_LOGOUT extends ACTION {

		function __construct() {
			parent::__construct()->disable_authorization();
		}

		function process() {

			SESSION_MANAGER::destroy_session();

			HTTP_UTIL::redirect("/user/login/");

		}
	}