<?php /* Smarty version Smarty-3.1.17, created on 2016-05-02 14:13:52
         compiled from "C:\Projects\boilerplate\utility\assets\remove_ajax_action.inc" */ ?>
<?php /*%%SmartyHeaderCode:23865572785f135a616-55309131%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '39ca9d5db6359634d562ab3d7c66cb363c885e11' => 
    array (
      0 => 'C:\\Projects\\boilerplate\\utility\\assets\\remove_ajax_action.inc',
      1 => 1462212829,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '23865572785f135a616-55309131',
  'function' => 
  array (
  ),
  'version' => 'Smarty-3.1.17',
  'unifunc' => 'content_572785f1386fa5_06807297',
  'variables' => 
  array (
    'is_framework' => 0,
    'upper_controller' => 0,
    'upper_task' => 0,
    'security_roles' => 0,
    'lower_model' => 0,
    'upper_model' => 0,
    'id' => 0,
    'title' => 0,
  ),
  'has_nocache_code' => false,
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_572785f1386fa5_06807297')) {function content_572785f1386fa5_06807297($_smarty_tpl) {?><<?php ?>?
	class <?php if ($_smarty_tpl->tpl_vars['is_framework']->value) {?>BASE_<?php }?>ACTION_<?php echo $_smarty_tpl->tpl_vars['upper_controller']->value;?>
_<?php echo $_smarty_tpl->tpl_vars['upper_task']->value;?>
REMOVE extends ACTION_JSON {
	
		function __construct() {
			parent::__construct([<?php echo $_smarty_tpl->tpl_vars['security_roles']->value;?>
]);
		}
		
		function process() {
		
			$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel = HMODEL_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::get($this->post("<?php echo $_smarty_tpl->tpl_vars['id']->value;?>
"));
			
			if(!$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel)
				throw new Exception("Failed to load <?php echo $_smarty_tpl->tpl_vars['title']->value;?>
");
			
			$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel->delete();
				
			$this->success(true);			
		}	
	}<?php }} ?>
