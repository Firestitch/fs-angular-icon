<?

	class DBQ_ACCOUNT_USER extends DBQ {

		const STATE_ACTIVE	= "A";
		const STATE_DELETED	= "D";

		static function get_state_list()	{ return array(self::STATE_ACTIVE=>"Active", self::STATE_DELETED=>"Deleted"); }


		const DEFAUT_DEFAULT	= "1";

		static function get_defaut_list()	{ return array(self::DEFAUT_DEFAULT=>"Default"); }

		public function __construct() {
			parent::__construct("account_users", "account_user_id");
		}
	}