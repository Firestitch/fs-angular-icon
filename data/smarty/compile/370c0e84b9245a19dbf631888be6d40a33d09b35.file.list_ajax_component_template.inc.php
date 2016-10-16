<?php /* Smarty version Smarty-3.1.17, created on 2016-05-02 12:53:04
         compiled from "C:\Projects\boilerplate\utility\assets\list_ajax_component_template.inc" */ ?>
<?php /*%%SmartyHeaderCode:19331572785f0dc1770-40708050%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '370c0e84b9245a19dbf631888be6d40a33d09b35' => 
    array (
      0 => 'C:\\Projects\\boilerplate\\utility\\assets\\list_ajax_component_template.inc',
      1 => 1458264296,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '19331572785f0dc1770-40708050',
  'function' => 
  array (
  ),
  'variables' => 
  array (
    'lower_models' => 0,
    'lower_model' => 0,
    'is_view_format_popup' => 0,
    'hyphen_model' => 0,
    'id' => 0,
    'has_priority' => 0,
    'id_get_column' => 0,
    'get_functions' => 0,
    'headings' => 0,
    'lower_model_spaced' => 0,
  ),
  'has_nocache_code' => false,
  'version' => 'Smarty-3.1.17',
  'unifunc' => 'content_572785f0e2aad9_38260611',
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_572785f0e2aad9_38260611')) {function content_572785f0e2aad9_38260611($_smarty_tpl) {?><<?php ?>?
	if($<?php echo $_smarty_tpl->tpl_vars['lower_models']->value;?>
) {

		$table_data = array();

		foreach($<?php echo $_smarty_tpl->tpl_vars['lower_models']->value;?>
 as $<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
) {

			$actions = array();
<?php if ($_smarty_tpl->tpl_vars['is_view_format_popup']->value) {?>			$actions[] = HTML_UTIL::link("javascript:;",MODEL_IMAGE_ICON::get_edit(),array("class"=>"<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-update","data-<?php echo $_smarty_tpl->tpl_vars['id']->value;?>
"=>$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
->get_<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_id()));
<?php } else { ?>			$actions[] = HTML_UTIL::link($<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
->get_manage_url(),MODEL_IMAGE_ICON::get_edit());
<?php }?>			$actions[] = HTML_UTIL::link("javascript:;",MODEL_IMAGE_ICON::get_delete(),array("class"=>"<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-remove","data-<?php echo $_smarty_tpl->tpl_vars['id']->value;?>
"=>$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
->get_<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_id()));			
<?php if ($_smarty_tpl->tpl_vars['has_priority']->value) {?>			$actions[] = HTML_UTIL::link("javascript:;",MODEL_IMAGE_ICON::get_drag(),array("class"=>"order"));
<?php }?>		
<?php if ($_smarty_tpl->tpl_vars['is_view_format_popup']->value) {?>			$name = HTML_UTIL::link("javascript:;",<?php echo $_smarty_tpl->tpl_vars['id_get_column']->value;?>
,array("class"=>"<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-update","data-<?php echo $_smarty_tpl->tpl_vars['id']->value;?>
"=>$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
->get_<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_id()));
<?php } else { ?>			$name = HTML_UTIL::link($<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
->get_manage_url(),<?php echo $_smarty_tpl->tpl_vars['id_get_column']->value;?>
);
<?php }?>
			$table_data[<?php if ($_smarty_tpl->tpl_vars['has_priority']->value) {?>$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
->get_<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_id()<?php }?>] = array(<?php echo $_smarty_tpl->tpl_vars['get_functions']->value;?>
,array("data"=>implode(" ",$actions),"class"=>"wsnw w1"));
		}

		HTML_TABLE_UTIL::create()
			->set_data($table_data)
			->set_headings(array(<?php echo $_smarty_tpl->tpl_vars['headings']->value;?>
,""))
			->set_id("<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-table")
<?php if ($_smarty_tpl->tpl_vars['has_priority']->value) {?>
			->set_row_id_prefix("<?php echo $_smarty_tpl->tpl_vars['id']->value;?>
s_")
<?php }?>
			->add_class("w100p")
			->render();
		
		$this->show_view("paging");
	} else
		echo "There are currently no <?php echo $_smarty_tpl->tpl_vars['lower_model_spaced']->value;?>
";
<?php }} ?>
