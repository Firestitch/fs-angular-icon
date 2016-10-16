<?=HTML_UTIL::get_link("/manage/contentwidgets/","Content Widgets",array("class"=>"btn btn-sm btn-default btn-sm btn-back fr"))?>

<h1>Content Widget</h1>

<? APPLICATION::include_base_template("manage","content_widget",$this->get_vars()) ?>