<?
	class VIEW_MANAGE_PROCESS extends VIEW {

		protected $_process_cmodel = null;

		function __construct() {
			$this->set_route("manage","process");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
			$this->type_popup();
			$this->_process_cmodel = new CMODEL_PROCESS();
		}

		function init() {
			$registry = REGISTRY::get_instance();

			if(is_numeric($process_id=$registry->get("pid")))
				$this->load($process_id);


			$this->set_var("process", $this->_process_cmodel);
		}

		function load($process_id) {

			$process_cmodel = HMODEL_PROCESS::create()->get($process_id);

			if($process_cmodel)
				$this->_process_cmodel = $process_cmodel;
		}

		function set_process($process_cmodel) { $this->_process_cmodel = $process_cmodel; }
	}


