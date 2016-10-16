<?

	class VIEW_USER_RESET extends VIEW {

		protected $_guid 				= "";
		protected $_password 			= "";
		protected $_password_confirm 	= "";

		function __construct() {
			$this
				->set_form("javascript:;")
				->set_route("user","reset")
				->disable_authorization();
		}

		function init() {

			if($guid=$this->get_get_parm(0))
				$this->load_view($guid);

			$this->set_var("guid",$this->_guid);
			$this->set_var("password",$this->_password);
			$this->set_var("password_confirm",$this->_password_confirm);
		}

		function set_guid($guid) 				{ $this->_guid = $guid; }

		function load_view($guid) {
			if(CMODEL_USER_PASSWORD_RESET::is_valid_guid($guid))
					$this->_guid = $guid;
				else {
					$this->reroute("user","resetcode");
					APPLICATION::add_error_message("The password change request is invalid");
				}
		}
	}