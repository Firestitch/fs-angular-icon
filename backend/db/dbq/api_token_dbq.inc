<?

	class DBQ_API_TOKEN extends DBQ {

		const STATE_ACTIVE	= "A";
		const STATE_INACTIVE= "I";
		const STATE_DELETED	= "D";

		static function get_state_list()	{ return array(self::STATE_ACTIVE=>"Active", self::STATE_INACTIVE=>"Inactive", self::STATE_DELETED=>"Deleted"); }

		public function __construct() {
			parent::__construct("api_tokens", "api_token_id");
		}
	}