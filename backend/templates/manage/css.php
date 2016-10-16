
	<form>	
		<div id="css-editor" class="dn"><?=XSS_UTIL::encode($css)?></div>
	</form>


<script>
	$(function() {

		$("#css-editor").coder({"save":{ method: "ajax",
										url: "/manage/docss/",
										message: "Successfully saved the css",
										success: function(response) {
											
										}}});
	});
</script>									
