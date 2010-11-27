<?php
// <!-- phpDesigner :: Timestamp [11/26/2010 10:48:37 AM] -->
/**
 * Based on the work of Jack Born in Spring 2006
 * http://15daysofjquery.com/safer-contact-forms-without-captchas/11/
 * Updated link: 11/25/2010
 * Above is now a bum link but a slightly updated version is found below
 * http://docs.jquery.com/Tutorials:Safer_Contact_Forms_Without_CAPTCHAs
 */
$ct = mktime();
// Probably need way to set your own secret salt here for drupal.
setcookie('token',md5('africa byby'.$ct), 0, '/');
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