<?
	class ACTION_MANAGE_APILOGREMOVE extends ACTION_JSON {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			$api_log_cmodel = HMODEL_API_LOG::get($this->post("alid"));

			if(!$api_log_cmodel)
				throw new Exception("Failed to load api log");

			$api_log_cmodel->delete();

			$this->success(true);
		}
	}