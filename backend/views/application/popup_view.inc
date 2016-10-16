<?	
	class VIEW_APPLICATION_POPUP extends BASE_VIEW_APPLICATION_POPUP {

		function __construct() {
			$this->set_route("application","popup");
			parent::__construct();
		}
		
		function init() {
			parent::init();

			$web_asset_manager_cmodel = $this->get_web_asset_manager();

			VIEW_APPLICATION_BODY::add_web_assets($web_asset_manager_cmodel);
			
			$web_asset_manager_cmodel->add_css_app_asset("popup.css");				
		}
	}	