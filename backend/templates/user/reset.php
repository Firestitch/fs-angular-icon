<h1>Password Reset</h1>	

<? if($guid) { ?>
	
	<table>
		<tr>
			<td>New Password:</td>
			<td><?=HTML_UTIL::password("password")?></td>
		</tr>
		<tr>
			<td>Confirm New Password:</td>
			<td><?=HTML_UTIL::password("password_confirm")?></td>
		</tr>		
		<tr>
			<td></td><td>
				<a href="javascript:;" class="btn btn-primary" id="reset">Reset Password</a>
			</td>
		</tr>
	</table>

	<input name="guid" type="hidden" value="<?=$guid;?>" />	
<? } ?>
