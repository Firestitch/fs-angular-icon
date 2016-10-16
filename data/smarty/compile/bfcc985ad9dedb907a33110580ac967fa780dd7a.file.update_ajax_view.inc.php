<?php /* Smarty version Smarty-3.1.17, created on 2016-05-02 14:13:51
         compiled from "C:\Projects\boilerplate\utility\assets\update_ajax_view.inc" */ ?>
<?php /*%%SmartyHeaderCode:8614572785efa6b424-94656131%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    'bfcc985ad9dedb907a33110580ac967fa780dd7a' => 
    array (
      0 => 'C:\\Projects\\boilerplate\\utility\\assets\\update_ajax_view.inc',
      1 => 1462212784,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '8614572785efa6b424-94656131',
  'function' => 
  array (
  ),
  'version' => 'Smarty-3.1.17',
  'unifunc' => 'content_572785efbe3878_98439927',
  'variables' => 
  array (
    'is_framework' => 0,
    'upper_controller' => 0,
    'upper_task' => 0,
    'lower_model' => 0,
    'lower_controller' => 0,
    'lower_task' => 0,
    'security_roles' => 0,
    'page_title' => 0,
    'is_interface_popup' => 0,
    'is_interface_blank' => 0,
    'upper_model' => 0,
    'id' => 0,
    'relation_field' => 0,
    'relation_field_abr' => 0,
    'dependent_objects' => 0,
    'object' => 0,
    'field' => 0,
  ),
  'has_nocache_code' => false,
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_572785efbe3878_98439927')) {function content_572785efbe3878_98439927($_smarty_tpl) {?><<?php ?>?
	class <?php if ($_smarty_tpl->tpl_vars['is_framework']->value) {?>BASE_<?php }?>VIEW_<?php echo $_smarty_tpl->tpl_vars['upper_controller']->value;?>
_<?php echo $_smarty_tpl->tpl_vars['upper_task']->value;?>
 extends VIEW {
	
		protected $_<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel = null;
		
		function __construct() {
			parent::__construct("<?php echo $_smarty_tpl->tpl_vars['lower_controller']->value;?>
","<?php echo $_smarty_tpl->tpl_vars['lower_task']->value;?>
",[<?php echo $_smarty_tpl->tpl_vars['security_roles']->value;?>
]);
<?php if ($_smarty_tpl->tpl_vars['page_title']->value) {?>			$this->set_title("<?php echo $_smarty_tpl->tpl_vars['page_title']->value;?>
");
<?php }?>
<?php if ($_smarty_tpl->tpl_vars['is_interface_popup']->value) {?>			$this->type_popup();<?php }?>
<?php if ($_smarty_tpl->tpl_vars['is_interface_blank']->value) {?>			$this->type_blank();<?php }?>
			
			$this->_<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel = CMODEL_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::create();
		}
		
		function init() {
			
			if($<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_id=$this->get("<?php echo $_smarty_tpl->tpl_vars['id']->value;?>
"))
				$this->load($<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_id);

<?php if ($_smarty_tpl->tpl_vars['relation_field']->value) {?>			if(is_numeric($<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
=$this->get("<?php echo $_smarty_tpl->tpl_vars['relation_field_abr']->value;?>
")))
				$this->_<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel->set_<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
($<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
);
<?php }?>
<?php if ($_smarty_tpl->tpl_vars['dependent_objects']->value) {?>/*		
<?php  $_smarty_tpl->tpl_vars['field'] = new Smarty_Variable; $_smarty_tpl->tpl_vars['field']->_loop = false;
 $_smarty_tpl->tpl_vars['object'] = new Smarty_Variable;
 $_from = $_smarty_tpl->tpl_vars['dependent_objects']->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
foreach ($_from as $_smarty_tpl->tpl_vars['field']->key => $_smarty_tpl->tpl_vars['field']->value) {
$_smarty_tpl->tpl_vars['field']->_loop = true;
 $_smarty_tpl->tpl_vars['object']->value = $_smarty_tpl->tpl_vars['field']->key;
?>			$<?php echo $_smarty_tpl->tpl_vars['object']->value;?>
_list = ARRAY_UTIL::listing(HMODEL_<?php echo mb_strtoupper($_smarty_tpl->tpl_vars['object']->value, 'UTF-8');?>
::create()
								->order("<?php echo $_smarty_tpl->tpl_vars['field']->value;?>
")
								->gets(),"get_<?php echo $_smarty_tpl->tpl_vars['field']->value;?>
","get_<?php echo $_smarty_tpl->tpl_vars['object']->value;?>
_id");
			
<?php } ?>
			
<?php  $_smarty_tpl->tpl_vars['field'] = new Smarty_Variable; $_smarty_tpl->tpl_vars['field']->_loop = false;
 $_smarty_tpl->tpl_vars['object'] = new Smarty_Variable;
 $_from = $_smarty_tpl->tpl_vars['dependent_objects']->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
foreach ($_from as $_smarty_tpl->tpl_vars['field']->key => $_smarty_tpl->tpl_vars['field']->value) {
$_smarty_tpl->tpl_vars['field']->_loop = true;
 $_smarty_tpl->tpl_vars['object']->value = $_smarty_tpl->tpl_vars['field']->key;
?>			$this->set_var("<?php echo $_smarty_tpl->tpl_vars['object']->value;?>
_list",$<?php echo $_smarty_tpl->tpl_vars['object']->value;?>
_list);
<?php } ?>	
*/<?php }?>
		$this->set_var("<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
",$this->_<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel);
		}	

		function load($<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_id) {

			$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel = HMODEL_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::create(false)->get($<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_id);

			if($<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel)
				$this->_<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel = $<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel;
		}		
	}<?php }} ?>
