<?

	class VIEW_MANAGE_ROLE extends VIEW {

		function __construct() {
			$this->set_form("/manage/dorole");
			$this->set_title("Role");
			$this->set_route("manage","role");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
				$this->_role_cmodel = new CMODEL_ROLE();
		}

		function init() {

			if(is_numeric($role_id=$this->get_get_parm(0)))
				$this->load_view($role_id);

			$this->set_var("role", $this->_role_cmodel);
		}

		private $_role_cmodel = null;

		function load_view($role_id) {

			$role_cmodel = HMODEL_ROLE::get_role($role_id);

			if($role_cmodel)
				$this->_role_cmodel = $role_cmodel;
		}

		function set_role($role_cmodel) { $this->_role_cmodel = $role_cmodel; }
	}