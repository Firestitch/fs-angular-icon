<?
	require MODEL_PATH::get_backend_dir().'composer/vendor/autoload.php';

	use Google\Spreadsheet\DefaultServiceRequest;
	use Google\Spreadsheet\ServiceRequestFactory;

	class VIEW_AUTH_INDEX extends VIEW {

		function __construct() {
			$this
				->disable_authorization()
				->set_route("auth","index");
		}

		function init() {

			$json = '{"web":{"client_id":"501877491375-mh8d9doa1p4ntm4ika0boa1uvptel7bu.apps.googleusercontent.com","project_id":"spring-base-135823","auth_uri":"https://accounts.google.com/o/oauth2/auth","token_uri":"https://accounts.google.com/o/oauth2/token","auth_provider_x509_cert_url":"https://www.googleapis.com/oauth2/v1/certs","client_secret":"UwQBZVbxAk-B4TxVhRCXbrB7"}}';

			$client = new Google_Client();
			$client->setAuthConfig(JSON_UTIL::decode($json));
			$client->setApplicationName("Client_Library_Examples");
			$client->setDeveloperKey("AIzaSyDolQ6khQ3QEu9d8xByWgR38aXy-hNK42M");


			$redirect_uri = 'http://' . $_SERVER['HTTP_HOST']."/auth";

			$client->setRedirectUri($redirect_uri);
			$client->addScope(Google_Service_Drive::DRIVE);

			$accessToken = USER_SESSION::instance()->get_setting("accessToken");

			if($code=$this->get("code")) {

				$accessToken = $client->fetchAccessTokenWithAuthCode($code);

				USER_SESSION::instance()->set_setting("accessToken",$accessToken);
			}

			HTTP_UTIL::redirect("/");
			die;
		}
	}