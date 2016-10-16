<?
	class CMODEL_FORMAT extends BCMODEL_FORMAT {
		
		public function __construct($value,$options) {		
			$options["format_timezone"] = value($options,"timezone","America/Toronto");
			parent::__construct($value,$options);
		}
	}