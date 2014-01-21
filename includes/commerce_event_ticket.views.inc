<?php
/**
 * @file
 * Views integration for the Commerce Event Ticket module.
 */

/**
 * Implements hook_views_data_alter().
 */
function commerce_event_ticket_views_data_alter(&$data) {
  $data['commerce_event_ticket']['valid'] = array(
    'title' => t('Validity'),
    'help' => t('Whether the ticket is currently valid.'),
    'field' => array(
      'handler' => 'commerce_event_ticket_views_handler_field_valid',
      'click sortable' => FALSE,
    ),
    'real field' => 'ticket_id',
  );
}
