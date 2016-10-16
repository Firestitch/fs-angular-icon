<?=HTML_UTIL::get_link("/manage/contentwidget/","Add Content Widget",array("class"=>"btn btn-sm btn-primary btn-sm btn-add fr"))?>

<h1>Content Widgets</h1>

<? APPLICATION::include_base_template("manage","content_widgets",$this->get_vars()) ?>