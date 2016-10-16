<?php /* Smarty version Smarty-3.1.17, created on 2016-05-02 19:30:23
         compiled from "c708ac05078188d8589110b24de7451425561014" */ ?>
<?php /*%%SmartyHeaderCode:270305727aacf4a4519-27286101%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    'c708ac05078188d8589110b24de7451425561014' => 
    array (
      0 => 'c708ac05078188d8589110b24de7451425561014',
      1 => 0,
      2 => 'string',
    ),
  ),
  'nocache_hash' => '270305727aacf4a4519-27286101',
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
  'unifunc' => 'content_5727aacf4cedf5_95044431',
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_5727aacf4cedf5_95044431')) {function content_5727aacf4cedf5_95044431($_smarty_tpl) {?>A request has been made to reset the password for the email <?php echo $_smarty_tpl->tpl_vars['user_email']->value;?>
.

Here is your reset code, which you can enter on the password reset page:

<?php echo $_smarty_tpl->tpl_vars['reset_guid']->value;?>


Or you can also click on the link below

<?php echo $_smarty_tpl->tpl_vars['reset_url']->value;?>


Please note your old password has not been changed. If you did not request the password change, we apologize for the inconvenience.<?php }} ?>
