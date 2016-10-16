<?
	class HMODEL_INDEX extends HMODEL {

		protected $_select_fields = array("indexes.*");

		public function __construct() {
			return $this->register_dbq(DBQ_INDEX::create());
		}

		public function gets() {
			$indexes = $this->get_dbq()->select($this->_select_fields);

			$index_cmodels = array();
			foreach($indexes as $index) {
				$index_cmodel = CMODEL_INDEX::create()->populate($index,true,false);
				$this->apply_properties($index_cmodel,$index);
				$index_cmodels[] = $index_cmodel;
			}

			if(!$index_cmodels)
				return array();

			return $index_cmodels;
		}

		public function where_state_active()			{ return $this->where("indexes.state","NOT IN",[CMODEL_INDEX::STATE_DRAFT, CMODEL_INDEX::STATE_DELETED]); }
		public function set_index_ids($values)	{ return $this->where("indexes.index_id","IN",$values); }
		public function set_index_id($value)	{ return $this->where("indexes.index_id","=",$value); }
		public function set_customer_user_id($value)		{ return $this->where("indexes.customer_user_id","=",$value); }
		public function set_customer_user_ids($values)			{ return $this->where("indexes.customer_user_id","IN",$values); }
		public function set_state($value)		{ return $this->where("indexes.state","=",$value); }
		public function set_states($values)			{ return $this->where("indexes.state","IN",$values); }
		public function set_guid($value)		{ return $this->where("indexes.guid","=",$value); }
		public function set_guids($values)			{ return $this->where("indexes.guid","IN",$values); }

		public static function create($defaults=true) {
			return $defaults ? parent::create()->where_state_active() : parent::create();
		}
	}
