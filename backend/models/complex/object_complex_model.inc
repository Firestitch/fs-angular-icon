<?
	class CMODEL_OBJECT extends MODEL_COMPLEX {

		const STATE_ACTIVE	= "active";
		const STATE_DELETED	= "deleted";
		const STATE_DRAFT	= "draft";

		const TYPE_USER		= "user";

		static function get_states()	{ return array(self::STATE_ACTIVE=>"Active", self::STATE_DELETED=>"Deleted", self::STATE_DRAFT=>"Draft"); }

		static function get_types()	{ return array(	self::TYPE_USER=>"User"); }

		public function __construct($dbo=null) {
			parent::__construct(DBO_OBJECT::create());
			if($dbo)
				$this->register_dbo($dbo);
		}

		public function is_type_user()		{ return $this->get_type()==self::TYPE_USER; }

		public function get_state_name()	{ return value(self::get_states(),$this->get_state()); }
		public function get_type_name()		{ return value(self::get_types(),$this->get_type()); }
		public function get_manage_url()	{ return "/manage/object/oid:".$this->get_object_id()."/"; }

		public function save($options=array()) {

			$has_success = false;
			if(is_numeric(self::get_object_id())) {
				$has_success = $this->get_dbo("object")->update();

			} else {
				if(!$this->get_guid())
					$this->set_guid(MISC_UTIL::get_guid());

				if(!$this->get_create_date())
					$this->set_create_date(DB::get_date_time());

				if(!$this->get_object_type())
					$this->set_object_type(value($options,"type"));

				if(!$this->get_state())
					$this->set_state(value($options,"state"));

				$has_success = $this->get_dbo("object")->insert();
			}

			return $has_success;
		}
	}