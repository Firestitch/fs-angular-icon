<?php /* Smarty version Smarty-3.1.17, created on 2016-03-17 21:25:08
         compiled from "C:\Projects\boilerplate\utility\assets\handler_model.inc" */ ?>
<?php /*%%SmartyHeaderCode:173356eb58f45781a2-53092210%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '903a0e220dd82555410e5dfd091d964625c8958d' => 
    array (
      0 => 'C:\\Projects\\boilerplate\\utility\\assets\\handler_model.inc',
      1 => 1458264296,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '173356eb58f45781a2-53092210',
  'function' => 
  array (
  ),
  'variables' => 
  array (
    'framework' => 0,
    'upper_model' => 0,
    'select_fields' => 0,
    'extends' => 0,
    'extend_tablename' => 0,
    'extend_primary_id' => 0,
    'lower_models' => 0,
    'lower_model' => 0,
    'has_state' => 0,
    'tablename' => 0,
    'fields' => 0,
    'name' => 0,
    'field' => 0,
  ),
  'has_nocache_code' => false,
  'version' => 'Smarty-3.1.17',
  'unifunc' => 'content_56eb58f45b9da9_21295137',
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_56eb58f45b9da9_21295137')) {function content_56eb58f45b9da9_21295137($_smarty_tpl) {?><<?php ?>?
	class <?php if ($_smarty_tpl->tpl_vars['framework']->value) {?>B<?php }?>HMODEL_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
 extends HMODEL {
	
		protected $_select_fields = array(<?php echo $_smarty_tpl->tpl_vars['select_fields']->value;?>
);
		
		public function __construct() {
<?php if ($_smarty_tpl->tpl_vars['extends']->value) {?>			return $this->register_dbq(DBQ_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::create()->inner("<?php echo $_smarty_tpl->tpl_vars['extend_tablename']->value;?>
","<?php echo $_smarty_tpl->tpl_vars['extend_primary_id']->value;?>
"));
<?php } else { ?>			return $this->register_dbq(DBQ_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::create());
<?php }?>
		}
		
		public function gets() {			
			$<?php echo $_smarty_tpl->tpl_vars['lower_models']->value;?>
 = $this->get_dbq()->select($this->_select_fields);

			$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodels = array();			
			foreach($<?php echo $_smarty_tpl->tpl_vars['lower_models']->value;?>
 as $<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
) {
				$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel = CMODEL_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::create()->populate($<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
,true,false);
				$this->apply_properties($<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel,$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
);
				$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodels[] = $<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodel;
			}
			
			if(!$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodels)
				return array();
			
			return $<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodels;
		}
		
<?php if ($_smarty_tpl->tpl_vars['has_state']->value) {?>		public function where_state_active()			{ return $this->set_state(CMODEL_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::STATE_ACTIVE); }
<?php }?>
		public function set_<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_ids($values)	{ return $this->where("<?php echo $_smarty_tpl->tpl_vars['tablename']->value;?>
.<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_id","IN",$values); }
		public function set_<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_id($value)	{ return $this->where("<?php echo $_smarty_tpl->tpl_vars['tablename']->value;?>
.<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_id","=",$value); }
<?php  $_smarty_tpl->tpl_vars['field'] = new Smarty_Variable; $_smarty_tpl->tpl_vars['field']->_loop = false;
 $_smarty_tpl->tpl_vars['name'] = new Smarty_Variable;
 $_from = $_smarty_tpl->tpl_vars['fields']->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
foreach ($_from as $_smarty_tpl->tpl_vars['field']->key => $_smarty_tpl->tpl_vars['field']->value) {
$_smarty_tpl->tpl_vars['field']->_loop = true;
 $_smarty_tpl->tpl_vars['name']->value = $_smarty_tpl->tpl_vars['field']->key;
?>		public function set_<?php echo $_smarty_tpl->tpl_vars['name']->value;?>
($value)		{ return $this->where("<?php echo $_smarty_tpl->tpl_vars['field']->value;?>
","=",$value); }
		public function set_<?php echo $_smarty_tpl->tpl_vars['name']->value;?>
s($values)			{ return $this->where("<?php echo $_smarty_tpl->tpl_vars['field']->value;?>
","IN",$values); }
<?php } ?>
		
		public static function create($defaults=true) {
			return $defaults ? parent::create()<?php if ($_smarty_tpl->tpl_vars['has_state']->value) {?>->where_state_active()<?php }?> : parent::create();
		}		
	}
	<?php }} ?>
