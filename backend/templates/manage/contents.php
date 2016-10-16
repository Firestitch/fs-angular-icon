<?=HTML_UTIL::get_link("/manage/content/","Add Content",array("class"=>"btn btn-primary btn-sm btn-add fr"))?>

<h1>Site Contents</h1>

<? APPLICATION::include_base_template("manage","contents",$this->get_vars()) ?>