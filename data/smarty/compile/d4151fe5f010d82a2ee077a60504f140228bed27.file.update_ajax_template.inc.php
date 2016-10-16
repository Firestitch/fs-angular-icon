<?php /* Smarty version Smarty-3.1.17, created on 2016-05-02 12:53:03
         compiled from "C:\Projects\boilerplate\utility\assets\update_ajax_template.inc" */ ?>
<?php /*%%SmartyHeaderCode:6119572785efd9d0c2-21130207%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    'd4151fe5f010d82a2ee077a60504f140228bed27' => 
    array (
      0 => 'C:\\Projects\\boilerplate\\utility\\assets\\update_ajax_template.inc',
      1 => 1458264296,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '6119572785efd9d0c2-21130207',
  'function' => 
  array (
  ),
  'variables' => 
  array (
    'lower_model' => 0,
    'is_interface_popup' => 0,
    'relation_field_abr' => 0,
    'lower_controller' => 0,
    'relation_field_controller' => 0,
    'relation_field' => 0,
    'small_button_class' => 0,
    'pretty_relation_field' => 0,
    'lower_task_plural' => 0,
    'lower_task' => 0,
    'pretty_model' => 0,
    'primary_key' => 0,
    'has_name' => 0,
    'hyphen_model' => 0,
    'dependent_objects' => 0,
    'object' => 0,
    'columns' => 0,
    'k' => 0,
    'v' => 0,
    'cmodel_state' => 0,
    'upper_model' => 0,
    'id' => 0,
  ),
  'has_nocache_code' => false,
  'version' => 'Smarty-3.1.17',
  'unifunc' => 'content_572785eff092c0_47078919',
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_572785eff092c0_47078919')) {function content_572785eff092c0_47078919($_smarty_tpl) {?><?php if (!is_callable('smarty_modifier_capitalize')) include 'C:\\Projects\\boilerplate\\framework\\packages\\Smarty\\plugins\\modifier.capitalize.php';
?><<?php ?>? if($<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
) { ?<?php ?>>
<?php if (!$_smarty_tpl->tpl_vars['is_interface_popup']->value) {?>
<?php if ($_smarty_tpl->tpl_vars['relation_field_abr']->value) {?>
<div class="fr"><a href="/<?php echo $_smarty_tpl->tpl_vars['lower_controller']->value;?>
/<?php echo $_smarty_tpl->tpl_vars['relation_field_controller']->value;?>
/<?php echo $_smarty_tpl->tpl_vars['relation_field_abr']->value;?>
:<<?php ?>?=$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
->get_<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
()?<?php ?>>" class="<?php echo $_smarty_tpl->tpl_vars['small_button_class']->value;?>
 btn-back"><?php echo smarty_modifier_capitalize($_smarty_tpl->tpl_vars['pretty_relation_field']->value);?>
</a></div>
<?php } else { ?>
<div class="fr"><a href="/<?php echo $_smarty_tpl->tpl_vars['lower_controller']->value;?>
/<?php echo $_smarty_tpl->tpl_vars['lower_task_plural']->value;?>
/" class="<?php echo $_smarty_tpl->tpl_vars['small_button_class']->value;?>
 btn-back"><?php echo $_smarty_tpl->smarty->registered_plugins[Smarty::PLUGIN_MODIFIER]['pluralize'][0][0]->smarty_modifier_pluralize(smarty_modifier_capitalize($_smarty_tpl->tpl_vars['lower_task']->value));?>
</a></div>
<?php }?><?php }?>


<h1><?php echo smarty_modifier_capitalize($_smarty_tpl->tpl_vars['pretty_model']->value);?>

<<?php ?>? if($<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
->get_<?php echo $_smarty_tpl->tpl_vars['primary_key']->value;?>
()) { ?<?php ?>>
	<span class="pl5 fss"><?php if ($_smarty_tpl->tpl_vars['has_name']->value) {?><<?php ?>?=$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
->get_name()?<?php ?>><?php } else { ?><<?php ?>?=$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
->get_<?php echo $_smarty_tpl->tpl_vars['primary_key']->value;?>
()?<?php ?>><?php }?></span>
<<?php ?>? } ?<?php ?>>
</h1>

<div class="cb"></div>

<div id="<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
-tabs" class="dn">

	<ul>
		<li><a href="#overview"><span>Overview</span></a></li>
	</ul>
	
	<div id="overview">

		<form action="javascript:;" method="post" id="<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-form">	
			<<?php ?>?
				FORM_UTIL::create()
<?php if ($_smarty_tpl->tpl_vars['dependent_objects']->value) {?>/*	
<?php  $_smarty_tpl->tpl_vars['field'] = new Smarty_Variable; $_smarty_tpl->tpl_vars['field']->_loop = false;
 $_smarty_tpl->tpl_vars['object'] = new Smarty_Variable;
 $_from = $_smarty_tpl->tpl_vars['dependent_objects']->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
foreach ($_from as $_smarty_tpl->tpl_vars['field']->key => $_smarty_tpl->tpl_vars['field']->value) {
$_smarty_tpl->tpl_vars['field']->_loop = true;
 $_smarty_tpl->tpl_vars['object']->value = $_smarty_tpl->tpl_vars['field']->key;
?>					->dropdown("form[<?php echo $_smarty_tpl->tpl_vars['object']->value;?>
_id]","<?php echo $_smarty_tpl->smarty->registered_plugins[Smarty::PLUGIN_MODIFIER]['pretty'][0][0]->get_pretty($_smarty_tpl->tpl_vars['object']->value);?>
",$<?php echo $_smarty_tpl->tpl_vars['object']->value;?>
_list,$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
->get_<?php echo $_smarty_tpl->tpl_vars['object']->value;?>
_id())
<?php } ?>*/<?php }?>
<?php  $_smarty_tpl->tpl_vars['v'] = new Smarty_Variable; $_smarty_tpl->tpl_vars['v']->_loop = false;
 $_smarty_tpl->tpl_vars['k'] = new Smarty_Variable;
 $_from = $_smarty_tpl->tpl_vars['columns']->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
foreach ($_from as $_smarty_tpl->tpl_vars['v']->key => $_smarty_tpl->tpl_vars['v']->value) {
$_smarty_tpl->tpl_vars['v']->_loop = true;
 $_smarty_tpl->tpl_vars['k']->value = $_smarty_tpl->tpl_vars['v']->key;
?><?php if ($_smarty_tpl->tpl_vars['k']->value=="state") {?>					->dropdown("form[<?php echo $_smarty_tpl->tpl_vars['k']->value;?>
]","<?php echo $_smarty_tpl->tpl_vars['v']->value->label;?>
",<?php if ($_smarty_tpl->tpl_vars['cmodel_state']->value) {?>CMODEL_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::get_states()<?php } else { ?>DBQ_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::get_state_list()<?php }?>,$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
->get_<?php echo $_smarty_tpl->tpl_vars['k']->value;?>
())
<?php } else { ?><?php if ($_smarty_tpl->tpl_vars['v']->value->get_data_type()=="char") {?>					//->dropdown("form[<?php echo $_smarty_tpl->tpl_vars['k']->value;?>
]","<?php echo $_smarty_tpl->tpl_vars['v']->value->label;?>
",CMODEL_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::get_<?php echo $_smarty_tpl->tpl_vars['k']->value;?>
s(),$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
->get_<?php echo $_smarty_tpl->tpl_vars['k']->value;?>
())
<?php } else { ?>					->input("form[<?php echo $_smarty_tpl->tpl_vars['k']->value;?>
]","<?php echo $_smarty_tpl->tpl_vars['v']->value->label;?>
",$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
->get_<?php echo $_smarty_tpl->tpl_vars['k']->value;?>
())
<?php }?><?php }?><?php } ?>					->text("", HTML_UTIL::button("<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-save","Save",array("id"=>"<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-save","class"=>"btn btn-primary")))
					->render();
			?<?php ?>>

			<<?php ?>?=HTML_UTIL::hidden("<?php echo $_smarty_tpl->tpl_vars['id']->value;?>
",$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
->get_<?php echo $_smarty_tpl->tpl_vars['primary_key']->value;?>
())?<?php ?>>
<?php if ($_smarty_tpl->tpl_vars['relation_field_abr']->value) {?>
			<<?php ?>?=HTML_UTIL::hidden("<?php echo $_smarty_tpl->tpl_vars['relation_field_abr']->value;?>
",$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
->get_<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
())?<?php ?>>
<?php }?>
		</form>

	</div>
</div>

<script>
	$(function() {
		
		$("#<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
-tabs").tabs({ activate: function(e,ui) {
									FF.cookie.set("<?php echo $_smarty_tpl->tpl_vars['lower_task']->value;?>
-tabs",ui.newTab.index());
								}}).show().tabs("option","active",((idx=FF.request.get("tab")) ? idx : parseInt(FF.cookie.get("<?php echo $_smarty_tpl->tpl_vars['lower_task']->value;?>
-tabs"))));

		$("#<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-save").go("/<?php echo $_smarty_tpl->tpl_vars['lower_controller']->value;?>
/do<?php echo $_smarty_tpl->tpl_vars['lower_task']->value;?>
",{ data: "#<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-form", message: "Successfully saved the <?php echo $_smarty_tpl->tpl_vars['pretty_model']->value;?>
" });
		
	});	
</script>

<<?php ?>? } ?<?php ?>><?php }} ?>
