<?

	class VIEW_USER_RESETCODE extends VIEW {

		protected $_guid 		= "";
		protected $_email 		= "";

		function __construct() {
			$this
				->set_form("javascript:;")
				->set_route("user","resetcode")
				->disable_authorization();
		}

		function init() {

			$this->set_var("guid",$this->_guid);
			$this->set_var("email",$this->_email);
		}

		function set_guid($guid) 				{ $this->_guid = $guid; }
		function set_email($email) 				{ $this->_email = $email; }
	}