<h1 class="fl">Accounts</h1>
<div class="cb"></div>


<table>
<tbody>
	<tr><td>Search: </td>
	<td><?=HTML_UTIL::get_input("search[keyword]","",array("id"=>"account-search-keyword"))?></td>
	<td><?=HTML_UTIL::get_dropdown("search[state]",array("all"=>"All",DBQ_ACCOUNT::STATE_ACTIVE=>"Active"),get_value($search,"state"),array("class"=>"account-search-interface"))?></td></tr>
</tbody>
</table>

<div id="account-list"><?$this->show_view("accounts")?></div>

<script>
	
	$(function() {
	
		$("#account-list").bind("load",function() {
			
			a = $("#account-form").serializeArray();
			a.push({ name: "raid", value: "<?=$root_account_id?>" });

			$(this).load("/manage/accountaccountlist/",a,function() {  $(this).trigger("bind") });
		
		}).bind("bind",function() {		
			
			$("#account-accounts ol ol").nestedSortable({
					handle: 'div.handle',
					items: "li",
					toleranceElement: "> div",
					
					stop: function(event, ui) {
						data = { raid: "<?=$root_account_id?>" };
						data.nested = $("#account-accounts ol ol").nestedSortable("toArray",{ startDepthCount: 1 });
				
						$.ajax("/manage/doaccountaccountorder", { data: data, 
																type: "POST",
																dataType: "json",
																success: function(response){
																	if(response.has_success)
																		FF.msg.success("Successfully saved the changes");
																}});
						
					}});

			$(".account-update").on("click",function() {
				FF.popup.show("/manage/accountaccount/" + ($(this).data("aid") ? "aid:" + $(this).data("aid") + "/" : ""),750,500, { onClosed: function() { $("#account-list").trigger("load") } });
			});	

			$(".account-add").on("click",function() {
				FF.popup.show("/manage/accountaccountadd/paid:" + $(this).data("paid"),600,350, { onClosed: function() { $("#account-list").trigger("load") } });
			});	
			
			$(".account-remove").on("click",function() {
				if(confirm("Are you sure you would like to delete this account account?"))
					$.post("/manage/doaccountaccountremove/", { aid: $(this).data("aid") },function() { $("#account-list").trigger("load"); });
			});		
		}).trigger("bind");
			
		$("#account-search-keyword").autocomplete({
			minLength: 0,
			source: [],
			search: function() { $("#account-list").trigger("load") }
		});

		$(".account-search-interface").on("change",function() { $("#account-list").trigger("load") });
	
	});	
</script>		
	
