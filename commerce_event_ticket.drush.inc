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
  $items['generate-event-tickets'] = array(
    'description' => 'Generate event tickets for existing orders.',
    'arguments' => array(
      'limit' => "The maximum number of orders to process (default: 50).",
    ),
    'aliases' => array('cet-generate'),
  );
  $items['delete-all-event-tickets'] = array(
    'description' => 'Delete all event tickets.',
    'aliases' => array('cet-delete-all'),
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

/**
 * Generate commerce event tickets for existing orders.
 *
 * @param int $limit
 *   The maximum number of orders to process (default: 50).
 */
function drush_commerce_event_ticket_generate_event_tickets($limit = 50) {
  $statuses_create = variable_get('commerce_event_ticket_statuses_create', array('checkout_complete'));
  $cache_key = 'commerce_event_ticket_tickets_generated';
  $tickets_generated = cache_get($cache_key);
  $tickets_generated = $tickets_generated ? $tickets_generated->data : array();
  $select = db_select('commerce_order')
  ->fields('commerce_order', array('order_id'))
  ->condition('status', $statuses_create, 'IN')
  ->range(0, $limit)
  ->orderBy('created', 'DESC');
  if (count($tickets_generated) > 0) {
    $select->condition('order_id', $tickets_generated, 'NOT IN');
  }
  $order_ids = $select->execute()->fetchCol();
  drush_log(count($order_ids) . ' orders found.', 'ok');
  $orders = commerce_order_load_multiple($order_ids);
  // Reset the cache for these orders - otherwise the database gets locked up.
  entity_get_controller('commerce_order')->resetCache($order_ids);
  $i = 1;
  while ($order = array_shift($orders)) {
    $order_id = $order->order_id;
    commerce_event_ticket_create_from_order($order);
    $tickets_generated[] = $order_id;
    if ($i++ % 10 == 0) {
      cache_set($cache_key, $tickets_generated);
    }
    drush_log("Created ticket(s) for order " . $order->order_number, 'ok');
  }
  cache_set($cache_key, $tickets_generated, NULL, CACHE_TEMPORARY);
}

/**
 * Delete all event tickets.
 */
function drush_commerce_event_ticket_delete_all_event_tickets() {
  $ids = db_query('SELECT ticket_id FROM commerce_event_ticket')->fetchCol();
  if (!count($ids)) {
    drush_log('No tickets to delete.', 'ok');
    return;
  }
  if (!drush_confirm(dt('Are you sure you want to delete ' . count($ids) . ' tickets?'))) {
    return;
  }
  commerce_event_ticket_delete_multiple($ids);
  cache_clear_all('commerce_event_ticket_tickets_generated', 'cache');
  $private = drupal_realpath('private://commerce_event_ticket_pdf/');
  if ($private) {
    drush_log('This will delete all files in ' . $private, 'warning');
    if (!drush_confirm('Are you sure?')) {
      return;
    }
    shell_exec('rm -r ' . escapeshellarg($private) . '/*');
  }
}
