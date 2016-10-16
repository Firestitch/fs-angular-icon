<script src="/lib/js/jquery/plugins/browser/jquery.browser.js"></script>
<link href="/lib/js/jquery/plugins/browser/themes/default/styles.css" rel="stylesheet" type="text/css"/> 


<div class="p10">		
	<div id="browser-container"></div>
</div>

<script>
	
	$(function() {	
		$("#browser-container").browser({ root: '', process_url: "<?=$process_url?>", base_path: "<?=$base_path?>" });		
	});
	
</script>
