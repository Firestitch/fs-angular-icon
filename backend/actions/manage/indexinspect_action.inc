<?
	class ACTION_MANAGE_INDEXINSPECT extends ACTION_JSON {

		function __construct() {
			parent::__construct([]);
		}

		function process() {

			$index_id	= $this->post("iid");
			$form			= $this->post("form");

			$index_cmodel = ($index_cmodel=HMODEL_INDEX::get($index_id)) ? $index_cmodel : CMODEL_INDEX::create();
			$index_cmodel->populate($form);

			$index_cmodel->set_primary_keyword(explode(",",value($form,"primary_keyword")));
			$index_cmodel->set_secondary_keyword(explode(",",value($form,"secondary_keyword")));

			try {

				$index_cmodel->save();

				if(!$index_id) {
					APPLICATION::add_persistent_notify("Successfully added the index");
					$this->redirect($index_cmodel->get_manage_url());
				}

				$this
					->data("iid",$index_cmodel->get_index_id())
					->success();

			} catch(Exception $e) {
				$this->error($e);
			}

			if(!$this->has_success() && !$this->has_error())
				$this->error("There was a problem trying to save the index");
		}
	}


