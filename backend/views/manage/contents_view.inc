<?
	class VIEW_MANAGE_CONTENTS extends BASE_VIEW_MANAGE_CONTENTS {

		function __construct() {
			parent::__construct();

			$this->set_form("/manage/contents");
			$this->set_title("Contents");
			$this->set_route("manage","contents");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);

		}

		function init() {

			$this->set_edit_url("/manage/content/%s/");
			$this->set_delete_url("/manage/docontentdelete/%s/");

			parent::init();
		}
	}