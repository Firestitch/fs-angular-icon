<?

	class DBQ_CONTACT extends DBQ {

		const STATE_ACTIVE	= "A";
		const STATE_DELETED	= "D";

		static function get_state_list()	{ return array(self::STATE_ACTIVE=>"Active", self::STATE_DELETED=>"Deleted"); }


		const REGISTERED_DEFAULT	= "1";

		static function get_registered_list()	{ return array(self::REGISTERED_DEFAULT=>"Default"); }


		const OPTIN_DEFAULT	= "1";

		static function get_optin_list()	{ return array(self::OPTIN_DEFAULT=>"Default"); }

		public function __construct() {
			parent::__construct("contacts", "contact_id");
		}
	}