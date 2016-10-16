<?
	class HMODEL_LOGIN extends HMODEL {
	
		protected $_select_fields = array("logins.*");
		
		public function __construct() {
			return $this->register_dbq(DBQ_LOGIN::create());
		}
		
		public function gets() {			
			$logins = $this->get_dbq()->select($this->_select_fields);

			$login_cmodels = array();			
			foreach($logins as $login) {
				$login_cmodel = CMODEL_LOGIN::create()->populate($login,true,false);
				$this->apply_properties($login_cmodel,$login);
				$login_cmodels[] = $login_cmodel;
			}
			
			if(!$login_cmodels)
				return array();
			
			$this->map_one($login_cmodels,$this->handler("user_handler"),"user","user","user");

			return $login_cmodels;
		}
		
		public function set_login_ids($values)	{ return $this->where(".login_id","IN",$values); }
		public function set_login_id($value)	{ return $this->where(".login_id","=",$value); }
		
		public static function create($defaults=true) {
			return $defaults ? parent::create() : parent::create();
		}		
	
		public function load_users($user_hmodel=null) {
			return $this->handler("user_handler",$user_hmodel ? $user_hmodel : HMODEL_USER::create());
		}
	}