<?
	if($this->get_view("paging")->has_records()) {

		$table_data = array();

		foreach($processes as $process) {

			$actions = array();
			$actions[] = HTML_UTIL::link("javascript:;",BASE_MODEL_IMAGE_ICON::get_edit(),array("class"=>"process-update","data-pid"=>$process->get_process_id()));
			$actions[] = HTML_UTIL::link("javascript:;",BASE_MODEL_IMAGE_ICON::get_delete(),array("class"=>"process-remove","data-pid"=>$process->get_process_id()));			
			
			$name = STRING_UTIL::get_propercase(str_replace("_"," ",$process->get_name()),true);

			$name = HTML_UTIL::link("javascript:;",$name,array("class"=>"process-update","data-pid"=>$process->get_process_id()));
		
			$created_time 	= DATE_UTIL::get_medium_date_time($process->get_created_time());
			$start_time 	= DATE_UTIL::get_medium_date_time($process->get_start_time());
			$end_time 		= DATE_UTIL::get_medium_date_time($process->get_end_time());

			$table_data[] = array($name,$process->get_state_name(),$process->get_percent()."%",$process->get_message(),$created_time,$start_time,$end_time,$process->get_notify(),$process->get_filename(),array("data"=>implode(" ",$actions),"class"=>"wsnw w1"));
		}

		HTML_TABLE_UTIL::create()
			->set_data($table_data)
			->set_headings(array("Name","State","Percent","Message","Created","Start","End","Notify","Filename",""))
			->set_width("100%")
			->set_id("process-table")
			->set_class("table table-bordered table-striped")
			->render();
		
		$this->show_view("paging");
	} else
		echo "There are currently no processes";
