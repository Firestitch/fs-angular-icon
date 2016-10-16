<? if($user->get_user_id()) { ?>

<a href="/manage/users/" class="btn btn-default btn-sm btn-back fr">Users</a>
<h1 class="cf">
	<? if($user->get_user_id()) { ?>
		<a href="javascript:;" class="fss mr10 fl" id="avatar"><?=$user->get_avatar_small_image(array("class"=>"w35 br50p"))?></a>
	<? } ?>

	<?=$user->get_name()?>
</h1>

<? } ?>

<div id="user-tabs" class="dn">

	<ul>
		<li><a href="#overview"><span>Overview</span></a></li>
	</ul>

	<div id="overview">

		<form id="form-user" action="javascript:;">

			<?
				FORM_UTIL::create()
					->dropdown("form[state]","State",CMODEL_USER::get_state_list(),$user->get_state())
					->input("form[first_name]","First Name",$user->get_first_name())
					->input("form[last_name]","Last Name",$user->get_last_name())
					->input("form[email]","Email",$user->get_email())
					->input("password","Password","")
					->dropdown("form[permissions]","Permissions",CMODEL_USER::get_grouped_permission_list(),$user->get_permissions(),array(),array("multiple"=>true))
					->text("", HTML_UTIL::button("user-save","Save",array("class"=>"btn btn-primary")))
					->render();
			?>

			<?=HTML_UTIL::hidden("uid",$user->get_user_id())?>
		</form>

	</div>
</div>

<script>

	$(function() {
		$("#user-tabs").tabs().show();

		$("input[name='user-save']")
		.go("/manage/douser",{ 	data: "#form-user",
								message: "Successfully saved the user",
								success: function(response) {
									$("input[name='password']").val("");
								}});

		$("#avatar")
		.transmit({	url: "/manage/douseravatar",
					multiple: false,
					accept: "image",
					autostart: true,
					form: $("#form-user"),
					success: function(response) {

						if(response.has_success)
							$("#avatar img").attr("src",response.data.url);
						else
							FF.msg.error(response.errors);
					}});
	});

</script>