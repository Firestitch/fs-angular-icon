<?
	class ACTION_MANAGE_USERSEARCH extends ACTION_JSON {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			$search = $this->post("search");

			$user_cmodels = HMODEL_USER::create()
									->where("first_name","LIKE","%".$search."%","OR","or-group")
									->where("email","LIKE","%".$search."%","OR","or-group")
									->where("last_name","LIKE","%".$search."%","OR","or-group")
									->where("state","=",CMODEL_USER::STATE_ACTIVE)
									->order("name")
									->limit(15)
									->gets();

			$options = array();
			foreach($user_cmodels as $user_cmodel)
				$options[] = array("label"=>$user_cmodel->get_name()." (".$user_cmodel->get_email().")","uid"=>$user_cmodel->get_user_id());

			die(JSON_UTIL::encode($options));
		}
	}


