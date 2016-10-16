<?
	class ACTION_MANAGE_UPGRADE extends ACTION {

		function __construct() {
			if(!SYSTEM_MANAGER::is_system_mode_debug())
				$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			if(preg_match("/(^\d+_\d+_\d+)/",FILE_UTIL::get(DIR_APPLICATION."upgrade/version"),$matches)) {

				$version = value($matches,1);

				$upgrade_cmodel = CMODEL_UPGRADE::create();

				if($upgrade_cmodel->process($version))
					echo "Succssfully upgrade to ".$version;

				foreach($upgrade_cmodel->get_error_messages() as $error_message)
					echo $error_message."\n\n";
			} else
				echo "Invalid version";
		}
	}