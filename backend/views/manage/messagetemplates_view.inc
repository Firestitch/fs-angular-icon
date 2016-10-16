<?
	class VIEW_MANAGE_MESSAGETEMPLATES extends BASE_VIEW_MANAGE_MESSAGETEMPLATES {

		function __construct() {
			parent::__construct();

			$this->set_route("manage","messagetemplates");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}
	}