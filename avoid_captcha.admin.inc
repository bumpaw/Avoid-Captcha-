<?php
// <!-- phpDesigner :: Timestamp [1/26/2011 6:52:12 PM] -->
/**
 * @file
 * Admin include file.
 */

/**
 * Define the admin form.
 */
function avoid_captcha_settings()
{
    $form['avoid_captcha_base_url'] = array('#title' =>
        'Base URL for token.php file', '#type' => 'textfield', '#default_value' =>
        variable_get('avoid_captcha_base_url', array('base URL')), '#description' =>
        'Enter a base_url in case it\'s not set in settings.php.<br />
      Use: http://www.example.com without a following /.', '#required' => true);
    $options = array('contact_site_form' => 'Site-wide Contact Form',
        'user_register_form' => 'User Register Form', 'comment_node_article_form' =>'Article Comment Form', 'comment_node_page_form' => 'Page Comment Form', 'contact_personal_form' => 'User Contact Form', 'user_pass' => 'Password Request Form', 'page_node_form' => 'Page Form', 'article_node_form' => 'Article Form');
    $form['protect_forms'] = array('#title' => 'Forms to protect', '#type' =>
        'checkboxes', '#default_value' => variable_get('avoid_captcha_form_ids', array()),
        '#description' => 'Check all that you want to protect.', '#options' => $options,
        '#weight' => 20, '#required' => true);
    $form['#submit'][] = 'avoid_captcha_admin_submit';
    return system_settings_form($form);
}
