<?
	class VIEW_MANAGE_INFO extends BASE_VIEW_MANAGE_INFO {

		function __construct() {
			parent::__construct();
			if(!SYSTEM_MANAGER::is_system_mode_debug())
				$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}
	}