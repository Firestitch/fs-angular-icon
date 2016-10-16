<?
	class VIEW_MANAGE_APILOGS extends VIEW {

		function __construct() {
			parent::__construct("manage","apilogs",[],"api-log-form")
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);

			$this->set_view("api_logs",APPLICATION::get_view("manage","apiloglist"));
		}

		function init() {
			$this->get_web_asset_manager()->add_daterangepicker();
		}

		function load() { $this->get_view("api_logs")->load(); }
	}