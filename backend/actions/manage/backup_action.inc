<?
	APPLICATION::include_base_action("manage","backup");

	class ACTION_MANAGE_BACKUP extends ACTION {

		function __construct() {
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			parent::process();

			$view = APPLICATION::get_view_instance("manage","master");
			$this->set_view($view);
		}
	}