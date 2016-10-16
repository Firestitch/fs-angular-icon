<?
	class CMODEL_FIELD extends MODEL_COMPLEX {
		
		protected $_field_option_cmodels 	= array();
		protected $_configs 				= array();
	
		public function __construct() {
			$this->register_dbo(new DBO_FIELD);
		}

		public function is_state_active()						{ return $this->get_state()==DBQ_FIELD::STATE_ACTIVE; }
		public function is_state_deleted()						{ return $this->get_state()==DBQ_FIELD::STATE_DELETED; }
		public function is_interface_default()					{ return $this->get_interface()==DBQ_FIELD::INTERFACE_DEFAULT; }
		public function is_mapping_default()					{ return $this->get_mapping()==DBQ_FIELD::MAPPING_DEFAULT; }
		public function get_state_name()						{ return get_value(DBQ_FIELD::get_state_list(),$this->get_state()); }
		public function get_interface_name()					{ return get_value(DBQ_FIELD::get_interface_list(),$this->get_interface()); }
		public function get_class()								{ return get_value($this->get_interface_class_list(),$this->get_interface()); }
		public function get_manage_url()						{ return "/manage/field/fid:".$this->get_field_id()."/"; }

		public function is_interface_single_line_text()			{ return $this->get_interface()==DBQ_FIELD::INTERFACE_SINGLE_LINE_TEXT; }
		public function is_interface_multi_line_text()			{ return $this->get_interface()==DBQ_FIELD::INTERFACE_MULTI_LINE_TEXT; }
		public function is_interface_multi_select_checkboxes()	{ return $this->get_interface()==DBQ_FIELD::INTERFACE_MULTI_SELECT_CHECKBOXES; }
		public function is_interface_single_select_dropdown()	{ return $this->get_interface()==DBQ_FIELD::INTERFACE_SINGLE_SELECT_DROPDOWN; }
		public function is_interface_optin()					{ return $this->get_interface()==DBQ_FIELD::INTERFACE_OPTIN; }
		public function is_interface_single_select_radio()		{ return $this->get_interface()==DBQ_FIELD::INTERFACE_SINGLE_SELECT_RADIO; }
		public function is_interface_date_select()				{ return $this->get_interface()==DBQ_FIELD::INTERFACE_DATE_SELECT; }
		public function is_interface_sentiment()				{ return $this->get_interface()==DBQ_FIELD::INTERFACE_SENTIMENT; }
		public function is_interface_rating()					{ return $this->get_interface()==DBQ_FIELD::INTERFACE_RATING; }
		public function is_interface_yes_no()					{ return $this->get_interface()==DBQ_FIELD::INTERFACE_YES_NO; }
		public function is_interface_single_select_image()		{ return $this->get_interface()==DBQ_FIELD::INTERFACE_SINGLE_SELECT_IMAGE; }
		
		public function get_configs()							{ return $this->_configs; }
		public function get_config($name,$default=null)			{ return get_value($this->_configs,$name,$default); }
		public function set_config($name,$value)				{ $this->_configs[$name] = $value; return $this; }
		public function set_configs($value)						{ $this->_configs = $value; return $this; }
		public function set_field_options($value) 				{ $this->_field_option_cmodels = $value; return $this; }

		public function get_field_option_configs()	{

			$configs = array();
			if($this->is_interface_single_select_image())
				$configs = array(array("name"=>"image-url","label"=>"Image URL"));

			return $configs;
		}
		
		static function get_interface_class_list()	{ return array(	DBQ_FIELD::INTERFACE_SINGLE_LINE_TEXT=>"line",
																	DBQ_FIELD::INTERFACE_MULTI_LINE_TEXT=>"mutiline",
																	DBQ_FIELD::INTERFACE_MULTI_SELECT_CHECKBOXES=>"checkbox",
																	DBQ_FIELD::INTERFACE_SINGLE_SELECT_DROPDOWN=>"dropdown",
																	DBQ_FIELD::INTERFACE_SINGLE_SELECT_RADIO=>"radiobutton",
																	DBQ_FIELD::INTERFACE_SENTIMENT=>"sentiment",
																	DBQ_FIELD::INTERFACE_DATE_SELECT=>"date",
																	DBQ_FIELD::INTERFACE_SINGLE_SELECT_IMAGE=>"imagebutton",
																	DBQ_FIELD::INTERFACE_RATING=>"rating",
																	DBQ_FIELD::INTERFACE_YES_NO=>"yesno",
																	DBQ_FIELD::INTERFACE_OPTIN=>"option"); }		

		public function interface_has_options() {
				return 	$this->is_interface_multi_select_checkboxes() || $this->is_interface_single_select_dropdown() || 
						$this->is_interface_single_select_radio() || $this->is_interface_optin() || $this->is_interface_rating()
						|| $this->is_interface_sentiment() || $this->is_interface_yes_no() || $this->is_interface_single_select_image();
		}

		public function is_interface_text() {
				return 	$this->is_interface_single_line_text() || $this->is_interface_multi_line_text();
		}		

		public function get_field_options($load=false,$field_option_hmodel=null) {
			
			if($load && !$this->_field_option_cmodels) {
				if(!$field_option_hmodel)
					$field_option_hmodel = HMODEL_FIELD_OPTION::create()->filter_state_active();
				$field_option_hmodel->where("field_id","=",$this->get_field_id());
				$this->_field_option_cmodels = $field_option_hmodel->gets();
			}
			return $this->_field_option_cmodels;
		}

		public function get_field_option_list() { return ARRAY_UTIL::listing($this->get_field_options(true),"get_label","get_field_option_id"); }

		public function render_display($value) {

			$list = array();

			if(	$this->is_interface_multi_select_checkboxes() || $this->is_interface_single_select_dropdown() || 
				$this->is_interface_single_select_radio() || $this->is_interface_optin() || $this->is_interface_rating())
					$list = ARRAY_UTIL::listing($this->get_field_options(true),"get_label","get_field_option_id");

			$html = "";
			if($this->is_interface_text())
				$html = $value;

			if($this->is_interface_yes_no())
				$html = get_value(array(1=>"Yes",0=>"No"),$value);

			return $html;
		}

		public function get_option_list($selected=array()) {
			
			$list = array();			
			if(	$this->interface_has_options()) {
					
					$field_option_hmodel = HMODEL_FIELD_OPTION::create();

					if($selected)
						$field_option_hmodel->where("field_option_id","IN",$selected);

					$list = ARRAY_UTIL::listing($this->get_field_options(true,$field_option_hmodel),"get_label","get_field_option_id");
				}

			elseif($this->is_interface_sentiment()) 
				$list = array(1=>"Positive",0=>"Negative");

			elseif($this->is_interface_yes_no())
				$list = array(1=>"Yes",0=>"No");

			$list = $selected ? ARRAY_UTIL::names($list,$selected) : $list;

			return $list;
		}

		public function render($name,$options=array()) {

			$attribs = array();

			if(get_value($options,"required"))
				$attribs["data-validation"] = "required";

			$html = "";
			$list = array();
			$default = get_value($options,"default");
			
			if(	$this->is_interface_multi_select_checkboxes() || $this->is_interface_single_select_dropdown() || 
				$this->is_interface_single_select_radio() || $this->is_interface_optin() || $this->is_interface_rating())
					$list = ARRAY_UTIL::listing($this->get_field_options(true),"get_label","get_field_option_id");

			if($this->is_interface_single_line_text()) 
				$html = HTML_UTIL::input($name,$default,$attribs);
			
			if($this->is_interface_multi_line_text())
				$html = HTML_UTIL::textarea($name,$default,$attribs);

			if($this->is_interface_multi_select_checkboxes()) {

				if(get_value($options,"required"))
					$attribs["data-validation"] = "checkboxes";

				$html = HTML_UTIL::checkboxes($name,$list,$default,$attribs);
			}

			if($this->is_interface_optin()) {
				
				$html .= HTML_UTIL::div(HTML_UTIL::checkbox($name."[optin]",1,get_value($options,"optin",1),array(),$this->get_config("optin_all_label")),array("class"=>"optin-all"));
				
				$html .= HTML_UTIL::div( HTML_UTIL::div("Select from available messages:",array("class"=>"label")).
										 HTML_UTIL::checkboxes($name,$list,$default),array("class"=>"optin-individual"));
			}

			if($this->is_interface_single_select_dropdown())
				$html = HTML_UTIL::dropdown($name,$list,$default,$attribs);

			if($this->is_interface_single_select_radio())
				$html = HTML_UTIL::radiobuttons($name,$list,$default,$attribs);

			if($this->is_interface_sentiment()) {

				$default = is_numeric($default) ? (int)$default : null;
			
				$html .= HTML_UTIL::radiobutton($name,1,"Positive",$default==1,array(),array("class"=>"positive"));
				$html .= HTML_UTIL::span("");
				$html .= HTML_UTIL::radiobutton($name,0,"Negative",$default===0,array(),array("class"=>"negative"));
			}

			if($this->is_interface_yes_no())
			$html = HTML_UTIL::radiobuttons($name,array(1=>"Yes",0=>"No"),$default,array(),false," ");

			if($this->is_interface_rating())
				$html = HTML_UTIL::radiobuttons($name,$list,$default,array(),false,"");

			if($this->is_interface_single_select_image()) {
				$images = array();

				$field_option_cmodels = $this->get_field_options(true);

				$grid = 12/count($field_option_cmodels);

				foreach($field_option_cmodels as $field_option_cmodel) 
					$images[] = '<div class="large-'.$grid.' columns"><label>'.HTML_UTIL::radiobutton($name,$field_option_cmodel->get_field_option_id()).
										HTML_UTIL::image(get_value($field_option_cmodel->get_configs(),"image-url")).'<span>'.$field_option_cmodel->get_label().'</span></label></div>';
				
			
				$html = implode("",$images);
			}

			return HTML_UTIL::div($html,array("class"=>"field field-".$this->get_class()));
		}

		public function delete() {
			$this->set_state(DBQ_FIELD::STATE_DELETED);
			return $this->save();
		}
		
		public function save() {
			
			$this->get_dbo("field")->set_configs(JSON_UTIL::encode($this->_configs));

			$has_success = false;
			if(is_numeric(self::get_field_id())) {
				$has_success = $this->get_dbo("field")->update();
				
			} else {

				if(!$this->get_state())
					$this->set_state(DBQ_FIELD::STATE_ACTIVE);

				if(!$this->get_guid())
					$this->set_guid(MISC_UTIL::get_guid());

				if($this->is_interface_optin() && $this->get_config("optin_all_label")) 
					$this->set_config("optin_all_label","Notify from time to time on news and offers");
					
				$has_success = $this->get_dbo("field")->insert();
			}
			
			return $has_success;
		}

		public function populate($data,$untag=false,$previous=false) {
						
			if(@array_key_exists("configs",$data)) {
						
				$configs = get_value($data,"configs",array());
				
				$this->_configs = (array)JSON_UTIL::decode($configs);

				unset($data["configs"]);
			}

			parent::populate($data,$untag,$previous);
		}
	}