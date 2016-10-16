<?php
	
	class VIEW_APPLICATION_CONTENT extends VIEW {
		
		protected $_site_content_cmodel = null;
		
		function __construct() {
			$this->set_route("application","content");
			$this->disable_authorization();
		}

		function init() {
		
			$content = "";		
			
			if($this->_site_content_cmodel) {
			
				$smarty_cmodel = $this->_site_content_cmodel->get_smarty();
				$smarty_cmodel->assign("head",$this->_site_content_cmodel->get_head());
				$smarty_cmodel->assign("path",$this->_site_content_cmodel->get_path());
				$smarty_cmodel->assign("title",$this->_site_content_cmodel->get_title());
				
				$this->set_title($this->_site_content_cmodel->get_title());
				
				try {
					$content = $this->_site_content_cmodel->get_content(true);
				} catch(Exception $e) {
					
					if(!SYSTEM_MANAGER::is_system_mode_production())
						APPLICATION::add_error_message($e->getMessage());
				}
				
				if($this->_site_content_cmodel->is_body_wrap_none())					
					die($content);
			}

			$this->set_var("content",$content);
		}
		
		function set_site_content($site_content_cmodel) 	{ $this->_site_content_cmodel = $site_content_cmodel; return $this; }
	}

