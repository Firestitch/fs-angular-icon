<?
	class ACTION_MANAGE_USERAVATAR extends ACTION_JSON {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			$user_cmodel = HMODEL_USER::get($this->request("uid"));

			if(!$user_cmodel)
				throw new Exception("Invalid user");

			$temp_cmodel = CMODEL_TEMP::create();

			$upload_util = UPLOAD_UTIL::create("file",$temp_cmodel->dir(),array("jpg","jpeg","png"))->upload();

			$user_cmodel->commit_avatar($upload_util->get_store_file());
			$this->success(true);

			$this->data("url",$user_cmodel->get_avatar_image()->url("small"));

			$temp_cmodel->cleanup();

			if(!$this->has_success())
				$this->error("There was a problem trying to upload the image");
		}
	}


