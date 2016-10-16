<?
	class VIEW_MANAGE_CONTENTBROWSE extends VIEW {

		function __construct() {
			$this->set_route("manage","contentbrowse");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
			$this->type_popup();
		}

		function init() {

			$this->set_var("process_url","/manage/docontentbrowse");
			$this->set_var("base_path",MODEL_PATH::get_content_url());
		}
	}
