<?
	

	class VIEW_APPLICATION_HEADER extends VIEW {

		function __construct(){
			$this->set_route("application","header");
			$this->disable_authorization();
		}

		function init() {
			$this->set_var("is_manage_section",APPLICATION::get_instance()->get_uri()->is_controller("manage"));
			$this->set_var("user",USER_SESSION::get()->get_user());
		}	
	}
