<?

	APPLICATION::include_base_action("manage","contentdelete");

	class ACTION_MANAGE_CONTENTDELETE extends BASE_ACTION_MANAGE_CONTENTDELETE {

		function __construct() {
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			parent::process();

			if($this->_has_success)
				APPLICATION::add_notify_message("Succesfully removed the content");
			else
				APPLICATION::add_error_message("There was a problem trying to remove the content");

			$view = APPLICATION::get_view_instance("manage","contents");
			$this->set_view($view);
		}
	}