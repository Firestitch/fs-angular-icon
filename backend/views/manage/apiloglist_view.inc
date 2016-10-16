<?
	class VIEW_MANAGE_APILOGLIST extends VIEW {

		protected $_api_log_cmodels = array();

		function __construct() {
			parent::__construct("manage","apiloglist")
				->set_permission(CMODEL_USER::PERMISSION_BACKEND)
				->type_blank();

			$this->set_view("paging",APPLICATION::get_base_view_instance("components","paging"));
		}

		function init() {

		if(SERVER_UTIL::is_post())
				$this->load();

			$this->set_var("api_logs",$this->_api_log_cmodels);
		}

		function load() {

			$page_index	= $this->request("page_index") ? $this->request("page_index") : 0;
			$page_limit	= $this->request("page_limit") ? $this->request("page_limit") : 25;

			$search		= (array)$this->request("search");
			$state 		= value($search,"state")!==null ? value($search,"state") : "";

			$api_log_hmodel = HMODEL_API_LOG::create(false);

			if($state)
				$api_log_hmodel->set_state($state);

			if($start=value($search,"start_date"))
				$api_log_hmodel->where("create_date",">=",DB::get_date($start));

			if($end=value($search,"end_date"))
				$api_log_hmodel->where("create_date","<=",CMODEL_TIME::create($end)->add_day()->db());

			if($direction=value($search,"direction"))
				$api_log_hmodel->where("direction","=",$direction);

			if($keyword=value($search,"keyword"))
				$api_log_hmodel
					->where("url","LIKE","%".$keyword."%","OR","searchgroup")
					->where("request","LIKE","%".$keyword."%","OR","searchgroup")
					->where("response","LIKE","%".$keyword."%","OR","searchgroup")
					->where("message","LIKE","%".$keyword."%","OR","searchgroup");

			$record_count = $api_log_hmodel->count();

			$api_log_hmodel->set_limit($page_limit,$page_limit * $page_index,$record_count);

			$this->_api_log_cmodels = $api_log_hmodel->gets();

			$this->get_view("paging")->populate($page_index,$page_limit,$record_count,'$("#api-log-list").trigger("load")');
		}
	}



