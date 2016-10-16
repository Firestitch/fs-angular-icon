<?php /* Smarty version Smarty-3.1.17, created on 2016-05-02 14:13:51
         compiled from "C:\Projects\boilerplate\utility\assets\list_ajax_view.inc" */ ?>
<?php /*%%SmartyHeaderCode:16276572785f0457f88-73832363%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    'f237a809046ce40786dc998788109281e7d36f64' => 
    array (
      0 => 'C:\\Projects\\boilerplate\\utility\\assets\\list_ajax_view.inc',
      1 => 1462212771,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '16276572785f0457f88-73832363',
  'function' => 
  array (
  ),
  'version' => 'Smarty-3.1.17',
  'unifunc' => 'content_572785f04a85f8_30151596',
  'variables' => 
  array (
    'is_framework' => 0,
    'upper_controller' => 0,
    'upper_task_plural' => 0,
    'lower_controller' => 0,
    'lower_task_plural' => 0,
    'security_roles' => 0,
    'hyphen_model' => 0,
    'is_list_body_blank' => 0,
    'is_list_body_popup' => 0,
    'lower_models' => 0,
    'lower_task' => 0,
    'relation_field' => 0,
    'relation_field_abr' => 0,
  ),
  'has_nocache_code' => false,
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_572785f04a85f8_30151596')) {function content_572785f04a85f8_30151596($_smarty_tpl) {?><<?php ?>?
	class <?php if ($_smarty_tpl->tpl_vars['is_framework']->value) {?>BASE_<?php }?>VIEW_<?php echo $_smarty_tpl->tpl_vars['upper_controller']->value;?>
_<?php echo $_smarty_tpl->tpl_vars['upper_task_plural']->value;?>
 extends VIEW {
	
		function __construct() {
			parent::__construct("<?php echo $_smarty_tpl->tpl_vars['lower_controller']->value;?>
","<?php echo $_smarty_tpl->tpl_vars['lower_task_plural']->value;?>
",[<?php echo $_smarty_tpl->tpl_vars['security_roles']->value;?>
],"<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-form");
<?php if ($_smarty_tpl->tpl_vars['is_list_body_blank']->value) {?>			$this->type_blank();<?php }?>
<?php if ($_smarty_tpl->tpl_vars['is_list_body_popup']->value) {?>			$this->type_popup();<?php }?>
			$this->set_view("<?php echo $_smarty_tpl->tpl_vars['lower_models']->value;?>
",APPLICATION::get_view("<?php echo $_smarty_tpl->tpl_vars['lower_controller']->value;?>
","<?php echo $_smarty_tpl->tpl_vars['lower_task']->value;?>
list"));
		}
		
		function init() {
<?php if ($_smarty_tpl->tpl_vars['relation_field']->value) {?>
			$<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
 = $this->get("<?php echo $_smarty_tpl->tpl_vars['relation_field_abr']->value;?>
");
			
			$this->load($<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
);
<?php } else { ?>
			$this->load();
<?php }?>
<?php if ($_smarty_tpl->tpl_vars['relation_field']->value) {?>			
			$this->set_var("<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
",$<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
);
<?php }?>
		}
<?php if ($_smarty_tpl->tpl_vars['relation_field']->value) {?>
		function load($<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
) { $this->get_view("<?php echo $_smarty_tpl->tpl_vars['lower_models']->value;?>
")->load($<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
); }
<?php } else { ?>
		function load() { $this->get_view("<?php echo $_smarty_tpl->tpl_vars['lower_models']->value;?>
")->load(); }
<?php }?>
	}<?php }} ?>
