<?

	class ACTION_MANAGE_MAINTENANCE extends ACTION {

		function __construct() {
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			if($this->request("cmd_theme_preview")) {


				$layout_page_site_template_cmodel = new DBQ_LAYOUT_PAGE_SITE_TEMPLATE();
				$has_success = $layout_page_site_template_cmodel->delete();

				if($has_success)
					APPLICATION::add_notify_message("Successfully queued the re-generation of theme preview images");
				else
					APPLICATION::add_error_messages("There was a problem trying to queue the re-generation of theme preview images");

			}

			if($this->request("cmd_layout_preview")) {

				$has_success = true;

				$layout_page_hmodel = new HMODEL_LAYOUT_PAGE();
				foreach($layout_page_hmodel->get_layout_pages() as $layout_page_cmodel) {

					if(is_file($layout_page_cmodel->get_preview_large_file())) {
						$has_success &= $layout_page_cmodel->commit_preview($layout_page_cmodel->get_preview_large_file());
						APPLICATION::inherit_messages($layout_page_cmodel);
					}
				}

				if($has_success)
					APPLICATION::add_notify_message("Successfully regenerated layout preview images");
				else
					APPLICATION::add_error_messages("There was a problem trying to regenerate layout preview images");
			}

			if($this->request("cmd_theme_preview")) {

				$has_success = true;

				$site_template_hmodel = new HMODEL_SITE_TEMPLATE();
				foreach($site_template_hmodel->get_site_templates() as $site_template_cmodel) {

					if(is_file($site_template_cmodel->get_preview_large_file())) {
						$has_success &= $site_template_cmodel->commit_preview($site_template_cmodel->get_preview_large_file());
						APPLICATION::inherit_messages($site_template_cmodel);
					}
				}

				if($has_success)
					APPLICATION::add_notify_message("Successfully regenerated theme preview images");
				else
					APPLICATION::add_error_messages("There was a problem trying to regenerate theme preview images");
			}




			$view = APPLICATION::get_view_instance("manage","maintenance");
			$this->set_view($view);

		}
	}