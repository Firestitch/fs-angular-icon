<?php /* Smarty version Smarty-3.1.17, created on 2016-05-02 14:13:52
         compiled from "C:\Projects\boilerplate\utility\assets\update_ajax_action.inc" */ ?>
<?php /*%%SmartyHeaderCode:16640572785f1130d95-36698524%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '96e9fcb0b72f86a000533a37cb79bb7a429e6707' => 
    array (
      0 => 'C:\\Projects\\boilerplate\\utility\\assets\\update_ajax_action.inc',
      1 => 1462212829,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '16640572785f1130d95-36698524',
  'function' => 
  array (
  ),
  'version' => 'Smarty-3.1.17',
  'unifunc' => 'content_572785f11950f0_55800006',
  'variables' => 
  array (
    'is_framework' => 0,
    'upper_controller' => 0,
    'upper_task' => 0,
    'security_roles' => 0,
    'lower_model' => 0,
    'id' => 0,
    'relation_field' => 0,
    'relation_field_abr' => 0,
    'upper_model' => 0,
    'pretty_model' => 0,
  ),
  'has_nocache_code' => false,
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_572785f11950f0_55800006')) {function content_572785f11950f0_55800006($_smarty_tpl) {?><<?php ?>?
	class <?php if ($_smarty_tpl->tpl_vars['is_framework']->value) {?>BASE_<?php }?>ACTION_<?php echo $_smarty_tpl->tpl_vars['upper_controller']->value;?>
_<?php echo $_smarty_tpl->tpl_vars['upper_task']->value;?>
 extends ACTION_JSON {
	
		function __construct() {
			parent::__construct([<?php echo $_smarty_tpl->tpl_vars['security_roles']->value;?>
]);
		}
		
		function process() {
		
			$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_id	= $this->post("<?php echo $_smarty_tpl->tpl_vars['id']->value;?>
");
			$form			= $this->post("form");
<?php if ($_smarty_tpl->tpl_vars['relation_field']->value) {?>			$<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
		= $this->post("<?php echo $_smarty_tpl->tpl_vars['relation_field_abr']->value;?>
");
<?php }?>
			
			$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel = ($<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel=HMODEL_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::get($<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_id)) ? $<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel : CMODEL_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::create();
			$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel->populate($form);

<?php if ($_smarty_tpl->tpl_vars['relation_field']->value) {?>			if($<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
)
				$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel->set_<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
($<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
);

<?php }?>
			try {
				
				$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel->save();
			
				if(!$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_id) {
					APPLICATION::add_persistent_notify("Successfully added the <?php echo $_smarty_tpl->tpl_vars['pretty_model']->value;?>
"); 
					$this->redirect($<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel->get_manage_url());
				}
				
				$this
					->data("<?php echo $_smarty_tpl->tpl_vars['id']->value;?>
",$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel->get_<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_id())
					->success();

			} catch(Exception $e) {
				$this->error($e);
			}
			
			if(!$this->has_success() && !$this->has_error())
				$this->error("There was a problem trying to save the <?php echo $_smarty_tpl->tpl_vars['pretty_model']->value;?>
");
		}	
	}
	

<?php }} ?>
