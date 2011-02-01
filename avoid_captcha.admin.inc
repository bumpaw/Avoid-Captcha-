<?php
// <!-- phpDesigner :: Timestamp [1/27/2011 11:41:34 AM] -->
/**
 * @file
 * Admin include file.
 */

/**
 * Define the admin form.
 */
function avoid_captcha_settings()
{
    $form['avoid_captcha_secret_salt'] = array('#title' =>
        'Secret Salt', '#type' => 'textfield', '#default_value' =>
        variable_get('avoid_captcha_secret_salt', array('secret salt')), '#description' =>
        'Change this phrase to make your \'hash\' or token unique.<br />
      Use: Any short text string will do under 15 characters.', '#required' => true, '#size' => 15, '#maxlength' => 15);
    $form['avoid_captcha_time_out'] = array('#title' =>
        'Form Timeout', '#type' => 'textfield', '#default_value' =>
        variable_get('avoid_captcha_time_out', array(10)), '#description' =>
        'The number of minutes on the page that the form will be usable.<br />
      Use: Up to 2 digets allowed here.', '#required' => true, '#size' => 2, '#maxlength' => 2);
    $options = array('contact_site_form' => 'Site-wide Contact Form',
        'user_register_form' => 'User Register Form', 'comment_node_article_form' =>'Article Comment Form', 'comment_node_page_form' => 'Page Comment Form', 'contact_personal_form' => 'User Contact Form', 'user_pass' => 'Password Request Form', 'page_node_form' => 'Page Form', 'article_node_form' => 'Article Form');
    $form['protect_forms'] = array('#title' => 'Forms to protect', '#type' =>
        'checkboxes', '#default_value' => variable_get('avoid_captcha_form_ids', array()),
        '#description' => 'Check all that you want to protect.', '#options' => $options,
        '#weight' => 20, '#required' => true);
    $form['#validate'][] = 'avoid_captcha_admin_validate';
    $form['#submit'][] = 'avoid_captcha_admin_submit';
    return system_settings_form($form);
}
