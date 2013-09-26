<?php
/**
 * @file
 * A configuration file for Commerce Event Ticket PDF's use of TCPDF.
 */

/**
  * Cache directory for temporary files (full path).
  */
if (!file_exists('temporary://commerce_event_ticket/cache')) {
  mkdir('temporary://commerce_event_ticket/cache', 0775, TRUE);
}
define('K_PATH_CACHE', drupal_realpath('temporary://commerce_event_ticket/cache'));
