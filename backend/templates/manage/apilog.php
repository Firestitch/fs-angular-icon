
<? if($next_api_id) { ?>
	<a href="/manage/apilog/alid:<?=$next_api_id?>" class="btn btn-small fr">Next</a>
<? } ?>

<? if($previous_api_id) { ?>
	<a href="/manage/apilog/alid:<?=$previous_api_id?>" class="btn btn-small fr mr5">Back</a>
<? } ?>

<h2 class="heading">API Log</h2>

<div class="cb"></div>

<div id="api_log-tabs">

	<div id="overview">

		<form action="javascript:;" method="post" id="form-api-log">	
			<?
				$html_form = FORM_UTIL::create()
								->text("Direction",$api_log->get_direction_name())
								->text("State",$api_log->get_state_name())
								->text("URL",HTML_UTIL::div($api_log->get_url(),array("class"=>"w800 wwbw")))
								->text("Date",CMODEL_FORMAT::create($api_log->get_create_date())->long_date_time(array("seconds"=>true))." (".CMODEL_FORMAT::create($api_log->get_create_date())->age().")");
				
				if($api_log->get_code())
					$html_form->text("Code",$api_log->get_code());
				
				if($api_log->get_method())
					$html_form->text("Method",$api_log->get_method());
				
				if($api_log->get_headers()) {

					$headers = trim($api_log->get_headers());

					if(strpos($headers,"<")===0)
						$html_form->text("Headers","<pre>".htmlentities(XML_READER_UTIL::get_pretty_xml($headers))."</pre>");
					
					elseif(JSON_UTIL::is_encoded($headers))
						$html_form->text("Headers","<pre>".print_r(JSON_UTIL::decode($headers),true)."</pre>");

					else
						$html_form->text("Headers","<pre>".$headers."</pre>");
				}
				
				$parts = parse_url($api_log->get_url());

				parse_str(get_value($parts,"query"),$parts);

				if($parts)
					$html_form->text("Query","<pre>".print_r($parts,true)."</pre>");
				
				if($api_log->get_message())
					$html_form->text("Message",$api_log->get_message());
				
				if($api_log->get_request()) {

					$request = trim($api_log->get_request());

					if(strpos($request,"<")===0)
						$html_form->text("Request","<pre>".htmlentities(XML_READER_UTIL::get_pretty_xml($request))."</pre>");
					
					elseif(JSON_UTIL::is_encoded($request))
						$html_form->text("Request","<pre>".print_r(JSON_UTIL::decode($request),true)."</pre>");

					else
						$html_form->text("Request","<pre>".$request."</pre>");
				}

				if($api_log->get_response()) {

					$response = trim($api_log->get_response());

					if(strpos($response,"<")===0)
						$html_form->text("Response","<pre>".htmlentities(XML_READER_UTIL::get_pretty_xml($response))."</pre>");

					elseif(JSON_UTIL::is_encoded($response))
						$html_form->text("Response","<pre>".print_r(JSON_UTIL::decode($response),true)."</pre>");

					else
						$html_form->text("Response","<pre>".$response."</pre>");
				}

				$html_form->render();
			?>

			<?=HTML_UTIL::hidden("alid",$api_log->get_api_log_id())?>
		</form>

	</div>
</div>

<script>
	$(function() {
		
		$("#api-log-save").go("/manage/doapilog",{ data: "#form-api-log", message: "Successfully saved the api log" });
		
	});
	
</script>
