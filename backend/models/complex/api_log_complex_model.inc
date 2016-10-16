<?
	class CMODEL_API_LOG extends CMODEL {
		
		const STATE_SUCCESS			= "success";
		const STATE_FAILED			= "failed";
		const STATE_DELETED			= "deleted";

		const DIRECTION_INCOMING	= "incoming";
		const DIRECTION_OUTGOING	= "outgoing";
				
		public static function get_states()	{ return array(self::STATE_SUCCESS=>"Success",self::STATE_FAILED=>"Failed"); }

		public static function get_directions()	{ return array(self::DIRECTION_INCOMING=>"Incoming",self::DIRECTION_OUTGOING=>"Outgoing"); }

		public function __construct() {
			parent::__construct();
			return $this->register_dbo(DBO_API_LOG::create());
		}
		
		public function get_state_name()	{ return value(self::get_states(),$this->get_state()); }
		public function get_direction_name(){ return value(self::get_directions(),$this->get_direction()); }
		public function get_manage_url()	{ return "/manage/apilog/alid:".$this->get_api_log_id()."/"; }
		public function is_state_failed()	{ return $this->get_state()==self::STATE_FAILED; }		
		public function is_state_success()	{ return $this->get_state()==self::STATE_SUCCESS; }		

		public function save() {

			if(is_numeric(self::get_api_log_id())) {
				$this->dbo("api_log")->update();
			} else {
				
				if(!$this->get_state())
					$this->set_state(self::STATE_FAILED);
					
				if(!$this->get_create_date())
					$this->set_create_date(DB::get_date_time());
					
				$this->dbo("api_log")->insert();
			}
		
			return $this;
		}

		public function arry($arry=array()) {

			$arry = CMODEL_OBJECTER::create($this,
											array(	"id"=>"get_api_log_id",
													"get_create_date",
													"get_request",
													"get_response",
													"get_state",
													"get_headers",
													"get_url",
													"get_code",
													"get_direction",
													"get_reference",
													"get_message",
													"get_type",
													"get_length",
													))->arry();

			return $arry;
		}		
	}