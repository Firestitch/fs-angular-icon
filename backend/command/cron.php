<?
	$DIR_APPLICATION = dirname(dirname(__FILE__))."/";
	$has_bootstrap = @include_once(realpath(dirname(__FILE__)."/../..")."/framework/boot/bootstrap.inc");
	
	if(!$has_bootstrap)		
		die("Failed to load bootstrap");
	
	BASE_APPLICATION::initialize_command_application();
	APPLICATION::get_instance()->initialize();
		
	CMODEL_CRON::create()->run();
