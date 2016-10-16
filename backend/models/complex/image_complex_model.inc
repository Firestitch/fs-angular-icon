<?
	class CMODEL_IMAGE extends BCMODEL_IMAGE {
	
		public static function create($directory,$path,$name,$extension,$sizes,$timestamp=null) {
			return parent::create($directory,$path,$name,$extension,$sizes,$timestamp)->use_filename_timestamp(true);
		}
	}