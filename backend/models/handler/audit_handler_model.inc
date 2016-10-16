<?
	class HMODEL_AUDIT extends HMODEL {

		protected $_select_fields = array("audits.*");

		public function __construct() {
			return $this->register_dbq(DBQ_AUDIT::create());
		}

		public function gets() {
			$audits = $this->get_dbq()->select($this->_select_fields);

			$audit_cmodels = array();
			foreach($audits as $audit) {
				$audit_cmodel = CMODEL_AUDIT::create()->populate($audit,true,false);
				$this->apply_properties($audit_cmodel,$audit);
				$audit_cmodels[] = $audit_cmodel;
			}

			if(!$audit_cmodels)
				return array();

			$this->map_one($audit_cmodels,$this->handler("user_handler"),"user","user","user");

			return $audit_cmodels;
		}

		public function set_audit_ids($values)	{ return $this->where("audits.audit_id","IN",$values); }
		public function set_audit_id($value)	{ return $this->where("audits.audit_id","=",$value); }
		public function set_user_id($value)		{ return $this->where("audits.user_id","=",$value); }
		public function set_user_ids($values)			{ return $this->where("audits.user_id","IN",$values); }

		/* add your foreign keys */
		// public function set_employee_id($value)		{ return $this->where("audits.employee_id","=",$value); }
		// public function set_employee_ids($values)			{ return $this->where("audits.employee_id","IN",$values); }


		public static function create($defaults=true) {
			return $defaults ? parent::create() : parent::create();
		}

		public function load_users($user_hmodel=null) {
			return $this->handler("user_handler",$user_hmodel ? $user_hmodel : HMODEL_USER::create());
		}
	}