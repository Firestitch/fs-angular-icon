<?
	class ACTION_MANAGE_APILOG extends ACTION_JSON {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			$api_log_id	= $this->post("alid");
			$form			= $this->post("form");

			$api_log_cmodel = ($api_log_cmodel=HMODEL_API_LOG::get($api_log_id)) ? $api_log_cmodel : CMODEL_API_LOG::create();
			$api_log_cmodel->populate($form);

			try {

				$api_log_cmodel->save();

				if(!$api_log_id) {
					APPLICATION::add_persistent_notify("Successfully added the api log");
					$this->redirect($api_log_cmodel->get_manage_url());
				}

				$this
					->data("alid",$api_log_cmodel->get_api_log_id())
					->success();

			} catch(Exception $e) {
				$this->error($e);
			}

			if(!$this->has_success() && !$this->has_error())
				$this->error("There was a problem trying to save the api log");
		}
	}


