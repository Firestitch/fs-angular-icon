<?

	class DBQ_GRAPH extends DBQ {

		const STATE_ACTIVE	= "A";
		const STATE_DELETED	= "D";


		const TYPE_TEMPLATE	= "T";
		const TYPE_SITE		= "S";
		const TYPE_SURVEY	= "U";


		static function get_state_list()	{ return array(self::STATE_ACTIVE=>"Active", self::STATE_DELETED=>"Deleted"); }
	

		static function get_type_list()	{ return array(	self::TYPE_TEMPLATE=>"Template",
														self::TYPE_SITE=>"Site",
														self::TYPE_SURVEY=>"Survey"); }

		public function __construct() {
			parent::__construct("graphs", "graph_id");
		}
	}