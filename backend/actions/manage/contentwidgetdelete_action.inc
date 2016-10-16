<?

	APPLICATION::include_base_action("manage","content_widget_delete");

	class ACTION_MANAGE_CONTENTWIDGETDELETE extends BASE_ACTION_MANAGE_CONTENT_WIDGET_DELETE {

		function __construct() {
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			if(parent::process())
				APPLICATION::add_notify_message("Succesfully removed the content widget");
			else
				APPLICATION::add_error_message("There was a problem trying to remove the content widget");

			$view = APPLICATION::get_view_instance("manage","contentwidgets");
			$this->set_view($view);
		}
	}