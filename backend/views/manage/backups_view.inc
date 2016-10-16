<?
	class VIEW_MANAGE_BACKUPS extends BASE_VIEW_MANAGE_BACKUPS {

		function __construct() {
			parent::__construct();

			$this->set_route("manage","backups");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
			$this->set_form("/manage/backups/");
		}
	}