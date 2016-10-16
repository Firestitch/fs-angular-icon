<a href="/manage/accounts/" class="btn btn-default btn-sm btn-back fr">Accounts</a>

<h1>Account
<? if($account->get_account_id()) { ?>
	<span class="pl5 fss"><?=$account->get_name()?></span>
<? } ?>
</h1>

<div id="account-tabs" class="dn">

	<ul>
		<li><a href="#overview"><span>Overview</span></a></li>

		<? if($account->get_account_id()) { ?>
			<li><a href="/manage/accountaccounts/aid:<?=$account->get_account_id()?>"><span>Accounts</span></a></li>
			<li><a href="/manage/accountsites/aid:<?=$account->get_account_id()?>"><span>Sites</span></a></li>
			<li><a href="/manage/survey/aid:<?=$account->get_account_id()?>"><span>Surveys</span></a></li>
		<? } ?>
	</ul>
	
	<div id="overview">

		<form action="javascript:;" method="post" id="form-account">	
			<?
				FORM_UTIL::create()
					->dropdown("form[state]","State",DBQ_ACCOUNT::get_state_list(),$account->get_state())
					->input("form[name]","Name",$account->get_name())
					->dropdown("form[type]","Type",DBQ_ACCOUNT::get_type_list(),$account->get_type())
					->text("", HTML_UTIL::link("javascript:;","Save",array("class"=>"btn btn-default","id"=>"account-save")))
					->render();
			?>

			<?=HTML_UTIL::hidden("aid",$account->get_account_id())?>
		</form>

	</div>
</div>

<script>
	$(function() {
		
		$("#account-tabs").tabs().show();

		$("#account-save").go("/manage/doaccount",{ data: "#form-account", message: "Successfully saved the account" });
		
	});
	
</script>