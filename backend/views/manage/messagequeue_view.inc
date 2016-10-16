<?
	class VIEW_MANAGE_MESSAGEQUEUE extends BASE_VIEW_MANAGE_MESSAGEQUEUE {

		function __construct() {
			$this->set_form("/manage/domessagequeue");
			$this->set_route("manage","messagequeue");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);

			parent::__construct();
		}
	}
