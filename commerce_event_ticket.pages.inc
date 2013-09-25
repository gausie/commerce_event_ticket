<?php

/**
 * View a single ticket.
 */
function commerce_event_ticket_page($ticket, $view_mode) {
  return commerce_event_ticket_view($ticket, $view_mode);
}

/**
 * View a list of tickets for an order.
 *
 * @todo use a View instead
 */
function commerce_event_ticket_list($order, $view_mode) {

  commerce_event_ticket_create_from_order($order);
  $ticket_ids = commerce_event_ticket_find_by_order($order);
  $tickets = commerce_event_ticket_load_multiple($ticket_ids);

  $output = array();
  foreach ($tickets as $ticket) {
    $output[] = commerce_event_ticket_view($ticket, $view_mode);
  }

  return $output;
}
