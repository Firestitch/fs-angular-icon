<?
	class CMODEL_SMS extends BASE_CMODEL_SMS {

		protected $_number 			= "";
		protected $_user 			= "";
		protected $_password 		= "";
		
		public function __construct($user,$password,$number) {
			$this->_user 		= $user;
			$this->_password 	= $password;
			$this->_number 		= $number;
		}

		public function send($to,$message) {

			$url = "https://api.twilio.com/2010-04-01/Accounts/".$this->_user."/SMS/Messages.json";
			
			$from 	= preg_replace("/[^\d]/","",$this->_number);
			$to 	= preg_replace("/[^\d]/","",$to);

			if(strlen($this->_number)>=10)
				$from 	= "+1".$this->_number;

			if(strlen($to)>=10)
				$to 	= "+1".$to;
			
			$data["From"] 	= $from;
			$data["To"] 	= $to;
			$data["Body"] 	= $message;

			$http_transport_util = new HTTP_TRANSPORT_UTIL();
			$http_transport_util->post($url,$data,array(),$this->_user,$this->_password);

			$body = $http_transport_util->get_http_response()->get_json_body();

			$status = get_value($body,"status");

			if($status!="queued")
				throw new Exception(get_value($body,"message"),get_value($body,"code"));
				
			return $body;
		}
	}
