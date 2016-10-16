<?
	$DIR_APPLICATION = realpath(dirname(__FILE__)."/../")."/";
	
	$has_bootstrap = include_once(realpath(dirname(__FILE__)."/../../")."/framework/boot/bootstrap.inc");
	
	if(!$has_bootstrap)
		die;
		
	BASE_APPLICATION::initialize_command_application();

	$application = APPLICATION::get_instance();
	$application->initialize();

	$maintenance_api_cmodel = new BCMODEL_INSTANCE_API();
	$maintenance_api_cmodel->listen();