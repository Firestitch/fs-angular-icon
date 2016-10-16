<?

	class CMODEL_MESSAGE_USER_PASSWORD_RESET extends CMODEL_MESSAGE {
		
		const VAR_USER_EMAIL 	= '{$user_email}';
		const VAR_RESET_URL 	= '{$reset_url}';
		const VAR_RESET_GUID 	= '{$reset_guid}';
		
		function get_default_name() 		{ return 	"User Account Password Reset"; }
		function get_default_email_body() 	{ return 	"A request has been made to reset the password for the email ".self::VAR_USER_EMAIL.".\n\n".
					        							"Here is your reset code, which you can enter on the password reset page:\n\n".
														self::VAR_RESET_GUID."\n\n".
														"Or you can also click on the link below\n\n".
					         							self::VAR_RESET_URL."\n\n".
					         							"Please note your old password has not been changed. If you did not request the password change, we apologize for the inconvenience."; }
		function get_default_email_subject() 		{ return "User Account Password Reset"; }
	}