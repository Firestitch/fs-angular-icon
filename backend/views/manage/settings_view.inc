<?
	class VIEW_MANAGE_SETTINGS extends BASE_VIEW_MANAGE_SETTINGS {

		function __construct() {
			$this->set_form("/manage/dosettings");
			$this->set_route("manage","settings");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function init() {

			parent::init();

		}
	}