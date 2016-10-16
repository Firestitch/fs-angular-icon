<?

	APPLICATION::include_base_action("manage","settings");

	class ACTION_MANAGE_SETTINGS extends BASE_ACTION_MANAGE_SETTINGS {

		function __construct() {
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			$has_success = parent::process();

			if($has_success)
				APPLICATION::add_notify_message("Successfully saved settings");
			else
				APPLICATION::add_error_message("There was a problem trying to save the settings");

			$view = APPLICATION::get_view_instance("manage","settings");
			$view->set_settings($this->get_settings());
			$this->set_view($view);
		}
	}

