<? if($index) { ?>
<div class="fr"><a href="/manage/indexinspector/" class="btn btn-default btn-sm btn-back">Indexinspects</a></div>


<h1>Index
<? if($index->get_index_id()) { ?>
	<span class="pl5 fss"><?=$index->get_name()?></span>
<? } ?>
</h1>

<div class="cb"></div>

<div id="index-tabs" class="dn">

	<ul>
		<li><a href="#overview"><span>Overview</span></a></li>
	</ul>

	<div id="overview">

		<form action="javascript:;" method="post" id="index-form">
			<?
				FORM_UTIL::create()
					->input("form[name]","Name",$index->get_name())
					->input("form[primary_keyword]","Primary Keyword",implode(",",$index->get_primary_keyword()))
					->input("form[secondary_keyword]","Secondary Keyword",implode(",",$index->get_secondary_keyword()))
					->input("form[image_url]","Image Url",$index->get_image_url())
					->dropdown("form[type]","Type",CMODEL_INDEX::get_types(),$index->get_type())
					->input("form[icon]","Icon",$index->get_icon())
					->input("form[icon_color]","Icon Color",$index->get_icon_color())
					->dropdown("form[state]","State",CMODEL_INDEX::get_states(),$index->get_state())

					->input("form[customer_user_id]","Customer User ID",$index->get_customer_user_id())
					->input("form[agent_user_id]","Agent User ID",$index->get_agent_user_id())
					->input("form[account_id]","Account ID",$index->get_account_id())
					->input("form[initiative_id]","Initiative ID",$index->get_initiative_id())
					->input("form[project_id]","Project ID",$index->get_project_id())
					->input("form[step_id]","Step ID",$index->get_step_id())
					->input("form[file_id]","File ID",$index->get_file_id())

					->text("", HTML_UTIL::button("index-save","Save",array("id"=>"index-save","class"=>"btn btn-primary")))
					->render();
			?>

			<?=HTML_UTIL::hidden("iid",$index->get_index_id())?>
		</form>

	</div>
</div>

<script>
	$(function() {

		$("#index-tabs").tabs({ activate: function(e,ui) {
									FF.cookie.set("indexinspect-tabs",ui.newTab.index());
								}}).show().tabs("option","active",((idx=FF.request.get("tab")) ? idx : parseInt(FF.cookie.get("indexinspect-tabs"))));

		$("#index-save").go("/manage/doindexinspect",{ data: "#index-form", message: "Successfully saved the index" });

	});
</script>

<? } ?>