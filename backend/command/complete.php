<?	
	$DIR_APPLICATION = realpath(dirname(__FILE__)."/../")."/";
	
	$has_bootstrap = include_once(realpath(dirname(__FILE__)."/../../")."/framework/boot/bootstrap.inc");
	
	if(!$has_bootstrap)
		die;
		
	BASE_APPLICATION::initialize_command_application();

	$application = APPLICATION::get_instance();
	$application->initialize();

	$upgrade_cmodel = new BCMODEL_UPGRADE();
	$has_success = $upgrade_cmodel->mark_all_completed();
		
	if($has_success)
		die(0);
	else
		die(101);