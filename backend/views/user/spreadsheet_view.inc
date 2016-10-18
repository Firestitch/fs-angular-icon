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

			$json = '{"web":{"client_id":"501877491375-mh8d9doa1p4ntm4ika0boa1uvptel7bu.apps.googleusercontent.com","project_id":"spring-base-135823","auth_uri":"https://accounts.google.com/o/oauth2/auth","token_uri":"https://accounts.google.com/o/oauth2/token","auth_provider_x509_cert_url":"https://www.googleapis.com/oauth2/v1/certs","client_secret":"UwQBZVbxAk-B4TxVhRCXbrB7","redirect_uris":["http://icon.local.firestitch.com/","http://icon.local.firestitch.com/auth"]}}';

			$client = new Google_Client();
			$client->setAuthConfig(JSON_UTIL::decode($json));
			$client->setApplicationName("Client_Library_Examples");
			$client->setDeveloperKey("AIzaSyDolQ6khQ3QEu9d8xByWgR38aXy-hNK42M");
			$client->setAccessType('offline');


			$redirect_uri = 'http://' . $_SERVER['HTTP_HOST']."/auth";

			$client->setRedirectUri($redirect_uri);
			$client->addScope(Google_Service_Sheets::DRIVE." ".Google_Service_Sheets::SPREADSHEETS);

			$token = USER_SESSION::instance()->get_setting("accessToken");

			$client->setAccessToken($token);

			if(!is_null($this->get("authorize"))) {
				$authUrl = $client->createAuthUrl();
				HTTP_UTIL::redirect($authUrl);
			}

			//https://docs.google.com/spreadsheets/d/1tftyNypXdc6bX3EIXH3kG49AV14irkHaxgm6K81jssQ/edit#gid=0

	    	$codepoint_values = explode("\n",FILE_UTIL::get(MODEL_PATH::get_backend_dir().'assets/codepoints'));
	    	$codepoints = [];
			foreach($codepoint_values as &$codepoint) {
				$codepoints[preg_replace("/\s.*/","",$codepoint)] = false;
			}

			$accessToken = $token["access_token"];
			$spreadsheetId = "1tftyNypXdc6bX3EIXH3kG49AV14irkHaxgm6K81jssQ";
			$sheetName = "Sheet1";

			$range = $sheetName."!A2:A";

			$service = new Google_Service_Sheets($client);
			$response = $service->spreadsheets_values->get($spreadsheetId, $range);
			$values = $response->getValues();

			$existing = [];
			if($values) {
				foreach($values as $value) {
					$value = value($value,0);

					$existing[$value] = true;
				}
			}

			$dir = MODEL_PATH::get_backend_dir().'assets/svg-sprite/';
			$files = FILE_UTIL::get_directory_listing($dir,"*.html");

			$codepoints = [];
			foreach($files as $file) {
				if(!preg_match("/-symbol.html/",$file) && preg_match("/svg-sprite-(.*).html/",$file,$match)) {

					$category = $match[1];

					$html = FILE_UTIL::get($dir.$file);

					if(preg_match_all("/\.svg-ic_(.*)_24px/",$html,$matches)) {

						foreach($matches[1] as $value) {
							if(!array_key_exists($value,$existing)) {
								$codepoints[$category][] = $value;
							}
						}
					}
				}
			}

			$range = $sheetName."!A2";

			$data = [];
			foreach($codepoints as $category=>$values) {

				foreach($values as $value) {
					$data[] = [$value,$category,"=IMAGE(\"https://github.com/google/material-design-icons/blob/master/".$category."/2x_web/ic_".$value."_black_24dp.png?raw=true\")"];
				}
			}

			p("Added: ",$data);

			$body = new Google_Service_Sheets_ValueRange(array('values' => $data));
			$params = array('valueInputOption' => "USER_ENTERED");

			$result = $service->spreadsheets_values->update($spreadsheetId, $range,$body ,$params);

			die;



			/*$serviceRequest = new DefaultServiceRequest("");
			$serviceRequest->setSslVerifyPeer(false);
			ServiceRequestFactory::setInstance($serviceRequest);
*/
			$spreadsheetService = new Google\Spreadsheet\SpreadsheetService();
			$worksheetFeed = $spreadsheetService->getPublicSpreadsheet($fileId);


			$worksheet = $worksheetFeed->getByTitle('Sheet1');


			$cellFeed = $worksheet->getCellFeed();

			$batchRequest = new Google\Spreadsheet\Batch\BatchRequest();
			$batchRequest->addEntry($cellFeed->createCell(2, 1, "111"));
			$batchRequest->addEntry($cellFeed->createCell(3, 1, "222"));
			$batchRequest->addEntry($cellFeed->createCell(4, 1, "333"));
			$batchRequest->addEntry($cellFeed->createCell(5, 1, "=SUM(A2:A4)"));

			$batchResponse = $cellFeed->insertBatch($batchRequest);


			//$listFeed = $worksheet->getListFeed();

		/*	foreach ($listFeed->getEntries() as $entry) {
			    $values = $entry->getValues();

			    p($entry);
			}

			$cellFeed = $worksheet->getCellFeed();
*/



			//$listFeed->insert(["name" => "Someone", "age" => 25]);
		}
	}