<?
	class ACTION_MANAGE_ACCOUNTSITEREMOVE extends ACTION_JSON {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			if($site_id=$this->post("sid")) {

				if($site_cmodel=HMODEL_SITE::get($site_id))
					$has_success = $site_cmodel->delete();

				$this->success($has_success);
			}

			if(!$this->has_success())
				$this->error("There was a problem trying to remove the site");
		}
	}