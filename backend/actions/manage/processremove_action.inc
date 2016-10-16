<?
	class ACTION_MANAGE_PROCESSREMOVE extends ACTION_JSON {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			if($process_id=$this->post("pid")) {

				if($process_cmodel=HMODEL_PROCESS::get($process_id))
					$has_success = $process_cmodel->delete();

				$this->success($has_success);
			}

			if(!$this->has_success())
				$this->error("There was a problem trying to remove the process");
		}
	}