<?
	class VIEW_API_AUDITS extends VIEW_API_BASE {

		//public function require_api_token() { return false; }
		//public function skip_group() { return false; }

		public function audits($audit_id=null,$action=null) {

			if($this->is_get()) {

				$audit_hmodel = HMODEL_AUDIT::create(false)
				->load_users();

				if($audit_id)
					$audit_hmodel->set_audit_id($audit_id);

				if(!is_null($value=$this->request("type")))
					$audit_hmodel->where("type","=",$value);

				if(!is_null($value=$this->request("start_date")))
					$audit_hmodel->where("create_date",">=",CMODEL_TIME::create($value)->db_date());

				if(!is_null($value=$this->request("end_date")))
					$audit_hmodel->where("create_date","<=",CMODEL_TIME::create($value)->add_day(1)->db_date());

				if(!is_null($value=$this->request("keyword")))
					$audit_hmodel->where("meta","like","%{$value}%");

				if(!is_null($value=$this->request("user_id")))
					$audit_hmodel->where("user_id","=",$value);

				/* ADD YOUR FILTERS HERE */
				// if(!is_null($value=$this->request("employee_id")))
				// 	$audit_hmodel->where("employee_id","=",$value);



				$order = array_filter(explode(",",$this->request("order")));
				$audit_hmodel->order_by(value($order,0,"create_date"),value($order,1,"desc"));

				if(!$audit_id)
					$this->handler_paging($audit_hmodel,"create_date");

				$audit_cmodels = $audit_hmodel->gets();

				$audits = array();
				foreach($audit_cmodels as $audit_cmodel)
					$audits[] = $audit_cmodel->arry();

				if($audit_id)
					$this->data("audit",value($audits,0));
				else
					$this->data("audits",$audits);
			}
		}


		public function wsdl() {
			return array(	"model"=>"audit",
							"name"=>"Audit",
							"endpoints"=>array(array(	"path"=>array("audits","audits/audit_id"),
														"description"=>"Retrieve Audits or a Audit",
														"method"=>"get",
														"parms"=>array(),
														"response"=>array("audits","audit")),
			));
		}


	}