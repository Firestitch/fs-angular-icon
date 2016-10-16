<?
	class VIEW_MANAGE_CONTENT extends BASE_VIEW_MANAGE_CONTENT {

		function __construct() {
			parent::__construct();

			$this->set_form("/manage/docontent");
			$this->set_title("Content");
			$this->set_route("manage","content");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);

			$this->set_cancel_url("/manage/contents/");
		}
	}