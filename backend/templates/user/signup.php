<h1>Sign Up</h1>
<table>
	<tr>
		<td>Email:</td>
		<td><?=HTML_UTIL::input("email",$user->get_email())?></td>		
	</tr>
	<tr>
		<td>Password:</td>
		<td><?=HTML_UTIL::password("password")?></td>
	</tr>
	<tr>
		<td>Verify Password:</td>
		<td><?=HTML_UTIL::password("password_confirm")?></td>
	</tr>
	<tr>
		<td></td>
		<td>
			<input type="submit" name="cmd_login" value="Signup" class="btn btn-primary" id="save"/>
		</td>		
	</tr>
</table>

<script>
$(function() {
	$("#save").go("/user/dosignup",{ data: $("#user-signup-form") });
});
</script>