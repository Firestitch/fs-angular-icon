<?
	class ACTION_MANAGE_INDEXES extends ACTION_JSON {

		public function __construct() {
			parent::__construct([]);
		}

		public function process() {
			CMODEL_PROCESS::create()->queue("reindex",$this->posts());
			$this->success();
		}
	}