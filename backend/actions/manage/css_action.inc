<?
	class ACTION_MANAGE_CSS extends ACTION_JSON {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			$css			= $this->post("content");

			try {

				FILE_UTIL::mkdir(MODEL_PATH::get_content_dir());
				$this->success(FILE_UTIL::put(MODEL_PATH::get_content_dir()."site.css",$css));
			} catch(Exception $e) {
				$this->error($e);
			}

			if(!$this->has_success() && !$this->has_error())
				$this->error("There was a problem trying to save the css");
		}
	}


