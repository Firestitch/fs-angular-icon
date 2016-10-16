<?
	class VIEW_MANAGE_ACCOUNTACCOUNTS extends VIEW {

		function __construct() {
			$this->set_route("manage","accountaccounts");
			$this->set_form("javascript:;",false,"account-form");

			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
			$this->type_blank();
			$this->set_view("accounts",APPLICATION::get_view("manage","accountaccountlist"));
		}

		function init() {

			$root_account_id = $this->get("raid");

			$this->set_var("root_account_id",$root_account_id);
			$this->set_var("search",array("state"=>DBQ_ACCOUNT::STATE_ACTIVE));
		}

		function load($account_id) { $this->get_view("accounts")->load($account_id); }
	}