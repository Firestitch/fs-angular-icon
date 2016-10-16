<?
	class HMODEL_ADDRESS extends HMODEL {
	
		protected $_select_fields = array("addresses.*");
		
		public function __construct() {
			return $this->register_dbq(DBQ_ADDRESS::create());
		}
		
		public function gets() {			
			$addresses = $this->get_dbq()->select($this->_select_fields);

			$address_cmodels = array();			
			foreach($addresses as $address) {
				$address_cmodel = CMODEL_ADDRESS::create()->populate($address,true,false);
				$this->apply_properties($address_cmodel,$address);
				$address_cmodels[] = $address_cmodel;
			}
			
			if(!$address_cmodels)
				return array();
			
			return $address_cmodels;
		}
		
		public function where_state_active()			{ return $this->set_state(CMODEL_ADDRESS::STATE_ACTIVE); }
		public function set_address_ids($values)	{ return $this->where("addresses.address_id","IN",$values); }
		public function set_address_id($value)	{ return $this->where("addresses.address_id","=",$value); }
		public function set_state($value)		{ return $this->where("addresses.state","=",$value); }
		public function set_states($values)			{ return $this->where("addresses.state","IN",$values); }
		public function set_guid($value)		{ return $this->where("addresses.guid","=",$value); }
		public function set_guids($values)			{ return $this->where("addresses.guid","IN",$values); }
		
		public static function create($defaults=true) {
			return $defaults ? parent::create()->where_state_active() : parent::create();
		}		
	}
	