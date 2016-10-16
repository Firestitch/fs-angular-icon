<?
	class VIEW_MANAGE_ACCOUNTACCOUNTUSERLIST extends VIEW {

		protected $_account_user_cmodels = array();

		function __construct() {
			$this->set_route("manage","accountaccountuserlist");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
			$this->type_blank();
		}

		function init() {

			if($account_id=$this->request("aid"))
				$this->load($account_id);
			$this->set_var("account_users",$this->_account_user_cmodels);
		}

		function load($account_id) {

			$search		= is_array($this->request("search")) ? $this->request("search") : array();
			$state 		= get_value($search,"state") ? get_value($search,"state") : DBQ_ACCOUNT_USER::STATE_ACTIVE;

			$account_user_hmodel = HMODEL_ACCOUNT_USER::create();
			$account_user_hmodel->set_state($state);

			if($keyword=get_value($search,"keyword")) {
				$account_user_hmodel->where("account_user_id","=",$keyword,"OR","searchgroup");
			}

			$account_user_hmodel->where("account_id","=",$account_id);

			$this->_account_user_cmodels = $account_user_hmodel->gets();

			$this->set_var("search",$search);
		}
	}



