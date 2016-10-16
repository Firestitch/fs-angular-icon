<?
	class CMODEL_IMPERSONATE extends CMODEL {
		
		const STATE_ACTIVE	= "active";
		const STATE_DELETED	= "deleted";
		const STATE_ACTIVATED = "activated";
				
		public static function get_states()	{ return array(self::STATE_ACTIVE=>"Active",self::STATE_DELETED=>"Deleted",self::STATE_ACTIVATED=>"Activated"); }

		public function set_impersonated_user($value) { return $this->data("impersonated_user",$value); }

		public function get_impersonated_user($hmodel=true) {
			if($hmodel && !$this->has_data("impersonated_user") && $this->get_impersonated_user_id()) {
				$hmodel = is_a($hmodel,"HMODEL") ? $hmodel : HMODEL_USER::create(false);
				$this->data("impersonated_user",$hmodel->get($this->get_impersonated_user_id()));
			}
			return $this->data("impersonated_user");
		}

		public function __construct() {
			return parent::__construct(DBO_IMPERSONATE::create());
		}
		
		public function get_state_name()	{ return value(self::get_states(),$this->get_state()); }
		public function get_manage_url()	{ return "/manage/impersonate/iid:".$this->get_impersonate_id()."/"; }
		public function get_url()			{ return "/impersonates/impersonate/iid:".$this->get_impersonate_id()."/"; }
		public function delete()			{ return $this->set_state(self::STATE_DELETED)->save(); }	
		public function is_state_delete()	{ return $this->get_state()==self::STATE_DELETED; }		
		public function is_state_active()	{ return $this->get_state()==self::STATE_ACTIVE; }		

		public function save() {

			if(is_numeric(self::get_impersonate_id())) {
				if(!$this->dbo("impersonate")->update())
					throw new Exception("Error updating ".get_class());
				
			} else {
				if(!$this->get_guid())
					$this->set_guid(MISC_UTIL::get_guid());
					
				if(!$this->get_state())
					$this->set_state(self::STATE_ACTIVE);
					
				if(!$this->get_create_date())
					$this->set_create_date(DB::get_date_time());
					
				if(!$this->dbo("impersonate")->insert())
					throw new Exception("Error inserting ".get_class());
			}
		
			return $this;
		}

		public function arry($arry=array()) {

			$arry = CMODEL_OBJECTER::create($this,
											array(	"id"=>"get_impersonate_id",
													"get_state",
													"get_ip",
													"get_user_agent",
													"get_create_date",
													"get_guid",
													"get_activate_date",
													"get_user_id",
													"get_impersonated_user_id",
													))->arry();

			if($impersonated_user_cmodel=$this->get_impersonated_user(false))
				$arry["impersonated_user"] = $impersonated_user_cmodel->arry();

			return $arry;
		}		
	}