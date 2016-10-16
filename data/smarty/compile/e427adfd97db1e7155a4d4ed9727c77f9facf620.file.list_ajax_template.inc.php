<?php /* Smarty version Smarty-3.1.17, created on 2016-05-02 12:53:04
         compiled from "C:\Projects\boilerplate\utility\assets\list_ajax_template.inc" */ ?>
<?php /*%%SmartyHeaderCode:23101572785f05e5774-94077524%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    'e427adfd97db1e7155a4d4ed9727c77f9facf620' => 
    array (
      0 => 'C:\\Projects\\boilerplate\\utility\\assets\\list_ajax_template.inc',
      1 => 1458264296,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '23101572785f05e5774-94077524',
  'function' => 
  array (
  ),
  'variables' => 
  array (
    'is_view_format_inline' => 0,
    'is_view_format_popup' => 0,
    'pretty_model' => 0,
    'small_button_class' => 0,
    'hyphen_model' => 0,
    'lower_controller' => 0,
    'lower_task' => 0,
    'relation_field' => 0,
    'relation_field_abr' => 0,
    'is_list_body_blank' => 0,
    'pretty_plural_model' => 0,
    'is_search_form' => 0,
    'has_state' => 0,
    'cmodel_state' => 0,
    'upper_model' => 0,
    'lower_models' => 0,
    'id' => 0,
    'has_priority' => 0,
  ),
  'has_nocache_code' => false,
  'version' => 'Smarty-3.1.17',
  'unifunc' => 'content_572785f073a421_10383610',
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_572785f073a421_10383610')) {function content_572785f073a421_10383610($_smarty_tpl) {?><?php if (!is_callable('smarty_modifier_capitalize')) include 'C:\\Projects\\boilerplate\\framework\\packages\\Smarty\\plugins\\modifier.capitalize.php';
?><?php if ($_smarty_tpl->tpl_vars['is_view_format_inline']->value||$_smarty_tpl->tpl_vars['is_view_format_popup']->value) {?>
<<?php ?>?=HTML_UTIL::link("javascript:;","Add <?php echo smarty_modifier_capitalize($_smarty_tpl->tpl_vars['pretty_model']->value);?>
",array("class"=>"<?php echo $_smarty_tpl->tpl_vars['small_button_class']->value;?>
 btn-primary btn-add fr <?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-update"))?<?php ?>>
<?php } else { ?>
<<?php ?>?=HTML_UTIL::link("/<?php echo $_smarty_tpl->tpl_vars['lower_controller']->value;?>
/<?php echo $_smarty_tpl->tpl_vars['lower_task']->value;?>
/<?php if ($_smarty_tpl->tpl_vars['relation_field']->value) {?><?php echo $_smarty_tpl->tpl_vars['relation_field_abr']->value;?>
:".$<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
."/<?php }?>","Add <?php echo smarty_modifier_capitalize($_smarty_tpl->tpl_vars['pretty_model']->value);?>
",array("class"=>"<?php echo $_smarty_tpl->tpl_vars['small_button_class']->value;?>
 btn-primary btn-add fr"))?<?php ?>>
<?php }?>

<?php if (!$_smarty_tpl->tpl_vars['is_list_body_blank']->value) {?>
<h1><?php echo smarty_modifier_capitalize($_smarty_tpl->tpl_vars['pretty_plural_model']->value);?>
</h1>
<?php }?>

<?php if ($_smarty_tpl->tpl_vars['is_search_form']->value) {?>
<div class="search-form">
	<<?php ?>?=HTML_UTIL::input("search[keyword]","",array("id"=>"<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-search-keyword","placeholder"=>"Search"))?<?php ?>>
	<?php if ($_smarty_tpl->tpl_vars['has_state']->value) {?><<?php ?>?=HTML_UTIL::dropdown("search[state]",array(""=>"All States") + <?php if ($_smarty_tpl->tpl_vars['cmodel_state']->value) {?>CMODEL_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::get_states()<?php } else { ?>DBQ_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::get_state_list()<?php }?>,<?php if ($_smarty_tpl->tpl_vars['cmodel_state']->value) {?>CMODEL_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::STATE_ACTIVE<?php } else { ?>DBQ_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::STATE_ACTIVE<?php }?>,array("class"=>"<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-search-interface"))?<?php ?>><?php }?>
</div>
<?php }?>

<div class="cb"></div>

<div id="<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-list"><<?php ?>?$this->show_view("<?php echo $_smarty_tpl->tpl_vars['lower_models']->value;?>
")?<?php ?>></div>
<?php if ($_smarty_tpl->tpl_vars['relation_field']->value) {?><<?php ?>?=HTML_UTIL::hidden("<?php echo $_smarty_tpl->tpl_vars['relation_field_abr']->value;?>
",$<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
)?<?php ?>><?php }?>

<script>

$(function() {
	
	$("#<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-list").bind("load",function() {
		$(this).load("/<?php echo $_smarty_tpl->tpl_vars['lower_controller']->value;?>
/<?php echo $_smarty_tpl->tpl_vars['lower_task']->value;?>
list/",$("#<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-form").serializeArray(),function() { $(this).trigger("bind") });	
	}).bind("bind",function() {

<?php if ('is_view_format_popup') {?>		$(".<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-update").off().on("click",function() {
		FF.popup.show("/<?php echo $_smarty_tpl->tpl_vars['lower_controller']->value;?>
/<?php echo $_smarty_tpl->tpl_vars['lower_task']->value;?>
/<?php if ($_smarty_tpl->tpl_vars['relation_field']->value) {?><?php echo $_smarty_tpl->tpl_vars['relation_field_abr']->value;?>
:<<?php ?>?=$<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
?<?php ?>>/<?php }?>" + ($(this).data("<?php echo $_smarty_tpl->tpl_vars['id']->value;?>
") ? "<?php echo $_smarty_tpl->tpl_vars['id']->value;?>
:" + $(this).data("<?php echo $_smarty_tpl->tpl_vars['id']->value;?>
") + "/" : ""),600,550, { onClosed: function() { $("#<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-list").trigger("load") } });
		});
<?php }?>
<?php if ($_smarty_tpl->tpl_vars['is_view_format_inline']->value) {?>		$(".<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-update").off().on("click",function() {
			
		FF.msg.clear();
			
		$("#<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-view").load("/<?php echo $_smarty_tpl->tpl_vars['lower_controller']->value;?>
/<?php echo $_smarty_tpl->tpl_vars['lower_task']->value;?>
/", { <?php if ($_smarty_tpl->tpl_vars['relation_field']->value) {?><?php echo $_smarty_tpl->tpl_vars['relation_field_abr']->value;?>
: "<<?php ?>?=$<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
?<?php ?>>", <?php }?> <?php echo $_smarty_tpl->tpl_vars['id']->value;?>
: $(this).data("<?php echo $_smarty_tpl->tpl_vars['id']->value;?>
") } ,function() {
			
			$(".<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-update.add").hide();
			
			$("input[name='<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-cancel']").click(function() {
				
				$("#<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-view").empty();
				$(".<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-update").show();
				$("#<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-list").trigger("load");
				
				return false;
			});
			
			$("input[name='<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-save']").click(function() {
				
				$.post("/<?php echo $_smarty_tpl->tpl_vars['lower_controller']->value;?>
/do<?php echo $_smarty_tpl->tpl_vars['lower_task']->value;?>
/", $("#<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-form").serializeArray(), function(response) {
				
					if(response.has_success) {
						
						FF.msg.success(response.notifies);
						
						$("#<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-view").empty();
						$(".<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-update.add").show();
						$("#<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-list").trigger("load");
						
					} else
						FF.msg.error(response.errors);
				});
				
				return false;
			});				
		});
	});
<?php }?>	
<?php if ($_smarty_tpl->tpl_vars['has_priority']->value) {?>	
		$("#<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-table tbody").sortable({
			helper: function(e, ui) {
				ui.children().each(function() {
					$(this).width($(this).width());
				});
				return ui;
			},
			handle: ".order",
			axis: "y",
			stop: function(event, ui) { 
			
				var data = $(this).sortable("serialize"); 
				
				_table = $(this);
				
				$.post("/<?php echo $_smarty_tpl->tpl_vars['lower_controller']->value;?>
/do<?php echo $_smarty_tpl->tpl_vars['lower_task']->value;?>
order/<?php if ($_smarty_tpl->tpl_vars['relation_field']->value) {?><?php echo $_smarty_tpl->tpl_vars['relation_field_abr']->value;?>
:<<?php ?>?=$<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
?<?php ?>>/<?php }?>",data,function(response) {
					FF.msg.success("Successfully update the order",false,5);
					
					_table.find("tr").each(function(i) {
						$(this).removeClass("table-listing-row-odd").removeClass("table-listing-row-even");
						i % 2 ? $(this).addClass("table-listing-row-odd") : $(this).addClass("table-listing-row-even");
					});
					
				},"json");
			}
		});
<?php }?>
		
		$(".<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-remove").off().on("click",function() {
			if(confirm("Are you sure you would like to delete this <?php echo $_smarty_tpl->tpl_vars['lower_task']->value;?>
?"))
				$.post("/<?php echo $_smarty_tpl->tpl_vars['lower_controller']->value;?>
/do<?php echo $_smarty_tpl->tpl_vars['lower_task']->value;?>
remove/", { <?php echo $_smarty_tpl->tpl_vars['id']->value;?>
: $(this).data("<?php echo $_smarty_tpl->tpl_vars['id']->value;?>
") },
																		function(response) { 
																			if(response.has_success)
																				$("#<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-list").trigger("load"); 
																			else
																				FF.msg.error(response.errors);
																		});

		});

	}).trigger("bind");
	
	$(".<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-search-interface").off().on("change",function() { $("#<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-list").trigger("load") });
	
<?php if ($_smarty_tpl->tpl_vars['is_search_form']->value) {?>			
	$("#<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-search-keyword").autocomplete({
		minLength: 0,
		source: [],
		search: function() { $("#<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-list").trigger("load") }
	});
<?php }?>
});	
</script>		
	
<?php }} ?>
