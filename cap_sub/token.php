<?php
// <!-- phpDesigner :: Timestamp [2/1/2011 5:13:30 PM] -->
/**
 * Based on the work of Jack Born in Spring 2006
 * http://15daysofjquery.com/safer-contact-forms-without-captchas/11/
 * Updated link: 11/25/2010
 * Above is now a bum link but a slightly updated version is found below
 * http://docs.jquery.com/Tutorials:Safer_Contact_Forms_Without_CAPTCHAs
 */
// Path will need to be changed if module is contributed
define('DRUPAL_ROOT', dirname(realpath('../../../../..')));
require_once DRUPAL_ROOT . '/' . 'includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
$secret_salt = variable_get('avoid_captcha_secret_salt', 'secret salt');

$ct = mktime();
// Set your own Secret salt in the admin.
setcookie('token',md5($secret_salt.$ct), 0, '/');

# 'Expires' in the past
header("Expires: Mon, 26 Jul 1997 05:00:00 GMT");

# Always modified
header("Last-Modified: ".gmdate("D, d M Y H:i:s")." GMT");

# HTTP/1.1
header("Cache-Control: no-store, no-cache, must-revalidate");
header("Cache-Control: post-check=0, pre-check=0", false);

# HTTP/1.0
header("Pragma: no-cache");
echo $ct;
?>