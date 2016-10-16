<?

	class VIEW_MANAGE_ROLES extends VIEW {

		function __construct() {
			$this->set_form("/manage/roles");
			$this->set_title("Roles");
			$this->set_route("manage","roles");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function init() {

			$page_index	= is_numeric($this->request("page_index")) ? $this->request("page_index") : 0;
			$page_limit	= is_numeric($this->request("page_limit")) ? $this->request("page_limit") : 15;

			$role_handler = new HMODEL_ROLE();
			$record_count = $role_handler->get_count();

			if(($page_index * $page_limit)>=$record_count)
				$page_index = 0;

			$role_handler->set_limit($page_limit,$page_limit * $page_index);

			$page_count = ceil($record_count/$page_limit);

			$role_cmodels = $role_handler->get_roles();

			$this->set_view("paging",APPLICATION::get_base_view_instance("components","paging"));
			$this->get_view("paging")->set_page_index($page_index);
			$this->get_view("paging")->set_page_count($page_count);
			$this->get_view("paging")->set_page_limit($page_limit);

			$this->set_var("roles",$role_cmodels);
		}
	}