<?php
/**
 * @file
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * Define event ticket types.
 */
function hook_commerce_event_ticket_info() {
  $types = array();
  $types['custom_module_ticket'] = array(
    'name' => t('Custom ticket'),
  );
  return $types;
}

/**
 * Alter event ticket types.
 */
function hook_commerce_event_ticket_info_alter(&$types) {
  $types['custom_module_ticket']['name'] = t('Renamed custom ticket');
}
