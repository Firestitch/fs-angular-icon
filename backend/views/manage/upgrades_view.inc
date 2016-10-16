<?

	class VIEW_MANAGE_UPGRADES extends BASE_VIEW_MANAGE_UPGRADES {

		function __construct() {
			$this->set_form("/manage/upgrades/");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
			parent::__construct();
		}
	}