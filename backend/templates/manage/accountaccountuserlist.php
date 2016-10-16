<?
	$table_data = array();

	foreach($account_users as $account_user) {

		$actions = array();
		$actions[] = HTML_UTIL::get_link("javascript:;",BASE_MODEL_IMAGE_ICON::get_delete(),array("class"=>"account-user-remove","data-auid"=>$account_user->get_account_user_id()));			
		
		$name = HTML_UTIL::get_link($account_user->get_manage_url(),$account_user->get_user()->get_name());

		$table_data[] = array($name,$account_user->get_roles(),$account_user->get_premissions(),array("data"=>implode(" ",$actions),"class"=>"wsnw w1"));
	}

	$html_table = new HTML_TABLE_UTIL();
	$html_table->set_data($table_data);
	$html_table->set_headings(array("User","Roles","Premissions",""));
	$html_table->set_width("100%");
	$html_table->set_id("account-user-table");

	$html_table->set_class("table table-bordered table-striped");
	$html_table->render();
