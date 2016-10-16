<?
	class CMODEL_SETTING extends BCMODEL_SETTING {

		const SETTING_SITE_NAME				= "SITE_NAME";
		const SETTING_SMTP_HOST				= "SMTP_HOST";
		const SETTING_SMTP_USER				= "SMTP_USER";
		const SETTING_SMTP_PASSWORD			= "SMTP_PASSWORD";
		const SETTING_SMTP_PORT				= "SMTP_PORT";
		const SETTING_SMTP_FROM_EMAIL		= "SMTP_FROM_EMAIL";
		const SETTING_SMTP_FROM_NAME		= "SMTP_FROM_NAME";
		const SETTING_AWS_ACCESS_KEY_ID		= "AWS_ACCESS_KEY_ID";
		const SETTING_AWS_SECRET_ACCESS_KEY	= "AWS_SECRET_ACCESS_KEY";
		const SETTING_S3_BUCKET				= "S3_BUCKET";
		const SETTING_S3_BUCKET_DOMAIN		= "S3_BUCKET_DOMAIN";
		const SETTING_S3_NAMESPACE			= "S3_NAMESPACE";
		const SETTING_APP_URL    			= "APP_URL";
		const SETTING_SMS_USER          	= "SMS_USER";
		const SETTING_SMS_PASSWORD        	= "SMS_PASSWORD";
		const SETTING_SMS_NUMBER        	= "SMS_NUMBER";
		const SETTING_BITLY_LOGIN       	= "BITLY_LOGIN";
		const SETTING_BITLY_API_KEY       	= "BITLY_API_KEY";

		function get_settings() {

			return [	$this->create_input(self::SETTING_SITE_NAME,"Site Name",""),
						$this->create_input(self::SETTING_SMTP_HOST,"SMTP Host Server","email-smtp.us-east-1.amazonaws.com","SMTP"),
						$this->create_input(self::SETTING_SMTP_USER,"SMTP User name","AKIAJWQSL7Y7I2FEP5JA","SMTP"),
						$this->create_input(self::SETTING_SMTP_PASSWORD,"SMTP Password","As31GCZvhxhO631MZivF6a/jdOk6yEyjDrWkLohlY9l/","SMTP"),
						$this->create_input(self::SETTING_SMTP_PORT,"SMTP Port","587","SMTP"),
						$this->create_input(self::SETTING_SMTP_FROM_EMAIL,"From Email Address","noreply@firestitch.com","SMTP"),
						$this->create_input(self::SETTING_SMTP_FROM_NAME,"From Email Name","noreply@firestitch.com","SMTP"),
						$this->create_input(self::SETTING_AWS_ACCESS_KEY_ID,"AWS Access Key ID","AKIAI2DI6CFOYA3JAI5Q","S3"),
						$this->create_input(self::SETTING_AWS_SECRET_ACCESS_KEY,"AWS Secret Access Key","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","S3"),
						$this->create_input(self::SETTING_S3_BUCKET,"S3 Bucket","firestitch-dev","S3"),
						$this->create_input(self::SETTING_S3_BUCKET_DOMAIN,"S3 Bucket Domain","s3.amazonaws.com","S3"),
						$this->create_input(self::SETTING_S3_NAMESPACE,"S3 Namespace",MISC_UTIL::guid(6),"S3"),
						$this->create_input(self::SETTING_APP_URL,"App URL"),
					    $this->create_input(self::SETTING_SMS_USER,"SMS Username","AC267b2ba71a8c4c48ab84c83fa1d088a4","SMS"),
					    $this->create_input(self::SETTING_SMS_PASSWORD,"SMS Password","be9f3bff43b5ac068ca62f223a802268","SMS"),
					    $this->create_input(self::SETTING_SMS_NUMBER,"SMS Number","7543336500","SMS"),
					    $this->create_input(self::SETTING_BITLY_LOGIN,"Bit.ly Login","firestitch","Bit.ly"),
					    $this->create_input(self::SETTING_BITLY_API_KEY,"Bit.ly API Key","R_18d22a7cb4f1f30f04bde14e4cffea65","Bit.ly")

					];
		}
	}