<?

	class DBQ_GRAPH_NODE extends DBQ {

		const STATE_ACTIVE	= "A";
		const STATE_DELETED	= "D";

		static function get_state_list()	{ return array(self::STATE_ACTIVE=>"Active", self::STATE_DELETED=>"Deleted"); }


		const TYPE_SITE		= "S";
		const TYPE_SURVEY	= "U";


		static function get_type_list()	{ return array(	self::TYPE_SITE=>"Site",
														self::TYPE_SURVEY=>"Survey"); }


		const DEFAULT_DEFAULT	= "1";

		static function get_default_list()	{ return array(self::DEFAULT_DEFAULT=>"Default"); }


		const PREVIEW_DEFAULT	= "1";

		static function get_preview_list()	{ return array(self::PREVIEW_DEFAULT=>"Default"); }

		public function __construct() {
			parent::__construct("graph_nodes", "graph_node_id");
		}
	}