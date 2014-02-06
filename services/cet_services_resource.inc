<?php
/**
 * @file
 * Resource callbacks for the Commerce Event Ticket Services module.
 */

/**
 * Retrieve callback to get ticket information based on a barcode.
 */
function cet_services_retrieve_ticket($barcode) {
  $ticket = commerce_event_ticket_load_by_barcode($barcode);
  if (!$ticket) {
    return FALSE;
  }
  $order = commerce_order_load($ticket->order_id);
  $product = commerce_product_load($ticket->product_id);
  $owner = user_load($order->uid);
  $line_item = commerce_line_item_load($ticket->line_item_id);
  $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $line_item);
  $unit_price = $line_item_wrapper->commerce_unit_price->value();
  $output = array(
    'valid' => commerce_event_ticket_is_valid($ticket),
    'barcode_token' => $ticket->barcode_token,
    'ticket_id' => $ticket->ticket_id,
    'created' => date('c', $ticket->created),
    'changed' => date('c', $ticket->changed),
    'owner' => array(
      'uid' => $order->uid,
      'name' => $owner->name,
      'mail' => $owner->mail,
      'username' => format_username($owner),
    ),
    'order' => array(
      'order_id' => $order->order_id,
      'order_number' => $order->order_number,
      'created' => date('c', $order->created),
      'changed' => date('c', $order->changed),
      'status' => $order->status,
      'status_title' => commerce_order_status_get_title($order->status),
    ),
    'line_item' => array(
      'line_item_id' => $line_item->line_item_id,
      'quantity' => $line_item->quantity,
      'unit_price' => commerce_currency_format($unit_price['amount'], $unit_price['currency_code']),
    ),
    'product' => array(
      'product_id' => $ticket->product_id,
      'title' => $product->title,
    ),
  );
  return $output;
}
