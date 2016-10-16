<?

	class DBQ_GRAPH_CONDITION extends DBQ {

		const STATE_ACTIVE	= "A";
		const STATE_DELETED	= "D";

		static function get_state_list()	{ return array(self::STATE_ACTIVE=>"Active", self::STATE_DELETED=>"Deleted"); }

		public function __construct() {
			parent::__construct("graph_conditions", "graph_condition_id");
		}
	}