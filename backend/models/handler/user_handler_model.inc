<?
	class HMODEL_USER extends MODEL_HANDLER {
	
		protected $_object_hmodel = null;
		protected $_user_role_hmodel = null;
		protected $_select_fields = array("objects.*","users.*");
		
		function get_dbq() {
			return $this->apply_constraints(DBQ_USER::create()->inner("objects","object_id"));
		}
		
		function get_users() {

			$users = $this->get_dbq()->select($this->_select_fields);

			$user_cmodels = array();			
			foreach($users as $user) {
				$user_cmodel = CMODEL_USER::create();
				$user_cmodel->populate($user,true);
				$this->apply_properties($user_cmodel,$user);
				$user_cmodels[] = $user_cmodel;
			}
			
			$this->map_many($user_cmodels,$this->_user_role_hmodel,"user","user","user_role");

			$this->map_one($user_cmodels,$this->_object_hmodel,"object","object","object");

			return $user_cmodels;
		}
		
		function set_user_ids($user_ids) 					{ return $this->add_filter("users.user_id","IN",$user_ids); }
		function set_user_id($user_id) 						{ return $this->add_filter("users.user_id","=",$user_id); }
		function set_guid($guid) 							{ return $this->add_filter("objects.guid","=",$guid); }
		function set_password($password,$encrypt=true) 		{ $this->add_filter("users.password","=",($encrypt ? CMODEL_USER::encrypt_password($password) : $password)); return $this; }
		function set_state($state) 							{ return $this->add_filter("objects.state","=",$state); }
	
		public function load_user_roles($user_role_hmodel=null) {
			$this->_user_role_hmodel = $user_role_hmodel ? $user_role_hmodel : HMODEL_USER_ROLE::create();
			return $this;
		}
	
		public function load_objects($object_hmodel=null) {
			$this->_object_hmodel = $object_hmodel ? $object_hmodel : HMODEL_OBJECT::create();
			return $this;
		}
	}