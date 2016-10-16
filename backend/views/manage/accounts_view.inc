<?
	class VIEW_MANAGE_ACCOUNTS extends VIEW {

		function __construct() {
			$this->set_route("manage","accounts");
			$this->set_form("javascript:;",false,"account-form");

			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
			$this->set_view("accounts",APPLICATION::get_view("manage","accountlist"));
		}

		function init() {
			$this->load();
			$this->set_var("search",array());
		}
		function load() { $this->get_view("accounts")->load(); }
	}