<?

	class CMODEL_CRON extends BCMODEL_CRON {
		
		public function __construct() {
			$this->init(["process_maintenance"=>CMODEL_CRON_SETTING::create()->duration(3)->hour(3)->minute(0)]);
		}
		
		public function process_message_queue() { 		
			$message_queue_cmodel = new BCMODEL_MESSAGE_QUEUE();
			$message_queue_cmodel->process_queue();			
			return true;
		}

		public function process_processes() {
			return CMODEL_PROCESS::process_queued();
		}

	}
	
	
