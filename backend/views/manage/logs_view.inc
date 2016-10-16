<?
	class VIEW_MANAGE_LOGS extends BASE_VIEW_MANAGE_LOGS {

		function __construct() {
			parent::__construct()->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}
	}