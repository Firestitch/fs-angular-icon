<?
	class CMODEL_AUDIT extends CMODEL {


		const TYPE_USER 			= "user";
		/* add your types */
		// const TYPE_EMPLOYEE 		= "employee";


		const ACTION_ADD 		= "add";
		const ACTION_CHANGE 	= "change";
		const ACTION_LOGIN 		= "login";

		public function __construct() {
			parent::__construct();
			$this->register_json("meta");
			return $this->register_dbo(DBO_AUDIT::create());
		}

		public function set_user($value) { return $this->data("user",$value); }

		public function get_user($hmodel=true) {
			if($hmodel && !$this->has_data("user") && $this->get_user_id()) {
				$hmodel = is_a($hmodel,"HMODEL") ? $hmodel : HMODEL_USER::create(false);
				$this->data("user",$hmodel->get($this->get_user_id()));
			}
			return $this->data("user");
		}


		public function get_manage_url()	{ return "/manage/audit/aid:".$this->get_audit_id()."/"; }
		public function get_url()			{ return "/audits/audit/aid:".$this->get_audit_id()."/"; }

		public function save() {

			if(is_numeric(self::get_audit_id())) {
				$this->dbo("audit")->update();
			} else {
				if(!$this->get_create_date())
					$this->set_create_date(DB::get_date_time());

				$this->dbo("audit")->insert();
			}

			return $this;
		}

		public function arry($arry=array()) {

			$arry = CMODEL_OBJECTER::create($this,
											array(	"id"=>"get_audit_id",
													"get_create_date|iso8601",
													"get_type",
													"get_user_id",
													"get_action",

													/* add your foreign ids */
													// "get_employee_id",

													"get_meta",
													))->arry();

			if($user_cmodel=$this->get_user(false))
				$arry["user"] = $user_cmodel->arry();

			return $arry;
		}
	}