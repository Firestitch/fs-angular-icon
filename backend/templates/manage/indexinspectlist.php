<?
	if($indexes) {

		$table_data = array();

		foreach($indexes as $index) {

			$weight = 0;

			$actions = array();
			$actions[] = HTML_UTIL::link($index->get_manage_url(),MODEL_IMAGE_ICON::get_edit());
			$actions[] = HTML_UTIL::link("javascript:;",MODEL_IMAGE_ICON::get_delete(),array("class"=>"index-remove","data-id"=>$index->get_index_id()));

			$name = HTML_UTIL::link($index->get_manage_url(),$index->get_name());
			$table_data[] = array(
				number_format($index->data("index_weight"),2),
				$name,
				implode(",",$index->get_primary_keyword()),
				implode(",",$index->get_secondary_keyword()),
				$index->get_type(),
				$index->get_state_name(),
				array("data"=>implode(" ",$actions),"class"=>"wsnw w1")
			);
		}

		HTML_TABLE_UTIL::create()
			->set_data($table_data)
			->set_headings(array("Weight","Name","Primary Keyword","Secondary Keyword","Type","State",""))
			->set_id("index-table")
			->add_class("w100p")
			->render();

		$this->show_view("paging");
	} else
		echo "There are currently no indexes";
