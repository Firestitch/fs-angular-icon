<?php /* Smarty version Smarty-3.1.17, created on 2016-05-02 14:13:51
         compiled from "C:\Projects\boilerplate\utility\assets\list_ajax_component_view.inc" */ ?>
<?php /*%%SmartyHeaderCode:12850572785f0a70950-70632530%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '0015199a15661f6cd031f6360382abd38c5ae6ce' => 
    array (
      0 => 'C:\\Projects\\boilerplate\\utility\\assets\\list_ajax_component_view.inc',
      1 => 1462212829,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '12850572785f0a70950-70632530',
  'function' => 
  array (
  ),
  'version' => 'Smarty-3.1.17',
  'unifunc' => 'content_572785f0b50077_63882269',
  'variables' => 
  array (
    'is_framework' => 0,
    'upper_controller' => 0,
    'upper_task' => 0,
    'lower_model' => 0,
    'lower_controller' => 0,
    'lower_task' => 0,
    'security_roles' => 0,
    'is_format_post' => 0,
    'relation_field' => 0,
    'relation_field_abr' => 0,
    'lower_models' => 0,
    'is_search_form' => 0,
    'has_state' => 0,
    'upper_model' => 0,
    'id_column' => 0,
    'has_column_name' => 0,
    'has_column_description' => 0,
    'has_priority' => 0,
    'hyphen_model' => 0,
  ),
  'has_nocache_code' => false,
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_572785f0b50077_63882269')) {function content_572785f0b50077_63882269($_smarty_tpl) {?><<?php ?>?
	class <?php if ($_smarty_tpl->tpl_vars['is_framework']->value) {?>BASE_<?php }?>VIEW_<?php echo $_smarty_tpl->tpl_vars['upper_controller']->value;?>
_<?php echo $_smarty_tpl->tpl_vars['upper_task']->value;?>
 extends VIEW {
		
		protected $_<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodels = array();

		function __construct() {
			parent::__construct("<?php echo $_smarty_tpl->tpl_vars['lower_controller']->value;?>
","<?php echo $_smarty_tpl->tpl_vars['lower_task']->value;?>
",[<?php echo $_smarty_tpl->tpl_vars['security_roles']->value;?>
]);

			<?php if (!$_smarty_tpl->tpl_vars['is_format_post']->value) {?>$this->type_blank();
<?php }?>
			$this->set_view("paging",APPLICATION::get_base_view_instance("components","paging"));
		}
		
		function init() {

<?php if ($_smarty_tpl->tpl_vars['relation_field']->value) {?>
			if(SERVER_UTIL::is_post() && ($<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
=$this->post("<?php echo $_smarty_tpl->tpl_vars['relation_field_abr']->value;?>
")))
				$this->load($<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
);
<?php } else { ?>		if(SERVER_UTIL::is_post())
				$this->load();
<?php }?>

			$this->set_var("<?php echo $_smarty_tpl->tpl_vars['lower_models']->value;?>
",$this->_<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodels);	
		}

<?php if ($_smarty_tpl->tpl_vars['relation_field']->value) {?>		function load($<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
) {
<?php } else { ?>
		function load() {
<?php }?>
			$page_index	= $this->request("page_index") ? $this->request("page_index") : 0;
			$page_limit	= $this->request("page_limit") ? $this->request("page_limit") : 25;

<?php if ($_smarty_tpl->tpl_vars['is_search_form']->value) {?>			$search		= (array)$this->request("search");
<?php if ($_smarty_tpl->tpl_vars['has_state']->value) {?>			$state 		= value($search,"state")!==null ? value($search,"state") : CMODEL_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::STATE_ACTIVE;
<?php }?><?php }?>						
			$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_hmodel = HMODEL_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::create(false);
<?php if ($_smarty_tpl->tpl_vars['has_state']->value) {?><?php if ($_smarty_tpl->tpl_vars['is_search_form']->value) {?>

			if($state)
				$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_hmodel->set_state($state);
			
			if($keyword=value($search,"keyword")) {
				$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_hmodel->where("<?php echo $_smarty_tpl->tpl_vars['id_column']->value;?>
","=",$keyword,"OR","searchgroup");
<?php if ($_smarty_tpl->tpl_vars['has_column_name']->value) {?>				$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_hmodel->where("name","LIKE","%".$keyword."%","OR","searchgroup");
<?php }?><?php if ($_smarty_tpl->tpl_vars['has_column_description']->value) {?>				$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_hmodel->where("description","LIKE","%".$keyword."%","OR","searchgroup");
<?php }?>			}
			
<?php } else { ?>			$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_hmodel->set_state(CMODEL_<?php echo $_smarty_tpl->tpl_vars['upper_model']->value;?>
::STATE_ACTIVE);
<?php }?>
<?php }?>
<?php if ($_smarty_tpl->tpl_vars['has_priority']->value) {?>			$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_hmodel->order("priority");
<?php }?>
<?php if ($_smarty_tpl->tpl_vars['relation_field']->value) {?>			$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_hmodel->where("<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
","=",$<?php echo $_smarty_tpl->tpl_vars['relation_field']->value;?>
);
<?php }?>
			$record_count = $<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_hmodel->count();

			$<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_hmodel->set_limit($page_limit,$page_limit * $page_index,$record_count);

			$this->_<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_cmodels = $<?php echo $_smarty_tpl->tpl_vars['lower_model']->value;?>
_hmodel->gets();

			$this->get_view("paging")->populate($page_index,$page_limit,$record_count,'$("#<?php echo $_smarty_tpl->tpl_vars['hyphen_model']->value;?>
-list").trigger("load")');
		}	
	}
	
	
				
				<?php }} ?>
