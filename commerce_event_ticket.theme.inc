<?php
/**
 * Theme functions for the Commerce Event Ticket module.
 */

/**
 * Theme function for displaying a ticket.
 */
function theme_commerce_event_ticket($variables) {

  $ticket = $variables['ticket'];
  $view_mode = $variables['view_mode'];

  $product = commerce_product_load($ticket->product_id);
  $product_label = entity_label('commerce_product', $product);

  $display = t('@product (ticket @number): @barcode', array(
    '@product' => $product_label,
    '@number' => $ticket->number,
    '@barcode' => $ticket->barcode_token,
  ));

  return '<div class="commerce-event-ticket">' . $display . '</div>';

}
