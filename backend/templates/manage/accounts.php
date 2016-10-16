<?=HTML_UTIL::get_link("/manage/account/","Add Account",array("class"=>"btn btn-sm btn-primary btn-add fr"))?>
<h1>Accounts</h1>

<table>
<tbody>
	<td><?=HTML_UTIL::get_input("search[keyword]","",array("id"=>"account-search-keyword","placeholder"=>"Search:"))?></td>
	<td><?=HTML_UTIL::get_dropdown("search[state]",DBQ_ACCOUNT::get_state_list(),"",array("class"=>"account-search-interface"))?></td></tr>
</tbody>
</table>

<div id="account-list"><?$this->show_view("accounts")?></div>

<script>
	$(function() {

		$("#account-list").bind("load",function() {
			$(this).load("/manage/accountlist/",$("#account-form").serializeArray(),function() { $(this).trigger("bind") });	
		}).bind("bind",function() {
		
			$(".account-update").on("click",function() {
				FF.popup.show("/manage/account/" + ($(this).data("aid") ? "aid:" + $(this).data("aid") + "/" : ""),600,500, { onClosed: function() { $("#account-list").trigger("load") } });
			});
			
			$(this).sortable({
				helper: function(e, ui) {
					ui.children().each(function() {
						$(this).width($(this).width());
					});
					return ui;
				},
				handle: ".order",
				axis: "y",
				stop: function(event, ui) { 
				
					var data = $(this).sortable("serialize"); 
					
					_table = $(this);
					
					$.post("/manage/doaccountorder/",data,function(response) {
						FF.msg.success("Successfully update the order",false,5);
						
						_table.find("tr").each(function(i) {
							$(this).removeClass("table-listing-row-odd").removeClass("table-listing-row-even");
							i % 2 ? $(this).addClass("table-listing-row-odd") : $(this).addClass("table-listing-row-even");
						});
						
					},"json");
				}
			});

			$(".account-remove").on("click",function() {
				if(confirm("Are you sure you would like to delete this account?"))
					$.post("/manage/doaccountremove/", { aid: $(this).data("aid") },function() { $("#account-list").trigger("load"); });
			});
		}).trigger("bind");
		
		$(".account-search-interface").on("change",function() { $("#account-list").trigger("load") });
		
		$("#account-search-keyword").autocomplete({
			minLength: 0,
			source: [],
			search: function() { $("#account-list").trigger("load") }
		});
		
	});	
</script>		
	
