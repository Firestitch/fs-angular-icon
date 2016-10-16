<?php	
	$has_bootstrap = include_once(realpath(dirname(__FILE__)."/../..")."/framework/boot/webbootstrap.inc");

	if(!$has_bootstrap) 
		die;
	
	$application = APPLICATION::get_instance();
	$application->initialize();
	
	$uri = APPLICATION::get_instance()->get_uri();
	
	$view = null;
	
	if($uri->is_action_task()) {

		$action = APPLICATION::get_action("s",preg_replace("/^do/","",$uri->get_task()));

		if($action) {
			$action->process();
			$action->post_process();
			die;
		}
		
	} else {
		
		$view = APPLICATION::get_view("s",$uri->get_task());

		if($view && $view->is_type_popup()) {
			
			$base_view = APPLICATION::get_view_instance("application","popup");
			$base_view->set_view("body",$view);

			$view = $base_view;
		}
	}

	if(!$view)
		$view = APPLICATION::get_view("s","index");

	$view->show();
	
	