<h1>Master Dashboard</h1>
<?
	echo HTML_UTIL::div($this->get_view("status",true),array("class"=>"fr"));
	
	$table_data[] = array(HTML_UTIL::button("upgrade","Run Upgrade")." ".HTML_UTIL::dropdown("version",$versions,$version,array("class"=>"wa")));
	$table_data[] = array(HTML_UTIL::button("cron","Run Cron"));
	$table_data[] = array(HTML_UTIL::button("test","Run Test"));
	$table_data[] = array(HTML_UTIL::button("init","Run Init"));
	
	HTML_TABLE_UTIL::create()
		->set_data($table_data)
		->disable_css()
		->render();
