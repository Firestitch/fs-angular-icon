<?
	class VIEW_MANAGE_INDEXINSPECTLIST extends VIEW {

		protected $_index_cmodels = array();

		function __construct() {
			parent::__construct("manage","indexinspectlist",[]);

			$this->type_blank();
			$this->set_view("paging",APPLICATION::get_base_view_instance("components","paging"));
		}

		function init() {

		if(SERVER_UTIL::is_post())
				$this->load();

			$this->set_var("indexes",$this->_index_cmodels);
		}

		function load() {
			$page_index	= $this->request("page_index") ? $this->request("page_index") : 0;
			$page_limit	= $this->request("page_limit") ? $this->request("page_limit") : 25;

			$search		= (array)$this->request("search");

			$index_hmodel = HMODEL_INDEX::create(false);

			$index_hmodel->set_state(value($search,"state")!==null ? value($search,"state") : CMODEL_INDEX::STATE_ACTIVE);

			if($type=value($search,"type"))
				$index_hmodel->where("type","=",$type);

			if($keyword=value($search,"keyword")) {
	        	$index_hmodel
		            ->group(DB_GROUP::create()
						->where("MATCH(indexes.primary_keyword)","AGAINST","'*".$keyword."*' IN BOOLEAN MODE","OR",false,false,false)
						->where("MATCH(indexes.secondary_keyword)","AGAINST","'*".$keyword."*' IN BOOLEAN MODE","OR",false,false,false)
                    )
					->data("((MATCH(indexes.primary_keyword) AGAINST ('*".$keyword."*' IN BOOLEAN MODE))*2) + (MATCH(indexes.secondary_keyword) AGAINST ('*".$keyword."*' IN BOOLEAN MODE))","index_weight")
					->order_by("index_weight","DESC");
					;


			}


			$record_count = $index_hmodel->count();

			$index_hmodel->set_limit($page_limit,$page_limit * $page_index,$record_count);

			$this->_index_cmodels = $index_hmodel->gets();

			$this->get_view("paging")->populate($page_index,$page_limit,$record_count,'$("#index-list").trigger("load")');
		}
	}



