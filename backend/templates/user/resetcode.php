<h2>Reset Code Confirmation</h2>

<div class="box">	
	
	<table>
		
		<tr>
			<td colspan="2">An email with the password reset code has been sent. Please note that it might take up to 10 minutes to arrive. Do not forget to check your spam/junk folder in your email application.</td>
		</tr>
		<tr>
			<td class="w1 wsnw">Reset Code:</td>
			<td><?=HTML_UTIL::input("guid",$guid,array("class"=>"w500"))?></td>
		</tr>		
		<tr>
			<td></td><td>
				<a href="javascript:;" class="btn btn-primary" id="continue">Continue</a>
			</td>
		</tr>
	</table>
</div>