<?
	class VIEW_MANAGE_ACCOUNTACCOUNTUSERS extends VIEW {

		function __construct() {
			$this->set_route("manage","accountaccountusers");

			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
			$this->type_blank();
			$this->set_view("account_users",APPLICATION::get_view("manage","accountaccountuserlist"));
		}

		function init() {

			$account_id = $this->get("aid");

			$this->set_var("account_id",$account_id);
			$this->set_var("search",array());
		}
		function load($account_id) { $this->get_view("account_users")->load($account_id); }
	}