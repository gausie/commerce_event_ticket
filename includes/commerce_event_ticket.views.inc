<?php
/**
 * @file
 * Views integration for the Commerce Event Ticket module.
 */

/**
 * Implements hook_views_data();
 */
function commerce_event_ticket_views_data() {
  $data = array();

  $data['commerce_event_ticket']['table']['group']  = t('Commerce Event Ticket');

  $data['commerce_event_ticket']['table']['entity type'] = 'commerce_event_ticket';

  $data['commerce_event_ticket']['table']['base'] = array(
    'field' => 'ticket_id',
    'title' => t('Commerce Event Ticket'),
    'defaults' => array(
      'field' => 'ticket_id',
    ),
  );

  $data['commerce_event_ticket']['ticket_id'] = array(
    'title' => t('Ticket ID'),
    'help' => t('The unique ID of the ticket.'),
    'field' => array(
      'handler' => 'commerce_event_ticket_views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'numeric' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['commerce_event_ticket']['barcode_token'] = array(
    'title' => t('Barcode token'),
    'help' => t('The barcode token for the ticket.'),
    'field' => array(
      'click sortable' => FALSE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['commerce_event_ticket']['created'] = array(
    'title' => t('Created date'),
    'help' => t('The date when the ticket was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['commerce_event_ticket']['changed'] = array(
    'title' => t('Updated date'),
    'help' => t('The date when the ticket was last updated.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  return $data;
}
