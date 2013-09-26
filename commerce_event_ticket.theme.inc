<?php
/**
 * Theme functions for the Commerce Event Ticket module.
 */

/**
 * Preprocess variables for displaying a ticket.
 */
function template_preprocess_commerce_event_ticket(&$variables) {
  $ticket = $variables['ticket'];

  $variables['product'] = commerce_product_load($ticket->product_id);

  $variables['product_label'] = check_plain(entity_label('commerce_product', $variables['product']));
}

/**
 * Theme function for displaying a ticket.
 */
function theme_commerce_event_ticket($variables) {
  $ticket = $variables['ticket'];

  $display = t('%product (ticket @number): @barcode', array(
    '%product' => $variables['product_label'],
    '@number' => $ticket->number,
    '@barcode' => $ticket->barcode_token,
  ));

  return '<div class="commerce-event-ticket">' . $display . '</div>';
}
