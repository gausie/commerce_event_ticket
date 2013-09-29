<?php
/**
 * @file
 * A configuration file for Commerce Event Ticket PDF's use of TCPDF.
 *
 * This only sets the TCPDF cache directory.
 */

$cache_dir = 'temporary://commerce_event_ticket_pdf/cache';

if (!file_exists($cache_dir)) {
  mkdir($cache_dir, 0775, TRUE);
  chmod(drupal_realpath($cache_dir), 0775);
}
define('K_PATH_CACHE', drupal_realpath($cache_dir));
