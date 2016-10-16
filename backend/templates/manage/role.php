<?
	$html_form = new HTML_FORM_UTIL();
	$html_form->add_static("Code",$role->get_role());
	$html_form->add_input("form[name]","Name",$role->get_name());
	$html_form->add_static("", HTML_UTIL::get_button("cmd_submit","Update")." ".HTML_UTIL::get_redirect_button("Cancel","/manage/roles/"));
	$html_form->render();

	echo HTML_UTIL::get_hidden_field("rid",$role->get_role_id());