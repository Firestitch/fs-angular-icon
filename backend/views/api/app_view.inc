<?
	class VIEW_API_APP extends VIEW_API_BASE {

		public function require_api_token() 	{ return false; }
		public function skip_group() 			{ return true; }

		public function init() {

			if($this->is_get()) {
	
				//$this
				//	->data("countries",MODEL_COUNTRY::get_countries())
				//	->data("footer",CMODEL_SITE_CONTENT_WIDGET::get("FOOTER"));
			}
		}

		public function wsdl() {
			return array(	"endpoints"=>array(	array(	"path"=>"app/init",
														"method"=>"get",
														"response"=>array()),

			));
		}		
	}