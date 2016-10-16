<?

	class VIEW_MANAGE_INFOFRAME extends VIEW {

		function __construct() {
			$this->set_route("manage","infoframe")->type_blank();

			if(!SYSTEM_MANAGER::is_system_mode_debug())
				$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function init() { }
	}