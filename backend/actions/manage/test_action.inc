<?
	class ACTION_MANAGE_TEST extends ACTION {

		function __construct() {
			parent::__construct()
				->set_permission(CMODEL_USER::PERMISSION_BACKEND);
		}

		function process() {

			p("E:/projects/POS/OUT/XML/3608/invoice2013-04-22.xml");

			$file = FILE_UTIL::get("E:/projects/POS/OUT/XML/3608/invoice2013-04-22.xml");

			p(XML_READER_UTIL::get_pretty_xml($file));

			die;
		}
	}


