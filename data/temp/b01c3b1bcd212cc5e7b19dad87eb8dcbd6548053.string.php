<?php /* Smarty version Smarty-3.1.17, created on 2016-03-18 01:54:49
         compiled from "b01c3b1bcd212cc5e7b19dad87eb8dcbd6548053" */ ?>
<?php /*%%SmartyHeaderCode:1531856eb5fe988f4a8-19763259%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    'b01c3b1bcd212cc5e7b19dad87eb8dcbd6548053' => 
    array (
      0 => 'b01c3b1bcd212cc5e7b19dad87eb8dcbd6548053',
      1 => 0,
      2 => 'string',
    ),
  ),
  'nocache_hash' => '1531856eb5fe988f4a8-19763259',
  'function' => 
  array (
  ),
  'variables' => 
  array (
    'user_email' => 0,
    'reset_guid' => 0,
    'reset_url' => 0,
  ),
  'has_nocache_code' => false,
  'version' => 'Smarty-3.1.17',
  'unifunc' => 'content_56eb5fe98bc8c8_64447334',
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_56eb5fe98bc8c8_64447334')) {function content_56eb5fe98bc8c8_64447334($_smarty_tpl) {?>A request has been made to reset the password for the email <?php echo $_smarty_tpl->tpl_vars['user_email']->value;?>
.

Here is your reset code, which you can enter on the password reset page:

<?php echo $_smarty_tpl->tpl_vars['reset_guid']->value;?>


Or you can also click on the link below

<?php echo $_smarty_tpl->tpl_vars['reset_url']->value;?>


Please note your old password has not been changed. If you did not request the password change, we apologize for the inconvenience.<?php }} ?>
