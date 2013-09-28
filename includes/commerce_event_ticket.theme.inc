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

  $variables['product_title'] = check_plain($variables['product']->title);

  $variables['link'] = url($variables['view_mode'] == 'admin' ? 'admin/commerce/orders/' . $ticket->order_id . '/tickets/' . $ticket->ticket_id : 'user/' . $ticket->uid . '/orders/' . $ticket->order_id . '/tickets/' . $ticket->ticket_id);
}

/**
 * Theme function for displaying a ticket.
 */
function theme_commerce_event_ticket($variables) {
  return '<div class="commerce-event-ticket">' . $variables['product_title'] . '</div>';
}
