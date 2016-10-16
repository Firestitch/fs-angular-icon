<?
	class VIEW_MANAGE_ACCOUNTACCOUNT extends VIEW {

		protected $_account_cmodel = null;

		function __construct() {
			$this->set_route("manage","accountaccount");
			$this->set_form("javascript:;",false,"account-form");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
			$this->type_popup();

			$this->_account_cmodel = new CMODEL_ACCOUNT();
		}

		function init() {

			if(is_numeric($account_id=$this->get("aid")))
				$this->load($account_id);

			if(is_numeric($account_id=$this->get("raid")))
				$this->_account_cmodel->set_account_id($account_id);

			if(is_numeric($parent_account_id=$this->get("paid"))) {

				if($parent_account_cmodel=HMODEL_ACCOUNT::get($parent_account_id)) {
					$this->_account_cmodel->set_account_id($parent_account_cmodel->get_account_id());
					$this->_account_cmodel->set_parent_account_id($parent_account_id);
				}
			}

			$this->set_var("account", $this->_account_cmodel);
		}

		function load($account_id) {

			$account_hmodel = new HMODEL_ACCOUNT();
			$account_hmodel->set_account_id($account_id);
			$account_cmodel = get_value($account_hmodel->gets(),0);

			if($account_cmodel)
				$this->_account_cmodel = $account_cmodel;
		}

		function set_account($account_cmodel) { $this->_account_cmodel = $account_cmodel; }
	}