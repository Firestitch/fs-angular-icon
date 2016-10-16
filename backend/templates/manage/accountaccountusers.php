<div class="fr">
	<form id="account-user-form">
		<?=HTML_UTIL::input("user","",array("class"=>"m0","placeholder"=>"Add User: Email or name"))?>
		<?=HTML_UTIL::hidden("aid",$account_id)?>
		<?=HTML_UTIL::hidden("uid","")?>
		<?=HTML_UTIL::link("javascript:;","Add",array("class"=>"btn btn-sm add-user"))?>
	</form>
</div>

<div class="cb"></div>

<form id="account-users-form">

<table>
<tbody>
	<td><?=HTML_UTIL::get_input("search[keyword]","",array("id"=>"account-user-search-keyword","placeholder"=>"Search"))?></td>
	<td><?=HTML_UTIL::get_dropdown("search[state]",DBQ_ACCOUNT_USER::get_state_list(),"",array("class"=>"account-user-search-interface"))?></td></tr>
</tbody>
</table>

<div id="account-user-list"><?$this->show_view("account_users")?></div>

</form>

<script>
	$("#account-user-list").bind("load",function() {
		a = $("#account-users-form").serializeArray();
		a.push({ name: "aid", value: "<?=$account_id?>" });
		$(this).load("/manage/accountaccountuserlist/",a);
	});
	$(".account-user-update").off().on("click",function() {
		FF.popup.show("/manage/accountaccountuser/aid:<?=$account_id?>/" + ($(this).data("auid") ? "auid:" + $(this).data("auid") + "/" : ""),600,500, { onClosed: function() { $("#account-user-list").trigger("load") } });
	});
	
	
	$(".account-user-remove").off().on("click",function() {
		if(confirm("Are you sure you would like to delete this accountaccountuser?"))
			$.post("/manage/doaccountaccountuserremove/", { auid: $(this).data("auid") },function() { $("#account-user-list").trigger("load"); });
	});

	$(".account-user-search-interface").off().on("change",function() { $("#account-user-list").trigger("load") });
	
	$(function() {
			
		$("#account-user-search-keyword").autocomplete({
			minLength: 0,
			source: [],
			search: function() { $("#account-user-list").trigger("load") }
		});


		$(".add-user").click(function() {
			
			$.post("/manage/doaccountuseradd",$("#account-user-form").serialize(),function(response) {
				if(response.has_success) {
					$("#account-user-list").trigger("load");
					FF.msg.success("Successfully add the user to the account");
				} else
					FF.msg.error(response.errors);
			});
		});

		$("input[name='user']").autocomplete({
			minLength: 0,
			source: [],
			select: function(e,el) {
				$("#uid").val(el.item.uid);
			},
			open: function(){
		        	$(this).autocomplete('widget').css('z-index', 100000);
		       		 return false;
	   		 },
			source: function(request,response) {
		      	 	 $.post("/manage/dousersearch", { search: request.term },function(data) {
		      		      response(data);
		        	},"json");
			}});

	});	
</script>		
	
