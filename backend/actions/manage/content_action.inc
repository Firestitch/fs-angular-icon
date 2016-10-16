<?
	APPLICATION::include_base_action("manage","content");

	class ACTION_MANAGE_CONTENT extends BASE_ACTION_MANAGE_CONTENT {

		function __construct() {
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			$view = null;
			$has_success = parent::process();

			if($this->is_update() || $this->is_update_close()) {

				if($has_success) {
					APPLICATION::add_notify_message("Saved Changes");

					if($this->is_update_close())
						$view = APPLICATION::get_view_instance("manage","contents");
				} else
					APPLICATION::add_error_message("There was a problem trying to save the content");
			}

			if(!$view) {
				$view = APPLICATION::get_view_instance("manage","content");
				$view->set_site_content($this->get_site_content());
				$view->set_mode($this->get_mode());
			}

			$this->set_view($view);
		}
	}
