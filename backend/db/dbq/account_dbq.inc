<?

	class DBQ_ACCOUNT extends DBQ {

		const STATE_ACTIVE	= "A";
		const STATE_DELETED	= "D";

		static function get_state_list()	{ return array(self::STATE_ACTIVE=>"Active", self::STATE_DELETED=>"Deleted"); }


		const TYPE_DEFAULT	= "1";

		static function get_type_list()	{ return array(self::TYPE_DEFAULT=>"Default"); }

		public function __construct() {
			parent::__construct("accounts", "account_id");
		}
	}