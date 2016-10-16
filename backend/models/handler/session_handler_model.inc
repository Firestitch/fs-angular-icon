<?
	class HMODEL_SESSION extends MODEL_HANDLER {
	
		protected $_select_fields = array("sessions.*");
		
		function get_dbq() {
			return $this->apply_constraints(DBQ_SESSION::create());
		}
		
		function gets() {			
			$sessions = $this->get_dbq()->select($this->_select_fields);

			$session_cmodels = array();			
			foreach($sessions as $session) {
				$session_cmodel = new CMODEL_SESSION();
				$session_cmodel->populate($session,true,false);
				$this->apply_properties($session_cmodel,$session);
				$session_cmodels[] = $session_cmodel;
			}
			
			if(!$session_cmodels)
				return array();
			
			return $session_cmodels;
		}
		
				public function get_count($field=null) 			{ return $this->get_dbq()->count($field); }
		public function exists($field=null)				{ return $this->get_dbq()->exists($field); }
		public function set_session_ids($values)	{ return $this->where("sessions.session_id","IN",$values); }
		public function set_session_id($value)	{ return $this->where("sessions.session_id","=",$value); }
		public function set_contact_id($value)		{ return $this->where("sessions.contact_id","=",$value); }
		public function set_contact_ids($values)			{ return $this->where("sessions.contact_id","IN",$values); }
	

		public static function create($defaults=true) {
			return $defaults ? parent::create() : parent::create();
		}		
	}
	