<?
	class VIEW_API_USERS extends VIEW_API_BASE {

		function users($user_id=null,$action=null) {

			if($this->is_get()) {

				$user_hmodel = HMODEL_USER::create();

				if($user_id)
					$user_hmodel->set_user_id($user_id);

				$this->handler($user_hmodel);

				$user_cmodels = $user_hmodel->gets();

				$users = array();
				foreach($user_cmodels as $user_cmodel) {

					$user = $user_cmodel->arry();

					$users[] = $user;
				}

				if($user_id)
					$this->data("user",get_value($users,0));
				else
					$this->data("users",$users);
			}
		}
	}