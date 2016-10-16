<h1>Account
<? if($account->get_account_id()) { ?>
	<span class="pl5 fss"><?=$account->get_name()?></span>
<? } ?>
</h1>


<div id="account-account-tabs">

	<ul>
		<li><a href="#overview"><span>Overview</span></a></li>
		<? if($account->get_account_id()) { ?>
			<li><a href="/manage/accountaccountusers/aid:<?=$account->get_account_id()?>"><span>Users</span></a></li>
		<? } ?>		
	</ul>
	
	<div id="overview">

		<?
			$html_form = new HTML_FORM_UTIL();
			$html_form->add_dropdown("form[state]","State",DBQ_ACCOUNT::get_state_list(),$account->get_state());
			//$html_form->add_dropdown("form[type]","Type",DBQ_ACCOUNT::get_type_list(),$account->get_type());
			$html_form->add_input("form[name]","Name",$account->get_name());
			$html_form->add_static("", HTML_UTIL::get_button("account-save","Save",array("id"=>"account-save"))." ".HTML_UTIL::get_button("account-cancel","Cancel",array("type"=>"button","onclick"=>"parent.FF.popup.hide()")));
			$html_form->render();
		?>
	</div>
</div>

<?=HTML_UTIL::get_hidden("aid",$account->get_account_id())?>
<?=HTML_UTIL::get_hidden("bid",$account->get_account_id())?>
<?=HTML_UTIL::get_hidden("paid",$account->get_parent_account_id())?>

<script>
	$(function() {
		$("input[name='form[name]']").focus();

		$("#account-save").go("/manage/doaccountaccount/",{ data: $("#account-form"), message: "Successfully saved the account" });

		$("#account-account-tabs").tabs();
	});
</script>
