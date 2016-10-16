<?
	class ACTION_MANAGE_INDEXINSPECTREMOVE extends ACTION_JSON {
	
		function __construct() {
			parent::__construct([]);
		}
		
		function process() {
		
			$index_cmodel = HMODEL_INDEX::get($this->post("iid"));
			
			if(!$index_cmodel)
				throw new Exception("Failed to load index");
			
			$index_cmodel->delete();
				
			$this->success(true);			
		}	
	}