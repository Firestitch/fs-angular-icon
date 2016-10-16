<?
	class VIEW_MANAGE_CRONS extends BASE_VIEW_MANAGE_CRONS {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}
	}