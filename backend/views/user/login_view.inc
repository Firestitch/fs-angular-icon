<?

	class VIEW_USER_LOGIN extends VIEW {

		protected $_is_remember_me 	= false;
		protected $_email		= "";
		protected $_uri			= "";

		function __construct() {
			parent::__construct("user","login",[],"form-login")
				->disable_authorization();

			$this->_is_remember_me	= !is_empty(HTML_COOKIE_UTIL::is_cookie_exist("rememberme"));

			if($this->_is_remember_me)
				$this->_email = HTML_COOKIE_UTIL::get_cookie("rememberme");
		}

		function init() {

			if(USER_SESSION::instance()->has_user())
				HTTP_UTIL::redirect("/user/home");

			if($email=$this->get("email"))
				$this->_email = $email;

			$this->set_var("api_key",MODEL_FACEBOOK::get_api_key());
			$this->set_var("secret_key",MODEL_FACEBOOK::get_secret_key());
			$this->set_var("is_remember_me",$this->_is_remember_me);
			$this->set_var("uri",$this->_uri);
			$this->set_var("email",$this->_email);
		}

		function set_uri($uri) { $this->_uri = $uri; }
		function set_email($email) { $this->_email = $email; }
	}