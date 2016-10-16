<?

	class VIEW_USER_FORGOT extends VIEW {

		protected $_email = "";

		function __construct() {
			$this
				->set_form("javascript:;")
				->set_route("user","forgot")
				->disable_authorization();
		}

		function init() {
			$this->set_var("email",$this->_email);
		}

		function set_email($email) { $this->_email = $email; }
	}