<div id="api-log">

	<div class="search-form">
		<table>
			<tr>
				<td>
					<?=HTML_UTIL::input("search[keyword]","",array("id"=>"api-log-search-keyword","placeholder"=>"Search"))?>
				</td>
				<td>
					<?=HTML_UTIL::dropdown("search[state]",array(""=>"All") + CMODEL_API_LOG::get_states(),"",array("class"=>"api-log-search-interface"))?>
				</td>				
				<td>
					<?=HTML_UTIL::dropdown("search[direction]",array(""=>"All") + CMODEL_API_LOG::get_directions(),"",array("class"=>"api-log-search-interface"))?>
				</td>
				<td>
					<span class="date"></span>
				</td>
			</tr>
		</table>
	</div>


	<div class="cb"></div>

	<div id="api-log-list"><?$this->show_view("api_logs")?></div>
</div>

<script>

$(function() {
	
	$("#api-log-list").bind("load",function() {
		$(this).load("/manage/apiloglist/",$("#api-log-form").serializeArray(),function() { $(this).trigger("bind") });	
	}).bind("bind",function() {

		$(".api-log-update").off().on("click",function() {
			FF.popup.show("/manage/apilog/" + ($(this).data("alid") ? "alid:" + $(this).data("alid") + "/" : ""),"90%","90%", { onClosed: function() { $("#api-log-list").trigger("load") } });
		});
		
		$(".api-log-remove").off().on("click",function() {
			if(confirm("Are you sure you would like to delete this apilog?"))
				$.post("/manage/doapilogremove/", { alid: $(this).data("alid") },
																		function(response) { 
																			if(response.has_success)
																				$("#api-log-list").trigger("load"); 
																			else
																				FF.msg.error(response.errors);
																		});

		});

	}).trigger("load");
	
	$(".api-log-search-interface").off().on("change",function() { $("#api-log-list").trigger("load") });
	
	$("#api-log .search-form .date")
	.daterange({ 	start: {name: "search[start_date]" },
					end: { 	name: "search[end_date]" },
					select: function() { $("#api-log-list").trigger("load"); }}).daterange("select");
			
	$("#api-log-search-keyword").autocomplete({
		minLength: 0,
		source: [],
		search: function() { $("#api-log-list").trigger("load") }
	});
});	
</script>		
	
