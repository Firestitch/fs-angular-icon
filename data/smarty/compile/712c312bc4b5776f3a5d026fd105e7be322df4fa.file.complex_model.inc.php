<?php /* Smarty version Smarty-3.1.17, created on 2016-05-02 12:52:40
         compiled from "C:\Projects\boilerplate\utility\assets\complex_model.inc" */ ?>
<?php /*%%SmartyHeaderCode:1055656eb58f41f13e6-95896287%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '712c312bc4b5776f3a5d026fd105e7be322df4fa' => 
    array (
      0 => 'C:\\Projects\\boilerplate\\utility\\assets\\complex_model.inc',
      1 => 1462207936,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '1055656eb58f41f13e6-95896287',
  'function' => 
  array (
  ),
  'version' => 'Smarty-3.1.17',
  'unifunc' => 'content_56eb58f4433e74_99343661',
  'variables' => 
  array (
    'framework' => 0,
    'upper_model' => 0,
    'extends' => 0,
    'has_state' => 0,
    'consts' => 0,
    'const' => 0,
    'columns' => 0,
    'column' => 0,
    'name' => 0,
    'lower_model' => 0,
    'id' => 0,
    'primary_key' => 0,
    'has_multiple_keys' => 0,
    'keys' => 0,
    'key' => 0,
    'extended' => 0,
    'has_guid' => 0,
    'has_create_date' => 0,
    'extend_id' => 0,
  ),
  'has_nocache_code' => false,
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_56eb58f4433e74_99343661')) {function content_56eb58f4433e74_99343661($_smarty_tpl) {?><?php if (!is_callable('smarty_modifier_replace')) include 'C:\\Projects\\boilerplate\\framework\\packages\\Smarty\\plugins\\modifier.replace.php';
?><<?php ?>?
	class <?php if ($_smarty_tpl->tpl_vars['framework']->value) {?>B<?php }?>CMODEL_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
 extends <?php echo $_smarty_tpl->tpl_vars['extends']->value;?>
 {
<?php if ($_smarty_tpl->tpl_vars['has_state']->value) {?>
		
		const STATE_ACTIVE	= "active";
		const STATE_DELETED	= "deleted";
				
		public static function get_states()	{ return array(self::STATE_ACTIVE=>"Active",self::STATE_DELETED=>"Deleted"); }
<?php }?>

		public function __construct() {
			parent::__construct();
			return $this->register_dbo(DBO_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::create());
		}
		
<?php  $_smarty_tpl->tpl_vars['const'] = new Smarty_Variable; $_smarty_tpl->tpl_vars['const']->_loop = false;
 $_from = $_smarty_tpl->tpl_vars['consts']->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
foreach ($_from as $_smarty_tpl->tpl_vars['const']->key => $_smarty_tpl->tpl_vars['const']->value) {
$_smarty_tpl->tpl_vars['const']->_loop = true;
?><?php if ($_smarty_tpl->tpl_vars['const']->value!="state") {?>		public function is_<?php echo mb_strtolower($_smarty_tpl->tpl_vars['const']->value['const'], 'UTF-8');?>
()	{ return $this->get_<?php echo $_smarty_tpl->tpl_vars['const']->value['field'];?>
()==self::<?php echo $_smarty_tpl->tpl_vars['const']->value['const'];?>
; }<?php }?>
<?php } ?>
<?php  $_smarty_tpl->tpl_vars['column'] = new Smarty_Variable; $_smarty_tpl->tpl_vars['column']->_loop = false;
 $_smarty_tpl->tpl_vars['name'] = new Smarty_Variable;
 $_from = $_smarty_tpl->tpl_vars['columns']->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
foreach ($_from as $_smarty_tpl->tpl_vars['column']->key => $_smarty_tpl->tpl_vars['column']->value) {
$_smarty_tpl->tpl_vars['column']->_loop = true;
 $_smarty_tpl->tpl_vars['name']->value = $_smarty_tpl->tpl_vars['column']->key;
?><?php if ($_smarty_tpl->tpl_vars['column']->value->is_data_type("CHAR")||$_smarty_tpl->tpl_vars['name']->value=="state") {?>		public function get_<?php echo $_smarty_tpl->tpl_vars['name']->value;?>
_name()	{ return value(self::get_<?php echo $_smarty_tpl->tpl_vars['name']->value;?>
s(),$this->get_<?php echo $_smarty_tpl->tpl_vars['name']->value;?>
()); }
<?php }?><?php } ?>
		public function get_manage_url()	{ return "/manage/<?php echo smarty_modifier_replace($_smarty_tpl->tpl_vars['lower_model']->value,'_','');?>
/<?php echo $_smarty_tpl->tpl_vars['id']->value;?>
:".$this->get_<?php echo $_smarty_tpl->tpl_vars['primary_key']->value;?>
()."/"; }
		public function get_url()			{ return "/<?php echo smarty_modifier_replace($_smarty_tpl->tpl_vars['lower_model']->value,'_','');?>
s/<?php echo smarty_modifier_replace($_smarty_tpl->tpl_vars['lower_model']->value,'_','');?>
/<?php echo $_smarty_tpl->tpl_vars['id']->value;?>
:".$this->get_<?php echo $_smarty_tpl->tpl_vars['primary_key']->value;?>
()."/"; }
<?php if ($_smarty_tpl->tpl_vars['has_state']->value) {?>		public function delete()			{ return $this->set_state(self::STATE_DELETED)->save(); }	
		public function is_state_delete()	{ return $this->get_state()==self::STATE_DELETED; }		
		public function is_state_active()	{ return $this->get_state()==self::STATE_ACTIVE; }		
<?php }?>

		public function save() {
<?php if ($_smarty_tpl->tpl_vars['has_multiple_keys']->value) {?>
			$this->set_<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_id(DBQ_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::create()
<?php  $_smarty_tpl->tpl_vars['key'] = new Smarty_Variable; $_smarty_tpl->tpl_vars['key']->_loop = false;
 $_from = $_smarty_tpl->tpl_vars['keys']->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
foreach ($_from as $_smarty_tpl->tpl_vars['key']->key => $_smarty_tpl->tpl_vars['key']->value) {
$_smarty_tpl->tpl_vars['key']->_loop = true;
?>
									->where("<?php echo $_smarty_tpl->tpl_vars['key']->value;?>
","=",$this->get_<?php echo $_smarty_tpl->tpl_vars['key']->value;?>
())
<?php } ?>
									->one("<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_id"));
<?php }?>

<?php if ($_smarty_tpl->tpl_vars['extended']->value) {?>
			try {
				
				DB::start_transaction();
				parent::save();

<?php }?>
			if(is_numeric(self::get_<?php echo $_smarty_tpl->tpl_vars['primary_key']->value;?>
())) {
				$this->dbo("<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
")->update();
			} else {
<?php if ($_smarty_tpl->tpl_vars['has_guid']->value) {?>
				if(!$this->get_guid())
					$this->set_guid(MISC_UTIL::get_guid());
					
<?php }?>
<?php if ($_smarty_tpl->tpl_vars['has_state']->value) {?>
				if(!$this->get_state())
					$this->set_state(self::STATE_ACTIVE);
					
<?php }?>
<?php if ($_smarty_tpl->tpl_vars['has_create_date']->value) {?>
				if(!$this->get_create_date())
					$this->set_create_date(DB::get_date_time());
					
<?php }?>
<?php if ($_smarty_tpl->tpl_vars['extended']->value) {?>
				$this->dbo("<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
")
					->set_<?php echo $_smarty_tpl->tpl_vars['extend_id']->value;?>
(parent::get_<?php echo $_smarty_tpl->tpl_vars['extend_id']->value;?>
())
					->insert();
						
<?php } else { ?>				$this->dbo("<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
")->insert();
<?php }?>
			}
<?php if ($_smarty_tpl->tpl_vars['extended']->value) {?>

				if(!DB::complete_transaction())
					throw new Exception("Error saving ".get_class());
			
			} catch(Exception $e) {
				DB::complete_transaction();
				throw $e;
			}
<?php }?>		
			return $this;
		}

		public function arry($arry=array()) {

			$arry = CMODEL_OBJECTER::create($this,
											array(	<?php  $_smarty_tpl->tpl_vars['column'] = new Smarty_Variable; $_smarty_tpl->tpl_vars['column']->_loop = false;
 $_smarty_tpl->tpl_vars['name'] = new Smarty_Variable;
 $_from = $_smarty_tpl->tpl_vars['columns']->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
foreach ($_from as $_smarty_tpl->tpl_vars['column']->key => $_smarty_tpl->tpl_vars['column']->value) {
$_smarty_tpl->tpl_vars['column']->_loop = true;
 $_smarty_tpl->tpl_vars['name']->value = $_smarty_tpl->tpl_vars['column']->key;
?><?php if ($_smarty_tpl->tpl_vars['column']->value->is_primary()) {?>"id"=>"get_<?php echo $_smarty_tpl->tpl_vars['name']->value;?>
",
<?php } else { ?>"get_<?php echo $_smarty_tpl->tpl_vars['name']->value;?>
",
<?php }?>													<?php } ?>))->arry();
<?php if ($_smarty_tpl->tpl_vars['extended']->value) {?>			$arry += parent::arry();
			<?php }?>

			return $arry;
		}		
	}<?php }} ?>
