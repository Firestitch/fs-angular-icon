<?

	class ACTION_MANAGE_ROLE extends ACTION {

		function __construct() {
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			$role_id	= $this->get_numeric_post_parm("rid");
			$form	= $this->get_post_parm("form");

			$role_cmodel = new CMODEL_ROLE();
			$role_cmodel->populate($form);

			$has_success = false;
			$view = null;

			if($this->is_form_valid()) {
				if($role_id)
					$role_cmodel->set_role_id($role_id);
				$has_success = $role_cmodel->save();
			}

			if($has_success) {
				APPLICATION::add_notify_message("Sucessfully saved the role");
				$view = APPLICATION::get_view_instance("manage","roles");
			} else
				APPLICATION::add_error_message("There was a problem trying to save the role");

			if(!$view) {
				$view = APPLICATION::get_view_instance("manage","role");
				$view->set_role(role_id);
			}
			$this->set_view($view);

		}
	function is_form_valid() {
		return !APPLICATION::has_error_messages();
	}	}