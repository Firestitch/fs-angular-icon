<?
	class VIEW_API_ME extends VIEW_API_BASE {

		public function skip_group() 			{ return true; }

		public function me($user_id=null,$action=null) {

			if($this->is_get()) {

				$user_cmodel = $this->get_api_token()->get_user();

				if(!$user_cmodel)
					throw new Exception("Failed to update the profile");

				$user = $user_cmodel->arry();

				$this->data("user",$user);


			} elseif($this->is_put()) {

				$user_cmodel = $this->get_api_token()->get_user();

				if(!$user_cmodel)
					throw new Exception("Failed to update the profile");

				$user_cmodel
					->start_diff()
					->fill($this->post(), ["first_name","last_name","email","company","phone","password"])
					->validate()
					->save()
					->audit($this->get_api_token(), CMODEL_AUDIT::ACTION_CHANGE);

				$this->data("user", $user_cmodel->arry());


			} elseif($this->is_post()) {


			} elseif($this->is_delete()) {

				$user_cmodel = $this->get_api_token()->get_user();

				if(!$user_cmodel)
					throw new Exception("Failed to deactivate the user");

				$user_cmodel
					->start_diff()
					->delete()
					->audit($this->get_api_token(), CMODEL_AUDIT::ACTION_CHANGE);
			}
		}




		function avatar($user_id=null) {
			$user_id = $this->get_api_token()->get_user_id();

			$user_cmodel = HMODEL_USER::create()->get($user_id);

			if(!$user_cmodel)
				throw new Exception("No user");

			$temp_cmodel = CMODEL_TEMP::create("jpg");

			UPLOAD_UTIL::create("file",$temp_cmodel->dir(),array("","jpg","png","jpeg"))->set_store_filename($temp_cmodel->filename())->upload();

			$user_cmodel->commit_avatar($temp_cmodel->file());

			$temp_cmodel->cleanup();

			$this->data("user",$user_cmodel->arry(true));
		}



		public function wsdl() {
			return array(	"endpoints"=>array(
													array(	"path"=>array("me"),
														"description"=>"Get the profile of the logged in user",
														"method"=>"get",
														"parms"=>array(),
														"response"=>array("user"),
														),
													array(	"path"=>array("me"),
														"description"=>"Upload the profile of the logged in user",
														"method"=>"put",
														"parms"=>array("first_name","last_name","email","company","password","phone"),
														"response"=>array("user"),
														),
													array(	"path"=>array("me"),
														"description"=>"Deactivates the user's account",
														"method"=>"delete",
														"response"=>array(),
														),
													array(	"path"=>array("me/avatar"),
														"description"=>"Upload avatar for logged in user",
														"method"=>"post",
														"parms"=>array("file"),
														"response"=>array("user"),
														),
				));
		}
	}


