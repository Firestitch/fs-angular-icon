<?
	class ACTION_USER_AVATAR extends ACTION_JSON {

		function process() {

			$user_cmodel = USER_SESSION::instance()->get_user();

			if($user_cmodel) {

				$upload_util = UPLOAD_UTIL::create("file");

				if($upload_util->is_file_upload_exist()) {

					$temp_cmodel = BCMODEL_TEMP::create();

					$has_success = $upload_util
										->set_store_path($temp_cmodel->dir())
										->set_valid_extensions(array("jpg","jpeg","png"))
										->upload();

					if($has_success) {

						try {
							$has_success = $user_cmodel->commit_avatar($upload_util->get_store_file());
							$this->success($has_success);

							$this->data("url",$user_cmodel->get_avatar_image()->url("small"));
						} catch(Exception $e) {
							$this->error($e);
						}
					} else
						$this->error($upload_util->get_error_message());

					$temp_cmodel->cleanup();
				}
			}

			if(!$this->has_success())
				$this->error("There was a problem trying to upload the image");
		}
	}


