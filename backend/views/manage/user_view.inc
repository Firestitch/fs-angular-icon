<?
	class VIEW_MANAGE_USER extends VIEW {

		protected $_user_cmodel 	= null;

		function __construct() {
			$this->set_route("manage","user");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);

			$this->_user_cmodel = CMODEL_USER::create();
		}

		function init() {

			$this->add_js_lib("transmit/jquery.transmit.js");

			if(is_numeric($user_id=$this->get("uid")))
				$this->load($user_id);

			$this->set_var("user", $this->_user_cmodel);
		}

		function load($user_id) {

			$user_cmodel = HMODEL_USER::create()
								->set_user_id($user_id)
							 	->get();

			if($user_cmodel) {
				$this->_user_cmodel = $user_cmodel;
			}
		}
	}