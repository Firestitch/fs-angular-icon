<?
	class VIEW_API_BASE extends BASE_VIEW_API_REST {

		protected $_api_token_cmodel = null;
		public function get_api_token() {

			if(!$this->_api_token_cmodel && ($key=$this->get_api_token_key())) {

				//Remove the 4th octet to create 255.255.255.0
				$ip = preg_replace("/\.\d+$/",".%",SERVER_UTIL::get_remote_ip());

				$this->_api_token_cmodel = HMODEL_API_TOKEN::create()
													->where("create_date",">",CMODEL_TIME::create(time())->subtract_day()->short_date())
													->where("state","=",DBQ_API_TOKEN::STATE_ACTIVE)
													->where("`key`","=",$key)
													->where("ip","LIKE",$ip)
													->get();

				// Reset the create date to now so the expiry date will be reset to 24 after the create date
				if($this->_api_token_cmodel)
					$this->_api_token_cmodel->reset_expiry_date();
			}

			return $this->_api_token_cmodel;
		}


		public function get_api_token_key() {
			return $this->header("api-key") ? $this->header("api-key") : $this->post("api-key");
		}

		public function get_api_token_id() {
			return $this->get_api_token() ? $this->get_api_token()->get_api_token_id() : null;
		}

		public function get_user() {
			return $this->get_api_token() ? $this->get_api_token()->get_user() : null;
		}

		public function require_api_token() 		{ return true; }
		public function require_user_api_token() 	{ return true; }
		public function api_token_exceptions() 		{ return array(); }

		public function validate_admin_access() {
			if(!$this->get_api_token())
				throw new Exception("Invalid token");

			return $this->get_api_token()->validate_admin_access();
		}

		public function has_api_token_exception() {

			foreach($this->api_token_exceptions() as $exception)
				if($this->server()->uri()->is_uri($exception))
					return true;

			return false;
		}

		public function process() {

			if($this->server()->is_options()) die();

			if($this->require_api_token() && !$this->has_api_token_exception()) {

				try {

					if(!$this->get_api_token_key())
						throw new Exception("API token not specified",401);

			 		if(!$this->get_api_token())
	             		throw new Exception("Sorry, your session has expired, please try again.",401);

	             	if($this->require_user_api_token() && !$this->get_api_token()->get_user_id())
						throw new Exception("Sorry, you do not have access to this page, please try again.",403);

				} catch(Exception $e) {
					$this->server()->response()->error($e->getMessage(),$e->getCode());
				 	$this->server()->render(true);
            	}
	        }

	        $token = null;
	        if($api_token_cmodel=$this->get_api_token())
	        	$token = $api_token_cmodel->arry();

	        $this->payload("token",$token);

            parent::process();
		}

		public function handler($hmodel,$order="") {

			$limit = (int)$this->request("limit");
			$records = $hmodel->count();

			$page = ($page=(int)$this->request("page"))>0 ? $page : 1;
			$pages = @ceil($records/$limit);

			$this->data("paging",array(	"limit"=>$limit,
										"records"=>$records,
										"page"=>$page,
										"pages"=>$pages));

			if($limit) {
				$offset = ($page - 1) * $limit;
				$hmodel->limit($limit,$offset);
			}

			$order 				= $this->request("order") ? $this->request("order") : $order;
			$order 				= explode(",",$order);
			$order_field 		= value($order,0);
			$order_direction 	= strtoupper(value($order,1));
			$order_direction 	= in_array($order_direction,["ASC","DESC"]) ? $order_direction : "ASC";

			if($order_field)
				$hmodel->add_order_by("`".$order_field."`",$order_direction);

			return $hmodel;
		}
	}