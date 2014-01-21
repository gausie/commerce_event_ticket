<?php
/**
 * @file
 * Drush integration for the Commerce Event Ticket module.
 */

/**
 * Implements hook_drush_command().
 */
function commerce_event_ticket_drush_command() {
  $items = array();
  $items['validate-event-ticket'] = array(
    'description' => 'Validate an event ticket.',
    'arguments' => array(
      'barcode' => "The ticket's barcode (required).",
    ),
    'required-arguments' => 1,
    'aliases' => array('vet'),
  );
  return $items;
}

/**
 * Validate a commerce event ticket barcode, via Drush.
 *
 * @param string $barcode_token
 *   The ticket's barcode token.
 */
function drush_commerce_event_ticket_validate_event_ticket($barcode_token) {
  $valid = commerce_event_ticket_check_barcode($barcode_token);
  return $valid ? dt('Valid') : dt('Invalid');
}
