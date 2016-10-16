<?
	class VIEW_USER_SIGNUP extends VIEW {

		protected $_user_cmodel = null;

		function __construct() {
			parent::__construct("user","signup",[],"user-signup-form")->disable_authorization();

			$this->_user_cmodel = CMODEL_USER::create();
		}

		function init() {
			$this->set_var("user",$this->_user_cmodel);
		}

		function set_user($user_cmodel) { $this->_user_cmodel = $user_cmodel; }
	}