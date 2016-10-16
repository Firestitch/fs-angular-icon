<?

	class VIEW_USER_HOME extends VIEW {

		function __construct() {
			$this
				->set_form("/user/dohome")
				->set_route("user","home");
		}

		function init() {



			die;
		}
	}