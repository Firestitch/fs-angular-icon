<?
	class CMODEL_WEB_ASSET_MANAGER extends BCMODEL_WEB_ASSET_MANAGER {
				

		function add_daterangepicker() 	{ return $this	
													->add_js_lib("daterange/jquery.daterange.js")
													->add_js_lib("daterangepicker/moment.js")
													->add_js_app("daterangepicker/daterangepicker.js")
													->add_js_app("daterangepicker/daterangepicker.css"); }


	}