<?
	class VIEW_MANAGE_ACCOUNTACCOUNTLIST extends VIEW {

		protected $_account_cmodel = null;

		function __construct() {
			$this->set_route("manage","accountaccountlist");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
			$this->type_blank();
		}

		function init() {

			if($account_id=$this->request("aid"))
				$this->load($account_id);

			$this->set_var("account",$this->_account_cmodel);
		}

		function load($account_id) {

			$search		= is_array($this->request("search")) ? $this->request("search") : array();
			$state 		= get_value($search,"state") ? get_value($search,"state") : DBQ_ACCOUNT::STATE_ACTIVE;

			$account_cmodel = HMODEL_ACCOUNT::create()
									->load_account_users(HMODEL_ACCOUNT_USER::get_default_handler()->load_users())
									->get($account_id);

			if($account_cmodel) {

				$account_hmodel = HMODEL_ACCOUNT::create();

				if($state!="all")
					$account_hmodel->set_state($state);

				if($keyword=get_value($search,"keyword")) {
					$account_hmodel->where("name","=",$keyword,"OR","searchgroup");
					$account_hmodel->where("name","LIKE","%".$keyword."%","OR","searchgroup");
				}


				$account_hmodel->load_account_users(HMODEL_ACCOUNT_USER::get_default_handler()->load_users());

				$account_cmodel->populate_accounts($account_hmodel);

				$this->_account_cmodel = CMODEL_ACCOUNT::create()
												->set_accounts(array($account_cmodel));
			}

			$this->set_var("search",$search);
		}
	}