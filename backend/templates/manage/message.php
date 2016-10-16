<?=HTML_UTIL::get_link("/manage/messages/","Messages",array("class"=>"btn btn-sm btn-default btn-back fr"))?>

<h1>Message</h1>

<? APPLICATION::include_base_template("manage","message",$this->get_vars()) ?>