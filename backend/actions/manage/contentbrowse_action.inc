<?
	class ACTION_MANAGE_CONTENTBROWSE extends BASE_ACTION_COMPONENTS_BROWSE {

		public function __construct() {
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
			parent::__construct();
		}

		public function process() {

			$file_browser_cmodel = $this->get_file_browser();
			$file_browser_cmodel->set_root_directory(MODEL_PATH::get_content_dir());

			parent::process();
		}
	}