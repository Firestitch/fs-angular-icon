<?
	class ACTION_MANAGE_PROCESS extends ACTION_JSON {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			$process_id	= $this->post("pid");
			$form		= $this->post("form");

			$process_cmodel = ($process_cmodel=HMODEL_PROCESS::get($process_id)) ? $process_cmodel : new CMODEL_PROCESS();
			$process_cmodel->populate($form);


			if($this->is_form_valid($process_cmodel)) {
				$has_success = $process_cmodel->save();

				if($has_success) {

					$this->data("pid",$process_cmodel->get_process_id());

					if(!$process_id) {
						APPLICATION::add_persistent_notify("Successfully added the process");
						$this->redirect($process_cmodel->get_manage_url());
					}
				}

				$this->success($has_success);
			}

			if(!$this->has_success() && !$this->has_error())
				$this->error("There was a problem trying to save the process");
		}

		function is_form_valid($process_cmodel) {
			return !$this->has_error();
		}
	}


