<?
	if($api_logs) {

		$table_data = array();

		foreach($api_logs as $api_log) {

			$actions = array();
			$actions[] = HTML_UTIL::link("javascript:;",MODEL_IMAGE_ICON::get_view(),array("class"=>"api-log-update","data-alid"=>$api_log->get_api_log_id()));
				
			$name = HTML_UTIL::get_link($api_log->get_manage_url(),$api_log->get_api_log_id());

			$response = $api_log->get_message() ?HTML_UTIL::div($api_log->get_message()) : STRING_UTIL::shorten(htmlentities($api_log->get_response()),300);

			$date = CMODEL_FORMAT::create($api_log->get_create_date())->short_date_time().HTML_UTIL::span(" (".CMODEL_FORMAT::create($api_log->get_create_date())->age().")",array("class"=>"fss"));
			
			$code = $api_log->is_state_success() ? HTML_UTIL::span($api_log->get_code(),array("style"=>"color:green","class"=>"fss ml5")) : HTML_UTIL::span($api_log->get_code(),array("style"=>"color:red","class"=>"fss ml5"));
			$url = HTML_UTIL::span($api_log->get_url());
			$table_data[] = array($url.$code,array("data"=>$date,"class"=>"wsnw"),$response,array("data"=>implode(" ",$actions),"class"=>"wsnw w1"));
		}

		HTML_TABLE_UTIL::create()
			->set_data($table_data)
			->set_headings(array("URL","Message","Date",""))
			->set_id("api-log-table")
			->add_class("w100p")
			->render();
		
		$this->show_view("paging");
	} else
		echo "There are currently no api logs";
