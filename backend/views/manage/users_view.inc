<?
	class VIEW_MANAGE_USERS extends VIEW {

		function __construct() {
			$this->set_route("manage","users");
			$this->set_form("javascript:;",false,"user-form");

			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
			$this->set_view("users",APPLICATION::get_view_instance("manage","userlist"));
		}

		function init() {


			$this->set_var("search",array());
		}
	}