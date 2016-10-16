<?
	class HMODEL_OBJECT extends MODEL_HANDLER {
	
		protected $_select_fields = array("objects.*");
		
		protected $_object_account_hmodel = null;

		function get_dbq() {
			return $this->apply_constraints(DBQ_OBJECT::create());
		}
		
		function gets() {			
			$objects = $this->get_dbq()->select($this->_select_fields);

			$object_cmodels = array();			
			foreach($objects as $object) {
				$object_cmodel = new CMODEL_OBJECT();
				$object_cmodel->populate($object,true,false);
				$this->apply_properties($object_cmodel,$object);
				$object_cmodels[] = $object_cmodel;
			}
			
			if(!$object_cmodels)
				return array();

			$this->map_one($object_cmodels,$this->_object_account_hmodel,"object","object","object_account");
			
			return $object_cmodels;
		}
		
		function where_state_active()			{ return $this->set_state(CMODEL_OBJECT::STATE_ACTIVE); }
		
		function load_account_objects($object_account_hmodel=null) {
			$this->_object_account_hmodel = $object_account_hmodel ? $object_account_hmodel : HMODEL_OBJECT_ACCOUNT::create();
			return $this;
		}

		function get_count($field=null) 	{ return $this->get_dbq()->count($field); }
		function exists($field=null)		{ return $this->get_dbq()->exists($field); }
		function set_object_ids($values)	{ return $this->where("objects.object_id","IN",$values); }
		function set_object_id($value)		{ return $this->where("objects.object_id","=",$value); }
		function set_state($value)			{ return $this->where("objects.state","=",$value); }
		function set_states($values)		{ return $this->where("objects.state","IN",$values); }
		function set_guid($value)			{ return $this->where("objects.guid","=",$value); }
		function set_guids($values)			{ return $this->where("objects.guid","IN",$values); }
	
		function get_default_handler() {
			return HMODEL_OBJECT::create()->where_state_active();
		}
	}
	