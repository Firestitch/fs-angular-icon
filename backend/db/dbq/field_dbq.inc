<?
	class DBQ_FIELD extends DBQ {

		const STATE_ACTIVE	= "A";
		const STATE_DELETED	= "D";

		static function get_state_list()	{ return array(self::STATE_ACTIVE=>"Active", self::STATE_DELETED=>"Deleted"); }

		const INTERFACE_SINGLE_LINE_TEXT        = "T";
		const INTERFACE_MULTI_LINE_TEXT         = "U";
		const INTERFACE_MULTI_SELECT_CHECKBOXES = "C";
		const INTERFACE_SINGLE_SELECT_DROPDOWN  = "D";
		const INTERFACE_SINGLE_SELECT_RADIO     = "R";
		const INTERFACE_SINGLE_SELECT_IMAGE     = "I";
		const INTERFACE_DATE_SELECT             = "V";
		const INTERFACE_OPTIN 		           	= "O";
		const INTERFACE_SENTIMENT       		= "S";
		const INTERFACE_RATING		       		= "A";
		const INTERFACE_YES_NO		       		= "Y";

		static function get_interface_list()	{ return array(	self::INTERFACE_SINGLE_LINE_TEXT=>"Single Line of Text",
																self::INTERFACE_MULTI_LINE_TEXT=>"Multiple Lines of Text",
																self::INTERFACE_MULTI_SELECT_CHECKBOXES=>"Multiple Choices from a List",
																self::INTERFACE_SINGLE_SELECT_DROPDOWN=>"One Choice from a Drop-Down",
																self::INTERFACE_SINGLE_SELECT_RADIO=>"One Choice from a List",
																self::INTERFACE_SINGLE_SELECT_IMAGE=>"One Choice from a Image List",
																self::INTERFACE_DATE_SELECT=>"Date",
																self::INTERFACE_RATING=>"Rating",
																self::INTERFACE_SENTIMENT=>"Sentiment",
																self::INTERFACE_YES_NO=>"Yes/No",
																self::INTERFACE_OPTIN=>"Optin"); }
		const MAPPING_DEFAULT	= "1";

		static function get_mapping_list()	{ return array(self::MAPPING_DEFAULT=>"Default"); }

		public function __construct() {
			parent::__construct("fields", "field_id");
		}
	}