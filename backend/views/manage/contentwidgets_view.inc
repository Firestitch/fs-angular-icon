<?
	class VIEW_MANAGE_CONTENTWIDGETS extends BASE_VIEW_MANAGE_CONTENT_WIDGETS {

		function __construct() {
			parent::__construct();

			$this->set_form("/manage/contentwidgets");
			$this->set_route("manage","contentwidgets");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function init() {

			$this->set_edit_url("/manage/contentwidget/%s/");
			$this->set_delete_url("/manage/docontentwidgetdelete/%s/");

			parent::init();
		}
	}