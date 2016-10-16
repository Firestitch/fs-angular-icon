<? if($process) { ?>

<h3>Process
<? if($process->get_process_id()) { ?>
	<span class="pl5 fss"><?=$process->get_name()?></span>
<? } ?>
</h3>


<div class="cb"></div>


<div id="process-tabs" class="dn">

	<ul>
		<li><a href="#overview"><span>Overview</span></a></li>
	</ul>
	
	<div id="overview">


		<form action="javascript:;" method="post" id="process-form">
			<?
				FORM_UTIL::create()
					->text("Name",$process->get_name())
					->dropdown("form[state]","State",DBQ_PROCESS::get_state_list(),$process->get_state())
					->text("Filename",$process->get_filename())
					->text("Extension",$process->get_extension())
					->text("Description",$process->get_description())
					->text("", HTML_UTIL::link("javascript:;","Save",array("class"=>"btn btn-primary","id"=>"process-save")))
					->render();
			?>

			<?=HTML_UTIL::hidden("pid",$process->get_process_id())?>
		</form>
	</div>
</div>


<script>
	$(function() {
		$("#process-tabs").tabs({ activate: function(e,ui) {
									FF.cookie.set("process-tabs",ui.newTab.index());
								}}).show().tabs("option","active",((idx=FF.request.get("tab")) ? idx : parseInt(FF.cookie.get("process-tabs"))));

		$("#process-save").go("/manage/doprocess",{ data: "#process-form", message: "Successfully saved the process" });
		
	});	
</script>

<? } ?>