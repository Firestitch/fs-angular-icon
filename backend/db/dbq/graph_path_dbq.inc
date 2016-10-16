<?

	class DBQ_GRAPH_PATH extends DBQ {

		const STATE_ACTIVE	= "A";
		const STATE_DELETED	= "D";

		static function get_state_list()	{ return array(self::STATE_ACTIVE=>"Active", self::STATE_DELETED=>"Deleted"); }


		const TRIGGER_DEFAULT	= "1";

		static function get_trigger_list()	{ return array(self::TRIGGER_DEFAULT=>"Default"); }

		public function __construct() {
			parent::__construct("graph_paths", "graph_path_id");
		}
	}