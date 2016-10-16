<?
	class VIEW_MANAGE_APILOG extends VIEW {

		protected $_api_log_cmodel = null;
		protected $_previous_api_id = null;
		protected $_next_api_id = null;

		function __construct() {
			parent::__construct("manage","apilog")
				->set_permission(CMODEL_USER::PERMISSION_BACKEND)
				->type_popup();

			$this->_api_log_cmodel = CMODEL_API_LOG::create();
		}

		function init() {

			if($api_log_id=$this->get("alid"))
				$this->load($api_log_id);

			$this->set_var("api_log",$this->_api_log_cmodel);
			$this->set_var("next_api_id",$this->_next_api_id);
			$this->set_var("previous_api_id",$this->_previous_api_id);
		}

		function load($api_log_id) {

			$api_log_cmodel = HMODEL_API_LOG::create(false)->get($api_log_id);

			if($api_log_cmodel) {

				$this->_next_api_id = DBQ_API_LOG::create()
											->where("api_log_id",">",$api_log_id)
											->one("api_log_id");


				$this->_previous_api_id = DBQ_API_LOG::create()
											->where("api_log_id","<",$api_log_id)
											->order("api_log_id","DESC")
											->one("api_log_id");

				$this->_api_log_cmodel = $api_log_cmodel;
			}
		}
	}