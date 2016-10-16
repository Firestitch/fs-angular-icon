<?	
	$DIR_APPLICATION = realpath(dirname(__FILE__)."/../")."/";
	
	$has_bootstrap = include_once(realpath(dirname(__FILE__)."/../../")."/framework/boot/bootstrap.inc");
	
	if(!$has_bootstrap)
		die;
		
	BASE_APPLICATION::initialize_command_application();

	$application = APPLICATION::get_instance();
	$application->initialize();

	$init_cmodel = new CMODEL_INIT();
	$has_success = $init_cmodel->init();	
	
	if($has_success)
		die(0);
	else
		die(101);