<?
	class HMODEL_ACCOUNT_USER extends MODEL_HANDLER {
	
		protected $_select_fields = array("account_users.*");
		
		protected $_user_hmodel = null;

		function get_dbq() {
			$account_user_dbq = DBQ_ACCOUNT_USER::create();
			$this->apply_constraints($account_user_dbq);
			return $account_user_dbq;
		}
		
		function gets() {			
			$account_users = $this->get_dbq()->select($this->_select_fields);

			$account_user_cmodels = array();			
			foreach($account_users as $account_user) {
				$account_user_cmodel = new CMODEL_ACCOUNT_USER();
				$account_user_cmodel->populate($account_user,true,false);
				$this->apply_properties($account_user_cmodel,$account_user);
				$account_user_cmodels[] = $account_user_cmodel;
			}
			
			if(!$account_user_cmodels)
				return array();
			
			
			if($this->_user_hmodel) {
				$user_ids = array_unique(MISC_UTIL::get_list_from_object_function($account_user_cmodels, "get_user_id"));
				$user_hmodel = $this->_user_hmodel;
				$user_hmodel->add_filter("user_id","IN",$user_ids);
				$user_cmodels = $user_hmodel->gets();

				foreach($account_user_cmodels as $account_user_cmodel)
					foreach($user_cmodels as $user_cmodel)
						if($account_user_cmodel->get_user_id()==$user_cmodel->get_user_id())
							$account_user_cmodel->set_user($user_cmodel);
			}

			return $account_user_cmodels;
		}
		
		function filter_state_active()			{ return $this->set_state(DBQ_ACCOUNT_USER::STATE_ACTIVE); }
		function load_users($user_hmodel=null) {
			$this->_user_hmodel = $user_hmodel ? $user_hmodel : HMODEL_USER::get_default_handler();
			return $this;
		}

		function get_count($field=null) 		{ return $this->get_dbq()->count($field); }
		function exists($field=null)			{ return $this->get_dbq()->exists($field); }
		function set_account_user_ids($values)	{ return $this->add_filter("account_users.account_user_id","IN",$values); }
		function set_account_user_id($value)	{ return $this->add_filter("account_users.account_user_id","=",$value); }
		function set_user_id($value)	{ return $this->add_filter("account_users.user_id","=",$value); }
		function set_user_ids($values)	{ return $this->add_filter("account_users.user_id","IN",$values); }
		function set_account_id($value)	{ return $this->add_filter("account_users.account_id","=",$value); }
		function set_account_ids($values)	{ return $this->add_filter("account_users.account_id","IN",$values); }
		function set_brand_id($value)	{ return $this->add_filter("account_users.brand_id","=",$value); }
		function set_brand_ids($values)	{ return $this->add_filter("account_users.brand_id","IN",$values); }
		function set_state($value)	{ return $this->add_filter("account_users.state","=",$value); }
		function set_states($values)	{ return $this->add_filter("account_users.state","IN",$values); }
	
		function get_default_handler() {
			
			return HMODEL_ACCOUNT_USER::create()
					->filter_state_active()
					->join("account_users","users","user_id")
					->join("users","objects","object_id")
					->where("objects.state","=",CMODEL_USER::STATE_ACTIVE);
		}
	}
	