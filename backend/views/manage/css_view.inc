<?
	class VIEW_MANAGE_CSS extends VIEW {

		function __construct() {
			$this->set_route("manage","css");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function init() {

			BASE_VIEW_COMPONENTS_CODE_EDITOR::web_asset_manager_include($this->get_web_asset_manager());

			$css = FILE_UTIL::get(MODEL_PATH::get_content_dir()."site.css");

			$this->set_var("css",$css);
		}
	}