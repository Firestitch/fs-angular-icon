<?

	class VIEW_MANAGE_UPGRADE extends VIEW {

		function __construct() {
			$this->set_form("/manage/doupgrade/");
			$this->set_route("manage","upgrade");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);

		}

		function init() {}

	}