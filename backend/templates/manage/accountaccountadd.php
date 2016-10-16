<h1>Add Account(s)</h1>

<div class="cb"></div>

Enter in an account name or specify multiple account names delimited by commas.

<br>

<?=HTML_UTIL::input("name","",array("class"=>"w99p"))?>
<a href="javascript:;" id="add" class="btn">Add Accounts</a>

<?=HTML_UTIL::get_hidden("paid",$parent_account_id)?>

<script>
	$(function() {
		$("input[name='name']").focus();
		
		$("#add").go("/manage/doaccountaccountadd",{ data: $("form"), success: function(response) {
			if(response.has_success) 
				parent.FF.popup.hide();
			}});
	
	});
</script>
