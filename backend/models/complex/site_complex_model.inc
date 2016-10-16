<?
	class CMODEL_SITE extends CMODEL_OBJECT_ACCOUNT {

		protected $_domain_cmodel = null;
		protected $_graph_cmodel = null;
		protected $_domain_cmodels = array();
	
		public function __construct() {
			parent::__construct(new DBO_SITE);
		}

		public function set_domains($value) { $this->_domain_cmodels = $value; return $this; }

		public function get_domains($load=false,$domain_hmodel=null) {
			if($load && !$this->_domain_cmodels) {
				if(!$domain_hmodel)
					$domain_hmodel = HMODEL_DOMAIN::create();
				$domain_hmodel->where("domain_id","=",$this->get_domain_id());
				$this->_domain_cmodels = $domain_hmodel->gets();
			}
			return $this->_domain_cmodels;
		}

		public function set_graph($value) { $this->_graph_cmodel = $value; }

		public function get_graph($load=true) {
			if($load && !$this->_graph_cmodel) $this->_graph_cmodel = $this->get_graph_id() ? HMODEL_GRAPH::get($this->get_graph_id()) : null;
			return $this->_graph_cmodel;
		}

		public function set_domain($value) { $this->_domain_cmodel = $value; }

		public function get_domain($load=true) {
			if($load && !$this->_domain_cmodel) $this->_domain_cmodel = $this->get_domain_id() ? HMODEL_DOMAIN::get($this->get_domain_id()) : null;
			return $this->_domain_cmodel;
		}
		
		public function is_state_active()			{ return $this->get_state()==DBQ_SITE::STATE_ACTIVE; }
		public function is_state_deleted()			{ return $this->get_state()==DBQ_SITE::STATE_DELETED; }
		public function is_protocol_default()		{ return $this->get_protocol()==DBQ_SITE::PROTOCOL_DEFAULT; }
		public function get_state_name()			{ return get_value(DBQ_SITE::get_state_list(),$this->get_state()); }
		public function get_protocol_name()			{ return get_value(DBQ_SITE::get_protocol_list(),$this->get_protocol()); }
		public function get_manage_url()			{ return "/manage/accountsite/sid:".$this->get_site_id()."/"; }
		public function get_public_url($time=null) 	{ return "/public/".($time ? $time."/" : "")."st/".$this->get_site_id()."/"; }
		public function get_public_dir() 			{ return MODEL_PATH::get_public_directory()."st/".$this->get_site_id()."/"; }
		public function get_css_file() 				{ return $this->get_public_dir()."css/style.css"; }
		public function has_css_file() 				{ return is_file($this->get_css_file()); }
		public function get_css() 					{ return FILE_UTIL::get($this->get_css_file()); }
		public function get_css_url() 				{ return $this->get_public_url(FILE_UTIL::get_file_modified_time($this->get_css_file()))."css/style.css"; }
		
		public function get_active_singed_request() { 
			
			$facebook_singed_request_cmodel = MODEL_FACEBOOK::get_active_singed_request($this->get_facebook_application_id(),$this->get_facebook_secret_key()); 

			if(!$facebook_singed_request_cmodel)
				$facebook_singed_request_cmodel = USER_SESSION::get_instance()->get_setting("signed_request");

			USER_SESSION::get_instance()->set_setting("signed_request",$facebook_singed_request_cmodel);

			return $facebook_singed_request_cmodel;
		}

		public function queue_preview() {
			DBQ_GRAPH_NODE::create()
				->where("graph_nodes.state","=",DBQ_GRAPH_NODE::STATE_ACTIVE)
				->inner("sites","graph_id")
				->update(array("preview"=>0));
		}

		public function get_url($protocol=true) {
			return ($protocol ? "http://" : "").$this->get_subdomain().".".($this->get_domain() ? $this->get_domain()->get_name() : "");
		}
		
		public function save() {
			
			DB::start_transaction();

			if(!self::get_site_id())
				$this->set_type(CMODEL_OBJECT::TYPE_SITE);

			$this->set_name($this->get_url(false));

			if(parent::save()) {
				
				if(is_numeric(self::get_site_id())) {
					$has_success = $this->get_dbo("site")->update();
					
				} else {

					if(!$this->get_graph_id()) {

						$this->set_graph(CMODEL_GRAPH::create()
												->set_object_id(parent::get_object_id()));


						$this->get_graph()
									->set_template($this->get_default_template())
									->save();

						$this->get_graph()->init();

						$this->set_graph_id($this->get_graph()->get_graph_id());
					}

					$has_success = $this->get_dbo("site")
											->set_object_id(parent::get_object_id())
											->insert();								
				}
			}

			$has_success = DB::has_transaction_success();
			DB::complete_transaction();
			
			return $has_success;
		}

		public function get_default_template() {
			return 	'<!DOCTYPE html>'.chr(10).
					'<head>'.chr(10).
					'		<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">'.chr(10).
					'	{$site->head}'.chr(10).
					'</head>'.chr(10).
					'<body>'.chr(10).
					'	{$site->body}'.chr(10).
					'</body>'.chr(10).
					'</html>';
		}

		public function find() {

			return HMODEL_SITE::create()
								->where("objects.name","=",SERVER_UTIL::get_server_host())
								->get();
		}
		
	}