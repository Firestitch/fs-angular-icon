<?
	class VIEW_MANAGE_ACCOUNTACCOUNTADD extends VIEW {

		protected $_parent_account_id = null;

		function __construct() {
			$this->set_route("manage","accountaccountadd");
			$this->set_permission(CMODEL_USER::PERMISSION_BACKEND);
			$this->set_form("javascript:;");
			$this->type_popup();
		}

		function init() {

			if(is_numeric($parent_account_id=$this->get("paid")))
				$this->_parent_account_id = $parent_account_id;

			$this->set_var("parent_account_id", $this->_parent_account_id);
		}
	}