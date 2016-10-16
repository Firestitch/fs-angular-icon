<?

	class VIEW_MANAGE_MAINTENANCE extends VIEW {

		function __construct() {
			$this->set_form("/manage/domaintenance");
			$this->set_title("Maintenance");
			$this->set_route("manage","maintenance");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function init() {
		}
	}