<?

	class VIEW_MANAGE_INDEX extends VIEW {

		function __construct() {
			$this->set_form("/manage/doindex");
			$this->set_route("manage","index");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);


		}

		function init() {

		}
	}