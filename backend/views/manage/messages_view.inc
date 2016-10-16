<?
	class VIEW_MANAGE_MESSAGES extends BASE_VIEW_MANAGE_MESSAGES {

		function __construct() {
			parent::__construct();

			$this->set_route("manage","messages");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}
	}