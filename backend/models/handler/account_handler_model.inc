<?
	class HMODEL_ACCOUNT extends MODEL_HANDLER {
	
		protected $_select_fields = array("accounts.*");
		
		protected $_parent_account_hmodel = null;

		protected $_account_hmodel = null;

		protected $_account_user_hmodel = null;

		function get_dbq() {
			$account_dbq = new DBQ_ACCOUNT();
			$this->apply_constraints($account_dbq);
			return $account_dbq;
		}
		
		function gets() {
			$account_dbq = $this->get_dbq();
			$accounts = $account_dbq->select($this->_select_fields);
			$account_cmodels = array();
			
			foreach($accounts as $account) {
				$account_cmodel = new CMODEL_ACCOUNT();
				$account_cmodel->populate($account,true,false);
				$this->apply_properties($account_cmodel,$account);
				$account_cmodels[] = $account_cmodel;
			}
			
			if(!$account_cmodels)
				return array();
			
			
			if($this->_parent_account_hmodel) {
				$account_ids = array_unique(MISC_UTIL::get_list_from_object_function($account_cmodels, "get_parent_account_id"));
				$parent_account_hmodel = $this->_parent_account_hmodel;
				$parent_account_hmodel->add_filter("account_id","IN",$account_ids);
				$parent_account_cmodels = $parent_account_hmodel->gets();

				foreach($account_cmodels as $account_cmodel)
					foreach($parent_account_cmodels as $parent_account_cmodel)
						if($account_cmodel->get_parent_account_id()==$parent_account_cmodel->get_account_id())
							$account_cmodel->set_parent_account($parent_account_cmodel);
			}

			
			if($this->_account_hmodel) {
				$account_ids = array_unique(MISC_UTIL::get_list_from_object_function($account_cmodels, "get_account_id"));
				$account_hmodel = $this->_account_hmodel;
				$account_hmodel->add_filter("account_id","IN",$account_ids);
				$account_cmodels = $account_hmodel->gets();

				foreach($account_cmodels as $account_cmodel) {
					$accounts = array();
					foreach($account_cmodels as $index=>$account_cmodel) {
						if($account_cmodel->get_account_id()==$account_cmodel->get_account_id()) {
							$accounts[] = $account_cmodel;
						}
					}
					$account_cmodel->set_accounts($accounts);
				}
			}

			
			if($this->_account_user_hmodel) {
				$account_ids = array_unique(MISC_UTIL::get_list_from_object_function($account_cmodels, "get_account_id"));
				$account_user_hmodel = $this->_account_user_hmodel;
				$account_user_hmodel->add_filter("account_users.account_id","IN",$account_ids);
				$account_user_cmodels = $account_user_hmodel->gets();

				foreach($account_cmodels as $account_cmodel) {
					$account_users = array();
					foreach($account_user_cmodels as $index=>$account_user_cmodel) {
						if($account_cmodel->get_account_id()==$account_user_cmodel->get_account_id()) {
							$account_users[] = $account_user_cmodel;
						}
					}
					$account_cmodel->set_account_users($account_users);
				}
			}

			return $account_cmodels;
		}
		
		function filter_state_active()			{ return $this->set_state(DBQ_ACCOUNT::STATE_ACTIVE); }
		function load_parent_accounts($parent_account_hmodel=null) {
			$this->_parent_account_hmodel = $parent_account_hmodel ? $parent_account_hmodel : new HMODEL_ACCOUNT();
			return $this;
		}

		function load_accounts($account_hmodel=null) {
			$this->_account_hmodel = $account_hmodel ? $account_hmodel : new HMODEL_ACCOUNT();
			return $this;
		}

		function load_account_users($account_user_hmodel=null) {
			$this->_account_user_hmodel = $account_user_hmodel ? $account_user_hmodel : HMODEL_ACCOUNT_USER::get_default_handler();
			return $this;
		}

		function get_count($field=null) 		{ return $this->get_dbq()->count($field); }
		function exists($field=null)			{ return $this->get_dbq()->exists($field); }
		function set_account_ids($values)		{ return $this->add_filter("accounts.account_id","IN",$values); }
		function set_account_id($value)			{ return $this->add_filter("accounts.account_id","=",$value); }
		function set_parent_account_id($value)	{ return $this->add_filter("accounts.parent_account_id","=",$value); }
		function set_parent_account_ids($values)	{ return $this->add_filter("accounts.parent_account_id","IN",$values); }
		function set_brand_id($value)	{ return $this->add_filter("accounts.brand_id","=",$value); }
		function set_brand_ids($values)	{ return $this->add_filter("accounts.brand_id","IN",$values); }
		function set_state($value)		{ return $this->add_filter("accounts.state","=",$value); }
		function set_states($values)	{ return $this->add_filter("accounts.state","IN",$values); }
		

	}
	