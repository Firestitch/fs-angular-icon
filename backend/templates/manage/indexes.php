<form id="form-manage-indexes">

	<h1>Regenerate Indexes</h1>
	<?
		FORM_UTIL::create()
			->checkboxes("indexes","Indexes",CMODEL_INDEX::get_types())
			->text("",HTML_UTIL::link("javascript:;","Regenerate",array("class"=>"btn btn-primary","id"=>"save-manage-indexes")))
			->render();
	?>
</form>

<script>

	$("#save-manage-indexes")
	.go("/manage/doindexes",
		{ 	data: $("#form-manage-indexes"),
			success: function(response) {
				FF.msg.success("Successfully queued for indexing");
			}
		});

</script>