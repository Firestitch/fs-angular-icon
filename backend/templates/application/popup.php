<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
<head>
	<title></title>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
	<? $web_asset_manager->render(false) ?>
</head>
<body id="<?=$body_id?>" class="<?=$body_class?>">

	<div id="body-wrap">
		<? $this->show_view("messages"); ?>
		<? $this->show_view("body"); ?>
		<? $this->show_view("debugmessages"); ?>
	</div>
</body>
</html>
