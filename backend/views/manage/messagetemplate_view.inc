<?
	class VIEW_MANAGE_MESSAGETEMPLATE extends BASE_VIEW_MANAGE_MESSAGETEMPLATE {

		function __construct() {
			parent::__construct();

			$this->set_form("/manage/doemailtemplate");
			$this->set_route("manage","messagetemplate");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}
	}