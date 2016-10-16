
<div id="header">

	<? if($is_manage_section) { ?>

		<div class="navbar navbar-default">

		  	<div class="navbar-header">
			    <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-ex1-collapse">
			      <span class="sr-only">Toggle navigation</span>
			      <span class="icon-bar"></span>
			      <span class="icon-bar"></span>
			      <span class="icon-bar"></span>
			    </button>
			    <a class="navbar-brand" href="/"> Project Name	</a>
			</div>

			<? if($user && $user->has_permission_backend()) { ?>

				<div class="collapse navbar-collapse">
			    	<ul class="nav navbar-nav">
				    	<li class="dropdown">
				        	<a href="#" class="dropdown-toggle" data-toggle="dropdown">Accounts <b class="caret"></b></a>
				        	<ul class="dropdown-menu">
				          		<li><a href="/manage/users/">Users</a></li>
				        	</ul>
				      	</li>

				   		<li class="dropdown">
				    		<a href="#" class="dropdown-toggle" data-toggle="dropdown">Content <b class="caret"></b></a>
				        	<ul class="dropdown-menu">
								<li><a href="/manage/articles/type:page">Pages</a></li>
								<li><a href="/manage/articles/type:post">Posts</a></li>
								<li><a href="/manage/contentwidgets/">Content Widget</a></li>
								<li><a href="/manage/articles/view:css">Site CSS</a></li>
								<li><a href="/manage/articles/view:js">Site JS</a></li>
								<li><a href="javascript:FF.popup.show('/manage/articles/view:assets','90%','90%')">Site Assets</a></li>
								<li><a href="/manage/messages/">Messages</a></li>
								<li><a href="/manage/messagequeues/">Messages Queue</a></li>
				        	</ul>
				    	</li>

				   		<li class="dropdown">
				    		<a href="#" class="dropdown-toggle" data-toggle="dropdown">Logs <b class="caret"></b></a>
				        	<ul class="dropdown-menu">
								<li><a href="/manage/apilogs">API Logs</a></li>
								<li><a href="/manage/logs">Errors Logs</a></li>
				        	</ul>
				    	</li>

				   		<li class="dropdown">
				    		<a href="#" class="dropdown-toggle" data-toggle="dropdown">Master <b class="caret"></b></a>
				        	<ul class="dropdown-menu">
								<li><a href="/manage/master/">Dashboard</a></li>
								<li><a href="/manage/backups/">Backups</a></li>
								<li><a href="/manage/settings/">Settings</a></li>
								<li><a href="/manage/upgrades/">Upgrades</a></li>
								<li><a href="/manage/crons/">Crons</a></li>
								<li><a href="/manage/processes">Processes</a></li>
								<li><a href="/manage/indexinspector">Index Inspector</a></li>
								<li><a href="/manage/indexes">Regenerate Indexes</a></li>
								<li><a href="/manage/logs">Errors Logs</a></li>
				        	</ul>
				    	</li>
					</ul>

					<ul class="nav navbar-nav navbar-right">

						<li class="dropdown">
					   		<a href="#" class="dropdown-toggle" data-toggle="dropdown"><?=$user->get_avatar_small_image(array("class"=>"w30 br50p mr5"))?> My Account</a>
					   		<ul class="dropdown-menu">
								<li><a href="/user/profile">Profile</a></li>
								<li class="divider"></li>
								<li><a href="/user/dologout">Logout</a></li>
					    	</ul>
					  	</li>
					</ul>
				</div>
			<? } ?>
		</div>
	<? } ?>

	<? if(!$is_manage_section) { ?>


	<div class="navbar navbar-default">
		<div class="navbar-header">
			<button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-ex1-collapse">
			  <span class="sr-only">Toggle navigation</span>
			  <span class="icon-bar"></span>
			  <span class="icon-bar"></span>
			  <span class="icon-bar"></span>
			</button>
			<a class="navbar-brand" href="/"> Project name</a>
		</div>

		<? if($user) { ?>

			<div class="collapse navbar-collapse">
				<ul class="nav navbar-nav navbar-right">
					<li class="dropdown">
				   		<a href="#" class="dropdown-toggle" data-toggle="dropdown"><?=$user->get_avatar_small_image(array("class"=>"w30 br50p mr5 avatar"))?> My Account</i></a>
				   		<ul class="dropdown-menu">
							<li><a href="/user/profile">Profile</a></li>
							<li><a href="/manage">Manage</a></li>
							<li class="divider"></li>
							<li><a href="/user/dologout">Logout</a></li>
				    	</ul>
				  	</li>
				</ul>
		  	</div>
		<? } ?>
	</div>

	<? } ?>
</div>
