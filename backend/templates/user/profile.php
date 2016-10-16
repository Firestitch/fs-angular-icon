<h1><?=$user->get_name()?>

	<? if($user->get_user_id()) { ?>
		<a href="javascript:;" class="fl fss mr10" id="avatar">
			<?=$user->get_avatar_small_image(array("class"=>"w40 br50p"))?>
		</a>
	<? } ?>

</h1>

<table>
	<tr>
		<td>Email:</td>
		<td><?=HTML_UTIL::get_input("form[email]",$user->get_email())?></td>
	</tr>
	<tr>
		<td>Password:</td>
		<td><?=HTML_UTIL::get_password("password")?></td>
	</tr>
	<tr>
		<td>Verify Password:</td>
		<td><?=HTML_UTIL::get_password("password_confirm")?></td>
	</tr>
	<tr>
		<td></td>
		<td><a href="javascript:;" class="btn btn-primary save">Save Changes</a></td>
	</tr>
</table>

<script>
$(function() {
	$(".save").go("/user/doprofile",{ data: "#user-profile-form", message: "Successfully saved the changes" });

	$("#avatar").upload({	filters : [ {title : "Image files", extensions : "jpeg,jpg,gif,png"}],
							url: "/user/doavatar",
							error: function(up,err) {
								FF.msg.error("Failed to upload" + (err.file ? " " + err.file.name : "") + ". " + err.message);
								up.refresh();
							},
							uploaded: function(up, file, response) {

								if(response.has_success) {
									$("#avatar img").attr("src",response.data.url);
									$(".navbar .avatar").attr("src",response.data.url);
								}
								else
									FF.msg.error(response.errors);

							},
							added: function(up, file) {
								up.start();
							}});
});

</script>