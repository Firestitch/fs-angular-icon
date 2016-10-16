<?
	class VIEW_MANAGE_INDEXINSPECT extends VIEW {

		protected $_index_cmodel = null;

		function __construct() {
			parent::__construct("manage","indexinspect")
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);

			$this->_index_cmodel = CMODEL_INDEX::create();
		}

		function init() {

			if($index_id=$this->get("id"))
				$this->load($index_id);

			$this->set_var("index",$this->_index_cmodel);
		}

		function load($index_id) {

			$index_cmodel = HMODEL_INDEX::create(false)->get($index_id);

			if($index_cmodel)
				$this->_index_cmodel = $index_cmodel;
		}
	}