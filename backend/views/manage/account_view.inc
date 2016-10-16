<?
	class VIEW_MANAGE_ACCOUNT extends VIEW {

		protected $_account_cmodel = null;

		function __construct() {
			$this->set_route("manage","account");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);

			$this->_account_cmodel = new CMODEL_ACCOUNT();
		}

		function init() {

			if($account_id=$this->get("aid"))
				$this->load($account_id);

			$this->add_js_app("nestedSortable/jquery.mjs.nestedSortable.js");


			/*
			$root_account_list = ARRAY_UTIL::listing(HMODEL_ROOT_ACCOUNT::create()
								->order("root_account_id")
								->gets(),"get_root_account_id","get_root_account_id");

			$parent_account_list = ARRAY_UTIL::listing(HMODEL_PARENT_ACCOUNT::create()
								->order("parent_account_id")
								->gets(),"get_parent_account_id","get_parent_account_id");
			*/

			$this->set_var("account", $this->_account_cmodel);
			//$this->set_var("root_account_list",$root_account_list);
			//$this->set_var("parent_account_list",$parent_account_list);
		}

		function load($account_id) {

			$account_cmodel = HMODEL_ACCOUNT::create()->get($account_id);

			if($account_cmodel)
				$this->_account_cmodel = $account_cmodel;
		}

		function set_account($account_cmodel) { $this->_account_cmodel = $account_cmodel; }
	}