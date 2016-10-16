<h1>Indexes</h1>

<div class="search-form">
	<?=HTML_UTIL::input("search[keyword]","",array("id"=>"index-search-keyword","placeholder"=>"Search"))?>
	<?=HTML_UTIL::dropdown("search[state]",array(""=>"All States") + CMODEL_INDEX::get_states(),CMODEL_INDEX::STATE_ACTIVE,array("class"=>"index-search-interface"))?>
	<?=HTML_UTIL::dropdown("search[type]",array(""=>"All Types") + CMODEL_INDEX::get_types(),"",array("class"=>"index-search-interface"))?>
</div>

<div class="cb"></div>

<div id="index-list"><?$this->show_view("indexes")?></div>

<script>

$(function() {

	$("#index-list").bind("load",function() {
		$(this).load("/manage/indexinspectlist/",$("#index-form").serializeArray(),function() { $(this).trigger("bind") });
	}).bind("bind",function() {

		$(".index-update").off().on("click",function() {
		FF.popup.show("/manage/indexinspect/" + ($(this).data("id") ? "id:" + $(this).data("id") + "/" : ""),600,550, { onClosed: function() { $("#index-list").trigger("load") } });
		});


		$(".index-remove").off().on("click",function() {
			if(confirm("Are you sure you would like to delete this indexinspect?"))
				$.post("/manage/doindexinspectremove/", { id: $(this).data("id") },
																		function(response) {
																			if(response.has_success)
																				$("#index-list").trigger("load");
																			else
																				FF.msg.error(response.errors);
																		});

		});

	}).trigger("bind");

	$(".index-search-interface").off().on("change",function() { $("#index-list").trigger("load") });


	$("#index-search-keyword").autocomplete({
		minLength: 0,
		source: [],
		search: function() { $("#index-list").trigger("load") }
	});
});
</script>

