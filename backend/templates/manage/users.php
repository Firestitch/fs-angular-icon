<?=HTML_UTIL::link("/manage/user","Add User",array("class"=>"fr user-update btn btn-primary btn-sm btn-add"))?>

<h1>Users</h1>

<div class="search-form">
	<?=HTML_UTIL::input("search[keyword]",get_value($search,array("keyword")),array("id"=>"user-search-keyword","placeholder"=>"Search"))?>
	<?=HTML_UTIL::dropdown("search[state]",CMODEL_USER::get_state_list(),get_value($search,array("state")),array("class"=>"user-search-interface"))?>
</div>

<?=HTML_UTIL::get_div($this->get_view("users",true),array("id"=>"user-list"))?>

<script>

	$(function() {

		$("#user-list").bind("load",function() {
			$(this).load("/manage/userlist/",$("#user-form").serializeArray(),function() { $(this).trigger("bind") });
		}).bind("bind",function() {
			
			$(".user-remove").on("click",function() {
				if(confirm("Are you sure you would like to delete this user?"))
					$.post("/manage/douserdelete/", { uid: $(this).data("uid") }, function() { $("#user-list").trigger("load") });
			});
		}).trigger("bind");

		$(".user-search-interface").change(function() { $("#user-list").trigger("load") });
			
		$("#user-search-keyword").autocomplete({
			minLength: 0,
			source: [],
			search: function() { $("#user-list").trigger("load") }
		});

	});	

</script>		
	
