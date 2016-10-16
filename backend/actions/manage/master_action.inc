<?

	class ACTION_MANAGE_MASTER extends ACTION {

		function __construct() {

			if(!SYSTEM_MANAGER::is_system_mode_debug())
				$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			$version = $this->request("version");

			if($this->request("cron") || $this->request("0")=="cron") {

				CMODEL_CRON::create()->run();

				APPLICATION::add_notify_message("Successfully ran the cron");
			}

			if($this->request("init") || $this->request("0")=="init") {

				$init_cmodel = new CMODEL_INIT();
				$has_success = $init_cmodel->init();

				if($has_success)
					APPLICATION::add_notify_message("Successfully init'ed the system");
				else
					APPLICATION::add_error_message("Failed to init the system");

				APPLICATION::inherit_messages($init_cmodel);
			}

			if($this->request("upgrade") || $this->request("0")=="upgrade") {

				$upgrade_cmodel = new CMODEL_UPGRADE();

				$version = $version ? $version : $upgrade_cmodel->get_current_version();

				$has_success = $upgrade_cmodel->process($version);

				if($has_success)
					APPLICATION::add_notify_message("Successfully upgraded instance");

				APPLICATION::inherit_messages($upgrade_cmodel);
			}

			if($this->request("test") || $this->request("0")=="test") {


			}

			$view = APPLICATION::get_view_instance("manage","master");
			$view->set_version($version);
			$this->set_view($view);
		}
	}