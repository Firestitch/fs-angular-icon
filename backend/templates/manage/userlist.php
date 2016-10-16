<?
	$table_data = array();

	foreach($users as $user) {

		$actions = array();
		$actions[] = HTML_UTIL::link("/manage/user/uid:".$user->get_user_id()."/",BASE_MODEL_IMAGE_ICON::get_edit());
		$actions[] = HTML_UTIL::link("javascript:;",BASE_MODEL_IMAGE_ICON::get_delete(),array("class"=>"user-remove","data-uid"=>$user->get_user_id()));		
		$actions[] = HTML_UTIL::link("/manage/doimpersonate/".$user->get_user_id()."/",BASE_MODEL_IMAGE_ICON::get_impresonate(),["target"=>"_blank"]);
		$actions = array("data"=>implode(" ",$actions),"class"=>"w1 wsnw");

		$login_date = CMODEL_FORMAT::create($user->get_last_login())->short_date_time();
		
		$email 		= HTML_UTIL::link($user->get_manage_url(),$user->get_email());
		$user_id 	= HTML_UTIL::link($user->get_manage_url(),$user->get_name());
		
		$table_data[] = array($user_id,$email,$login_date,$user->get_state_name($user->get_state()),$actions);
	}

	HTML_TABLE_UTIL::create()
		->set_data($table_data)
		->set_headings(array("Name","Email","Last Login","State",""))
		->set_width("100%")
		->set_id("user-table")
		->render();
		
	$this->show_view("paging");

