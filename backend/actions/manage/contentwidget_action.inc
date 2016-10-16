<?
	class ACTION_MANAGE_CONTENTWIDGET extends BASE_ACTION_MANAGE_CONTENT_WIDGET {

		function __construct() {
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

	}