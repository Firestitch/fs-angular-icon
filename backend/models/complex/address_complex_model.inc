<?
	class CMODEL_ADDRESS extends CMODEL {
		
		const STATE_ACTIVE	= "active";
		const STATE_DELETED	= "deleted";
				
		public static function get_states()	{ return array(self::STATE_ACTIVE=>"Active",self::STATE_DELETED=>"Deleted"); }

		public function __construct() {
			return parent::__construct(DBO_ADDRESS::create());
		}
		
		public function get_state_name()	{ return value(self::get_states(),$this->get_state()); }
		public function get_manage_url()	{ return "/manage/address/aid:".$this->get_address_id()."/"; }
		public function get_url()			{ return "/addresss/address/aid:".$this->get_address_id()."/"; }
		public function delete()			{ return $this->set_state(self::STATE_DELETED)->save(); }	
		public function is_state_delete()	{ return $this->get_state()==self::STATE_DELETED; }		
		public function is_state_active()	{ return $this->get_state()==self::STATE_ACTIVE; }		

		public function save() {

			if(is_numeric(self::get_address_id())) {
				if(!$this->dbo("address")->update())
					throw new Exception("Error updating ".get_class());
				
			} else {
				if(!$this->get_guid())
					$this->set_guid(MISC_UTIL::get_guid());
					
				if(!$this->get_state())
					$this->set_state(self::STATE_ACTIVE);
					
				if(!$this->get_create_date())
					$this->set_create_date(DB::get_date_time());
					
				if(!$this->dbo("address")->insert())
					throw new Exception("Error inserting ".get_class());
			}
		
			return $this;
		}

		public function arry($arry=array()) {

			$arry = CMODEL_OBJECTER::create($this,
											array(	"id"=>"get_address_id",
													"get_state",
													"get_address1",
													"get_address2",
													"get_city",
													"get_region",
													"get_zip",
													"get_country",
													"get_lat",
													"get_lng",
													"get_create_date",
													"get_modify_date",
													"get_guid",
													))->arry();

			return $arry;
		}		
	}