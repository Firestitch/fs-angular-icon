<?
	class VIEW_MANAGE_PROCESSES extends VIEW {

		function __construct() {
			$this->set_route("manage","processes");
			$this->set_form("javascript:;",false,"process-form");

			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
			$this->set_view("processes",APPLICATION::get_view("manage","processlist"));
		}

		function init() {
			$this->load();
		}
		function load() { $this->get_view("processes")->load(); }
	}