<?

	class DBQ_GRAPH_OBJECT extends DBQ {

		const STATE_ACTIVE	= "A";
		const STATE_DELETED	= "D";

		static function get_state_list()	{ return array(self::STATE_ACTIVE=>"Active", self::STATE_DELETED=>"Deleted"); }


		const TYPE_RADIOBUTTONS		= "RA";
		const TYPE_LOGIN			= "LG";
		const TYPE_FACEBOOK_LIKE	= "FL";
		const TYPE_SHARE			= "SH";
		const TYPE_FIRST_NAME		= "FN";
		const TYPE_LAST_NAME		= "LN";
		const TYPE_FULL_NAME		= "FU";
		const TYPE_EMAIL			= "EM";
		const TYPE_MOBILE			= "MB";
		const TYPE_DOB				= "BD";
		const TYPE_BRAND_FIELD		= "BF";
		const TYPE_PASSWORD			= "PW";
		const TYPE_OFFER			= "OF";
		const TYPE_REGISTRATION		= "RG";
		const TYPE_ACCOUNT			= "AC";
		const TYPE_TERMS			= "TM";
		const TYPE_MEMBER_OFFERS	= "MO";
		const TYPE_MEMBER_PROGRAMS	= "MP";
		const TYPE_COM_PREFERENCE	= "CF";
		const TYPE_SURVEY			= "SV";
		const TYPE_SURVEY_FIELD		= "SF";
		const TYPE_REDIRECT			= "RD";
		
		static function get_type_list()	{ return array(	self::TYPE_EMAIL=>"Email",
														self::TYPE_DOB=>"Birth Date",
														self::TYPE_FACEBOOK_LIKE=>"Facebook Like",
														self::TYPE_FIRST_NAME=>"First Name",
														self::TYPE_FULL_NAME=>"Full Name",
														self::TYPE_LAST_NAME=>"Last Name",
														self::TYPE_LOGIN=>"Login",
														self::TYPE_MOBILE=>"Mobile Number",
														self::TYPE_RADIOBUTTONS=>"Radio Buttons",
														self::TYPE_SHARE=>"Share",
														self::TYPE_BRAND_FIELD=>"Brand Field",
														self::TYPE_PASSWORD=>"Password",
														self::TYPE_REGISTRATION=>"Registration",
														self::TYPE_OFFER=>"Offer",
														self::TYPE_ACCOUNT=>"Account",
														self::TYPE_TERMS=>"Terms Signoff",
														self::TYPE_MEMBER_OFFERS=>"Member Offers",
														self::TYPE_COM_PREFERENCE=>"Communication Preference",
														self::TYPE_SURVEY=>"Survey",
														self::TYPE_MEMBER_PROGRAMS=>"Members Programs",
														self::TYPE_SURVEY_FIELD=>"Survey Field",
														self::TYPE_REDIRECT=>"Redirect",
														); }

		static function get_grouped_type_list()	{ return array(	"Interactions"=>array(	self::TYPE_LOGIN=>"Login",
																						self::TYPE_SHARE=>"Share",
																						self::TYPE_OFFER=>"Offer",
																						self::TYPE_SURVEY=>"Survey",
																						self::TYPE_REGISTRATION=>"Registration",
																						self::TYPE_TERMS=>"Terms Signoff",
																						self::TYPE_MEMBER_OFFERS=>"Member Offers",
																						self::TYPE_MEMBER_PROGRAMS=>"Member Programs",
																						self::TYPE_REDIRECT=>"Redirect",
																						self::TYPE_FACEBOOK_LIKE=>"Facebook Like"																						
																				),
																"Standard Contact Fields"=>array(	self::TYPE_FULL_NAME=>"Full Name",
																									self::TYPE_FIRST_NAME=>"First Name",
																									self::TYPE_LAST_NAME=>"Last Name",
																									self::TYPE_MOBILE=>"Mobile Number",
																									self::TYPE_EMAIL=>"Email",
																									self::TYPE_DOB=>"Birth Date",
																									self::TYPE_PASSWORD=>"Password",
																									self::TYPE_RADIOBUTTONS=>"Radio Buttons",
																									self::TYPE_ACCOUNT=>"Account",																									
																									self::TYPE_COM_PREFERENCE=>"Communication Preference",
																							)																				
																				); }


		public function __construct() {
			parent::__construct("graph_objects", "graph_object_id");
		}
	}