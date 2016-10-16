<?
	class VIEW_MANAGE_CONTENTWIDGET extends BASE_VIEW_MANAGE_CONTENT_WIDGET {

		function __construct() {
			parent::__construct();
			$this->set_route("manage","contentwidget");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}
	}