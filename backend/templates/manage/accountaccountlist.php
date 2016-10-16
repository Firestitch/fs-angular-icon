
<div id="account-accounts">
	<? render_accounts($account) ?>
</div>

<? 

function render_accounts($account) {

	if(!$account || !$account->get_accounts())
		return;

	echo "<ol>";
	
	foreach($account->get_accounts() as $account) {
		
		$handle = $account->get_parent_account_id() ? ' class="handle"' : "";
		$id = $account->get_parent_account_id() ?  "aid_".$account->get_account_id() : "aid_root";

		$users = "No assigned users";

		if($account->get_account_users()) {

			if(count($account->get_account_users())>2)
				$users = "2+ users";
			else {
				$users = array();
				foreach($account->get_account_users() as $account_user)
					$users[] = HTML_UTIL::link($account_user->get_user()->get_manage_url(),$account_user->get_user()->get_name());
				$users = implode(", ",$users);
			}
		}

		$actions = array();
		$actions[] = HTML_UTIL::get_link("javascript:;",BASE_MODEL_IMAGE_ICON::get_edit(),array("class"=>"account-update","data-aid"=>$account->get_account_id()));
		$actions[] = HTML_UTIL::get_link("javascript:;",BASE_MODEL_IMAGE_ICON::get_add(),array("class"=>"account-add","data-paid"=>$account->get_account_id()));
		
		if($account->get_parent_account_id())
			$actions[] = HTML_UTIL::get_link("javascript:;",BASE_MODEL_IMAGE_ICON::get_delete(),array("class"=>"account-remove","data-aid"=>$account->get_account_id()));

		echo '<li id="'.$id.'">
					<div'.$handle.'>'.
					$account->get_name().

					'<span class="pl5">('.$users.')	</span>'.
					'<span class="actions">'.
					implode(" ",$actions).
					'</span>
					</div>';
				
		render_accounts($account);

		echo '</li>';
	}	

	echo "</ol>";
}
