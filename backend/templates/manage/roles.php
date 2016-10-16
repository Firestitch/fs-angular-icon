<?
	echo HTML_UTIL::get_link("/manage/role/","Add role",array("class"=>"btn btn-sm"));

	$table_data = array();

	foreach($roles as $role) {

		$actions = array();
		$actions[] = HTML_UTIL::get_link("/manage/role/".$role->get_role_id()."/","view");

		$table_data[] = array($role->get_role_id(),$role->get_role(),$role->get_name(),implode(" ",$actions));
	}

	$html_table = new HTML_TABLE_UTIL();
	$html_table->set_data($table_data);
	$html_table->set_headings(array("Role id","Role","Name",""));
	$html_table->render();
	$this->show_view("paging");