<?
	require MODEL_PATH::get_backend_dir().'composer/vendor/autoload.php';

	use Google\Spreadsheet\DefaultServiceRequest;
	use Google\Spreadsheet\ServiceRequestFactory;

	class VIEW_USER_SPREADSHEET extends VIEW {

		function __construct() {
			$this
				->disable_authorization()
				->set_form("/user/dohome")
				->set_route("user","spreadsheet");
		}

		function init() {

			$json = '{"web":{"client_id":"501877491375-mh8d9doa1p4ntm4ika0boa1uvptel7bu.apps.googleusercontent.com","project_id":"spring-base-135823","auth_uri":"https://accounts.google.com/o/oauth2/auth","token_uri":"https://accounts.google.com/o/oauth2/token","auth_provider_x509_cert_url":"https://www.googleapis.com/oauth2/v1/certs","client_secret":"UwQBZVbxAk-B4TxVhRCXbrB7"}}';

			$client = new Google_Client();
			$client->setAuthConfig(JSON_UTIL::decode($json));
			$client->setApplicationName("Client_Library_Examples");
			$client->setDeveloperKey("AIzaSyDolQ6khQ3QEu9d8xByWgR38aXy-hNK42M");


			$redirect_uri = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['PHP_SELF'];
			$client->setRedirectUri($redirect_uri);
			$client->addScope(Google_Service_Drive::DRIVE);
/*
			$httpClient = $client->authorize();

			//p($client->getAccessToken());
			$authUrl = $client->createAuthUrl();



			HTTP_UTIL::redirect($authUrl);
			die;
*/

			$code = "4/Pzk4ePsB6Nc5-pjXrljFHBqkXOLjmf-1c04DXKrNkA4#";
			///$accessToken = $client->fetchAccessTokenWithAuthCode($code);

	    	$accessToken = "ya29.Ci9-A0esVNgkUVBRD9u_kIP_x2c6znd8Qcix41tdovF4FxRYY3_tjNzInp-jHEPWvg";

	    	$codepoints = explode("\n",FILE_UTIL::get(MODEL_PATH::get_backend_dir().'assets/codepoints'));

			foreach($codepoints as &$codepoint) {
				$codepoint = explode(" ",$codepoint);
			}

			$serviceRequest = new DefaultServiceRequest($accessToken);
			ServiceRequestFactory::setInstance($serviceRequest);


			/*$serviceRequest = new DefaultServiceRequest("");
			$serviceRequest->setSslVerifyPeer(false);
			ServiceRequestFactory::setInstance($serviceRequest);
*/
			$spreadsheetService = new Google\Spreadsheet\SpreadsheetService();
			$worksheetFeed = $spreadsheetService->getPublicSpreadsheet("1tftyNypXdc6bX3EIXH3kG49AV14irkHaxgm6K81jssQ");


			$worksheet = $worksheetFeed->getByTitle('Sheet1');

			$listFeed = $worksheet->getListFeed();

		/*	foreach ($listFeed->getEntries() as $entry) {
			    $values = $entry->getValues();

			    p($entry);
			}
*/
			$cellFeed = $worksheet->getCellFeed();


			$listFeed->insert(["name" => "Someone", "age" => 25]);
		}
	}