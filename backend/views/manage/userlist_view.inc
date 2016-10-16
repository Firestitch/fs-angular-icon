<?
	class VIEW_MANAGE_USERLIST extends VIEW {

		function __construct() {
			$this->set_route("manage","userlist");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
			$this->type_blank();
		}

		function init() {

			$page_index	= is_numeric($this->request("page_index")) ? $this->request("page_index") : 0;
			$page_limit	= is_numeric($this->request("page_limit")) ? $this->request("page_limit") : 15;
			$search		= is_array($this->request("search")) ? $this->request("search") : array();
			$state 		= value($search,"state") ? get_value($search,"state") : CMODEL_USER::STATE_ACTIVE;

			$user_hmodel = new HMODEL_USER();
			$user_hmodel->set_state($state);

			if($keyword=value($search,"keyword"))
				$user_hmodel
					->where("user_id","=",$keyword,"OR","searchgroup")
					->where("first_name","=",$keyword,"OR","searchgroup")
					->where("last_name","=",$keyword,"OR","searchgroup")
					->where("email","=",$keyword,"OR","searchgroup");

			$record_count = $user_hmodel->get_count();

			if(($page_index * $page_limit)>=$record_count)
				$page_index = 0;

			$user_hmodel->set_limit($page_limit,$page_limit * $page_index);

			$page_count = ceil($record_count/$page_limit);

			$user_cmodels = $user_hmodel->get_users();

			$this->set_view("paging",APPLICATION::get_base_view_instance("components","paging"));
			$this->get_view("paging")->set_page_index($page_index);
			$this->get_view("paging")->set_page_count($page_count);
			$this->get_view("paging")->set_page_limit($page_limit);
			$this->get_view("paging")->set_record_count($record_count);
			$this->get_view("paging")->set_submit_paging_javascript('$("#user-list").trigger("load")');

			$this->set_var("users",$user_cmodels);
			$this->set_var("search",$search);

		}
	}



