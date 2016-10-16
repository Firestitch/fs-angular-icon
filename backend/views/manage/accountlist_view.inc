<?
	class VIEW_MANAGE_ACCOUNTLIST extends VIEW {

		protected $_account_cmodels = array();

		function __construct() {
			$this->set_route("manage","accountlist");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
			$this->type_blank();
		}

		function init() {

		if(SERVER_UTIL::is_post())
				$this->load();
			$this->set_var("accounts",$this->_account_cmodels);
		}

		function load() {

			$page_index	= $this->request("page_index") ? $this->request("page_index") : 0;
			$page_limit	= $this->request("page_limit") ? $this->request("page_limit") : 25;

			$search		= (array)$this->request("search");
			$state 		= get_value($search,"state") ? get_value($search,"state") : DBQ_ACCOUNT::STATE_ACTIVE;

			$account_hmodel = HMODEL_ACCOUNT::create()
									->where("root_account_id","IS",null)
									->set_state($state);

			if($keyword=get_value($search,"keyword")) {
				$account_hmodel->where("name","=",$keyword,"OR","searchgroup");
				$account_hmodel->where("name","LIKE","%".$keyword."%","OR","searchgroup");
			}

			$account_hmodel->order("priority");
			$record_count = $account_hmodel->count();

			$account_hmodel->set_limit($page_limit,$page_limit * $page_index,$record_count);

			$this->_account_cmodels = $account_hmodel->gets();

			$this->set_view("paging",APPLICATION::get_base_view_instance("components","paging"));
			$this->get_view("paging")->populate($page_index,$page_limit,$record_count,'$("#account-list").trigger("load")');

			$this->set_var("search",$search);


		}
	}



