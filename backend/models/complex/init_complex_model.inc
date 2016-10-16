<?
	class CMODEL_INIT extends BCMODEL_INIT {

		function init_settings() {

			CMODEL_SETTING_INITIALIZE::create()->init();

			return $this;
		}

/*
function init_roles() {

			foreach(SECURITY_MANAGER::get_role_list() as $role=>$name) {
				$exists = DBQ_ROLE::create()
							->where("role","=",$role)
							->exists();

				if(!$exists) {
					CMODEL_ROLE::create()
						->set_role($role)
						->set_name($name)
						->set_level("system")
						->save();
				}
			}

			return $this;
		}
*/

		function init_messages() {

			CMODEL_MESSAGE::create()->init_messages();

			return $this;
		}
	}

