<?
	$table_data = array();

	foreach($accounts as $account) {

		$actions = array();
		$actions[] = HTML_UTIL::get_link($account->get_manage_url(),BASE_MODEL_IMAGE_ICON::get_edit());
		$actions[] = HTML_UTIL::get_link("javascript:;",BASE_MODEL_IMAGE_ICON::get_delete(),array("class"=>"account-remove","data-aid"=>$account->get_account_id()));			
		
		$name = HTML_UTIL::get_link($account->get_manage_url(),$account->get_name());

		$table_data[$account->get_account_id()] = array($name,$account->get_state_name(),$account->get_type_name(),array("data"=>implode(" ",$actions),"class"=>"wsnw w1"));
	}

	$html_table = new HTML_TABLE_UTIL();
	$html_table->set_data($table_data);
	$html_table->set_headings(array("Name","State","Type",""));
	$html_table->set_width("100%");
	$html_table->set_id("account-table");
	$html_table->set_row_id_prefix("aids_");

	$html_table->set_class("table table-bordered table-striped");
	$html_table->render();
	
	$this->show_view("paging");
