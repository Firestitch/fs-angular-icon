<?
	class VIEW_MANAGE_ARTICLES extends BASE_VIEW_ARTICLE_ARTICLES {

		function __construct() {
			parent::__construct()->set_permission(CMODEL_USER::PERMISSION_BACKEND);

			//S3 Storage
			//$this
			//	->set_asset_base_url(CMODEL_SETTING::get_s3_bucket_url()."/".CMODEL_SETTING::get_s3_bucket())
			//	->set_asset_base_path("/pub/assets/")
			//	->set_articles_path("/manage/articles/action:assets");

			//Local Storage
			$this
				->set_asset_base_url("/public/")
				->set_asset_base_dir(MODEL_PATH::get_public_dir())
				->set_asset_base_path("/assets")
				->set_articles_path("/manage/articles/action:assets");
		}
	}