<?
	class VIEW_MANAGE_PROCESSLIST extends VIEW {

		protected $_process_cmodels = array();

		function __construct() {
			$this->set_route("manage","processlist");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
			$this->type_blank();
			$this->set_view("paging",APPLICATION::get_base_view_instance("components","paging"));
		}

		function init() {

		if(SERVER_UTIL::is_post())
				$this->load();
			$this->set_var("processes",$this->_process_cmodels);
		}

		function load() {
			$registry 	= REGISTRY::get_instance();
			$page_index	= $registry->request("page_index") ? $registry->request("page_index") : 0;
			$page_limit	= $registry->request("page_limit") ? $registry->request("page_limit") : 25;

			$search		= (array)$registry->request("search");
			$state 		= get_value($search,"state") ? get_value($search,"state") : null;

			$process_hmodel = HMODEL_PROCESS::create()->order("process_id","DESC");


			if($state)
				$process_hmodel->set_state($state);

			if($keyword=get_value($search,"keyword")) {
				$process_hmodel->where("name","=",$keyword,"OR","searchgroup");
				$process_hmodel->where("name","LIKE","%".$keyword."%","OR","searchgroup");
				$process_hmodel->where("description","LIKE","%".$keyword."%","OR","searchgroup");
			}

			$record_count = $process_hmodel->count();

			$process_hmodel->set_limit($page_limit,$page_limit * $page_index,$record_count);

			$this->_process_cmodels = $process_hmodel->gets();

			$this->get_view("paging")->populate($page_index,$page_limit,$record_count,'$("#process-list").trigger("load")');
		}
	}



