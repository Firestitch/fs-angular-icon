
<h1>Login</h1>	

<div>
	<table>
		<tr>
			<td>Email:</td>
			<td><?=HTML_UTIL::input("form[email]",$email,array("id"=>"email"))?></td>
		</tr>
		<tr>
			<td>Password:</td>
			<td>
				<?=HTML_UTIL::password("form[password]","",array("id"=>"password"))?>
			</td>
		</tr>
		<tr>
			<td></td>
			<td>	
				<a href="javascript:;" class="btn btn-primary" id="login">Login</a>
				<?=HTML_UTIL::hidden("redirect",SERVER_UTIL::get_request_uri())?>
			</td>
		</tr>		
		<tr>
			<td></td>
			<td colspan="2">No Account Yet? <a href="/user/signup">Sign Up</a>  <a href="/user/forgot/">Forgot Password</a></td>
		</tr>
	</table>
</div>

<script>
	
	$(function() {
		$("#login").go("/user/dologin",$("#form-login"));
		$("#email").val() ? $("#password").select() : $("#email").select();
	});

</script>


