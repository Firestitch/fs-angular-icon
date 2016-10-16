<h3 class="fl">Processes</h3>

<div class="cb"></div>


<table>
<tbody>
	<td><?=HTML_UTIL::input("search[keyword]","",array("id"=>"process-search-keyword","placeholder"=>"Search"))?></td>
	<td><?=HTML_UTIL::dropdown("search[state]",array(""=>"") + DBQ_FF_PROCESS::get_state_list(),"",array("class"=>"process-search-interface"))?></td></tr>
</tbody>
</table>

<div id="process-list"><?$this->show_view("processes")?></div>

<script>
	$(function() {

		$("#process-list").bind("load",function() {
			$(this).load("/manage/processlist/",$("#process-form").serializeArray(),function() { $(this).trigger("bind"); });
		}).bind("bind",function() {
			$(".process-update").off().on("click",function() {
				FF.popup.show("/manage/process/" + ($(this).data("pid") ? "pid:" + $(this).data("pid") + "/" : ""),600,550, { onClosed: function() { $("#process-list").trigger("load") } });
			});


			$(".process-remove").off().on("click",function() {
				if(confirm("Are you sure you would like to delete this process?"))
					$.post("/manage/doprocessremove/", { pid: $(this).data("pid") },function() { $("#process-list").trigger("load"); });
			});
		}).trigger("bind");

		$(".process-search-interface").off().on("change",function() { $("#process-list").trigger("load") });

		$("#process-search-keyword").autocomplete({
			minLength: 0,
			source: [],
			search: function() { $("#process-list").trigger("load") }
		});
	});
</script>

