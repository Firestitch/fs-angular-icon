<?
	class VIEW_MANAGE_MESSAGE extends BASE_VIEW_MANAGE_MESSAGE {

		function __construct() {
			parent::__construct();
			$this->set_form("javascript:;");
			$this->set_route("manage","message");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}
	}