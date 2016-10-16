<?
	class VIEW_MANAGE_MESSAGEQUEUES extends BASE_VIEW_MANAGE_MESSAGEQUEUES {

		function __construct() {
			$this->set_form("/manage/messagequeues/");
			$this->set_route("manage","messagequeues");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);

			parent::__construct();
		}
	}