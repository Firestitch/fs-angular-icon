<?

	$has_bootstrap = include_once(realpath(dirname(__FILE__)."/../..")."/framework/boot/webbootstrap.inc");

	if(!$has_bootstrap)
		header("location: /unavailable/");
		
	$application = APPLICATION::get_instance();
	$application->initialize();
	$application->process();


