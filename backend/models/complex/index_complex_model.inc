<?
	class CMODEL_INDEX extends CMODEL {

		// ADD INDEX OBJECT TYPES
		const TYPE_CUSTOMER		= "customer";
		const TYPE_AGENT		= "agent";
		const TYPE_ACCOUNT		= "account";
		const TYPE_INITIATIVE 	= "initiative";
		const TYPE_PROJECT 		= "project";
		const TYPE_STEP 		= "step";
		const TYPE_FILE	 		= "file";

		const STATE_ACTIVE 		= 'active';
		const STATE_DRAFT 		= 'draft';
		const STATE_DELETED 	= 'deleted';

		static function get_states()	{
			return [	self::STATE_ACTIVE=>"Active",
						self::STATE_DRAFT=>"Draft",
						self::STATE_DELETED=>"Deleted"
			];
		}
		static function get_state_list()	{return self::get_states(); }

		static function get_types()	{
			return [
				// ADD INDEX OBJECT TYPES
				self::TYPE_CUSTOMER=>"Customer",
				self::TYPE_AGENT=>"Agent",
				self::TYPE_ACCOUNT=>"Account",
				self::TYPE_INITIATIVE=>"Initiative",
				self::TYPE_PROJECT=>"Project",
				self::TYPE_STEP=>"Step",
				self::TYPE_FILE=>"File"
			];
		}

		public function __construct($type=null,$id=null) {
			parent::__construct()
						->register_dbo(DBO_INDEX::create())
						->register_delimited("secondary_keyword"," ")
						->register_delimited("primary_keyword"," ");

			if($type) {
				$where = ["type"=>$type];

				$this->set_type($type);

				// if($this->is_type_customer()) {
				// 	$this->set_customer_user_id($id);
				// 	$where["customer_user_id"] = $id;
				// }

				// if($this->is_type_step()) {
				// 	$this->set_step_id($id);
				// 	$where["step_id"] = $id;
				// }

				// if($this->is_type_file()) {
				// 	$this->set_file_id($id);
				// 	$where["file_id"] = $id;
				// }

				// if($this->is_type_project()) {
				// 	$this->set_project_id($id);
				// 	$where["project_id"] = $id;
				// }

				// if($this->is_type_initiative()) {
				// 	$this->set_initiative_id($id);
				// 	$where["initiative_id"] = $id;
				// }

				// if($this->is_type_agent()) {
				// 	$this->set_agent_user_id($id);
				// 	$where["agent_user_id"] = $id;
				// }

				// if($this->is_type_account()) {
				// 	$this->set_account_id($id);
				// 	$where["account_id"] = $id;
				// }

				$this->dbo("index")->select($where);
			}

			return $this;
		}

		public static function create($type=null,$id=null) {
			return new CMODEL_INDEX($type,$id);
		}

		public function get_manage_url()		{ return "/manage/indexinspect/id:".$this->get_index_id()."/"; }
		public function get_state_name()		{ return value(self::get_states(),$this->get_state()); }

		public function is_type_customer()		{ return $this->get_type()==self::TYPE_CUSTOMER; }
		public function is_type_agent()			{ return $this->get_type()==self::TYPE_AGENT; }
		public function is_type_account()		{ return $this->get_type()==self::TYPE_ACCOUNT; }
		public function is_type_initiative()	{ return $this->get_type()==self::TYPE_INITIATIVE; }
		public function is_type_project()		{ return $this->get_type()==self::TYPE_PROJECT; }
		public function is_type_file()			{ return $this->get_type()==self::TYPE_FILE; }
		public function is_type_step()			{ return $this->get_type()==self::TYPE_STEP; }

		public function get_url() {
			if($this->is_type_customer())
				return "/accounts/customers/".$this->get_customer_user_id();

			if($this->is_type_agent())
				return "/agents/agent/".$this->get_agent_user_id();

			if($this->is_type_account())
				return "/accounts/account/".$this->get_account_id();

			if($this->is_type_initiative())
				return "/initiative/".$this->get_initiative_id();

			if($this->is_type_project())
				return "/initiative/".$this->get_initiative_id()."/project/".$this->get_project_id();

			if($this->is_type_step())
				return "/initiative/".$this->get_initiative_id()."/step/".$this->get_step_id();

			if($this->is_type_file())
				return "/accounts/account/".$this->get_account_id()."/files/".$this->get_file_id();
		}

		public function get_icon() {
			if($this->is_type_customer() || $this->is_type_agent())
				return "person";

			if($this->is_type_account())
				return "account_balance";

			if($this->is_type_initiative() || $this->is_type_project())
				return "work";

			if($this->is_type_file())
				return "insert_drive_file";

			return parent::get_icon();
		}

		public function save() {

			if(!$this->get_type())
				throw new Exception("Invalid index type");

			if(self::get_index_id()) {
				$this->dbo("index")->update();
			} else {
				$this->dbo("index")->insert();
			}

			return $this;
		}

		public function describe() {
			return [
					"name" => [
						"validations"=>[ "required"=>true ]
					],
					"primary_keyword" => [
						"validations"=>[ "required"=>false ]
					],
					"secondary_keyword" => [
						"validations"=>[ "required"=>false ]
					],
					"image_url" => [
						"validations"=>[ "required"=>false ]
					],
					"type" => [
						"validations"=>[ "required"=>false ]
					]
			];
		}

		/**
		 * @param $hmodel HMODEL
		 * @param $type string
		 * @param $value string
		 * @return HMODEL
		 */

		public function apply_handler($hmodel,$type,$value) {

			$table = value([self::TYPE_PROJECT=>"projects", self::TYPE_STEP=>'steps'],$type);
			$column = value([self::TYPE_PROJECT=>"project_id", self::TYPE_STEP=>'step_id'],$type);

			return $hmodel
				->db_join(DB_JOIN::create($table,"indexes",$column,$column)
							->on("indexes.type","=","'".$type."'"))
				->group(DB_GROUP::create()
					->where("MATCH(indexes.primary_keyword)","AGAINST","'*".$value."*' IN BOOLEAN MODE","OR",false,false,false)
					->where("MATCH(indexes.secondary_keyword)","AGAINST","'*".$value."*' IN BOOLEAN MODE","OR",false,false,false)
				)
				->where('indexes.'.$column,'=', $table.'.'.$column, 'AND', false, false, false)

				->data("MATCH(indexes.primary_keyword) AGAINST ('*".$value."*' IN BOOLEAN MODE)","index_weight1")
				->data("MATCH(indexes.secondary_keyword) AGAINST ('*".$value."*' IN BOOLEAN MODE)","index_weight2")
				//->data("((MATCH(indexes.primary_keyword) AGAINST ('".$value."*' IN BOOLEAN MODE))*2) + (MATCH(indexes.secondary_keyword) AGAINST ('".$value."*' IN BOOLEAN MODE))","index_weight")

				->order_by("(index_weight1*2) + index_weight2","DESC");
				;
		}


		public function arry($arry=array()) {

			$arry = CMODEL_OBJECTER::create($this,
											array(	"id"=>"get_index_id",
													"get_name",
													"get_image_url",
													"get_customer_user_id",
													"get_type",
													"get_url",
													"get_icon",
													"get_icon_color"
													))->arry();

			return $arry;
		}
	}