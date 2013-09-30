<?php
/**
 * @file
 * Theme functions for the Commerce Event Ticket module.
 */

/**
 * Preprocess variables for displaying a ticket.
 */
function template_preprocess_commerce_event_ticket(&$variables) {
  $ticket = $variables['ticket'];
  $product = commerce_product_load($ticket->product_id);
  $order = commerce_order_load($ticket->order_id);

  $variables['valid'] = commerce_event_ticket_is_valid($ticket);
  $variables['product_title'] = check_plain($product->title);
  $variables['order_id'] = intval($order->order_id);
  $variables['order_number'] = intval($order->order_number);
  $variables['order_created'] = format_date($order->created);
  $variables['order_status'] = check_plain(commerce_order_status_get_title($order->status));
}

/**
 * Theme function for displaying a ticket.
 */
function theme_commerce_event_ticket($variables) {
  extract($variables);
  $header = array(
    t('Valid?'),
    t('Product'),
    t('Order number'),
    t('Order date'),
    t('Order status'),
  );
  $rows = array(
    array(
      $valid ? t('Yes') : t('No'),
      $product_title,
      l($order_number, 'admin/commerce/orders/' . $order_id),
      $order_created,
      $order_status,
    ),
  );
  return theme('table', array(
    'header' => $header,
    'rows' => $rows,
  ));
}
