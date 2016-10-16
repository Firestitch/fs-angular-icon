<?
	class CMODEL_FIELD_OPTION extends MODEL_COMPLEX {
	
		protected $_configs 				= array();
		
		public function __construct() {
			$this->register_dbo(new DBO_FIELD_OPTION);
		}
		
		public function is_state_active()					{ return $this->get_state()==DBQ_FIELD_OPTION::STATE_ACTIVE; }
		public function is_state_deleted()					{ return $this->get_state()==DBQ_FIELD_OPTION::STATE_DELETED; }
		public function get_state_name()					{ return get_value(DBQ_FIELD_OPTION::get_state_list(),$this->get_state()); }
		public function get_manage_url()					{ return "/manage/fieldoption/foid:".$this->get_field_option_id()."/"; }
		public function get_configs()						{ return $this->_configs; }
		public function get_config($name,$default=null)		{ return get_value($this->_configs,$name,$default); }
		public function set_config($name,$value)			{ $this->_configs[$name] = $value; return $this; }
		public function set_configs($value)					{ $this->_configs = $value; return $this; }

		public function delete() {
			$this->set_state(DBQ_FIELD_OPTION::STATE_DELETED);
			return $this->save();
		}
		
		public function save() {
			
			$this->get_dbo("field_option")->set_configs(JSON_UTIL::encode($this->_configs));

			$has_success = false;
			if(is_numeric(self::get_field_option_id())) {
				$has_success = $this->get_dbo("field_option")->update();
				
			} else {
				if(!$this->get_guid())
					$this->set_guid(MISC_UTIL::get_guid());
					
				if(!$this->get_state())
					$this->set_state(DBQ_FIELD_OPTION::STATE_ACTIVE);
					
				$has_success = $this->get_dbo("field_option")->insert();
			}
				
			return $has_success;
		}

		public function populate($data,$untag=false,$previous=false) {
						
			if(@array_key_exists("configs",$data)) {
						
				$configs = get_value($data,"configs",array());
				
				$this->_configs = (array)JSON_UTIL::decode($configs);

				unset($data["configs"]);
			}

			parent::populate($data,$untag,$previous);
		}		
	}