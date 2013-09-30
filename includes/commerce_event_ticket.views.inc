<?php
/**
 * @file
 * Views integration for the Commerce Event Ticket module.
 */

/**
 * Implements hook_views_data().
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

  $data['commerce_event_ticket']['line_item_id'] = array(
    'title' => t('Line item ID'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'relationship' => array(
      'title' => t('Line item'),
      'help' => t("Relate this ticket to the line item it belongs to"),
      'handler' => 'views_handler_relationship',
      'base' => 'commerce_line_item',
      'base field' => 'line_item_id',
      'field' => 'line_item_id',
      'label' => t('Line item'),
    ),
  );

  $data['commerce_event_ticket']['order_id'] = array(
    'title' => t('Order ID'),
    'field' => array(
      'handler' => 'commerce_order_handler_field_order',
      'click sortable' => TRUE,
    ),
    'relationship' => array(
      'title' => t('Order'),
      'help' => t("Relate this ticket to the order it belongs to"),
      'handler' => 'views_handler_relationship',
      'base' => 'commerce_order',
      'base field' => 'order_id',
      'field' => 'order_id',
      'label' => t('Order'),
    ),
  );

  $data['commerce_event_ticket']['product_id'] = array(
    'title' => t('Product ID'),
    'relationship' => array(
      'title' => t('Product'),
      'help' => t("Relate this ticket to the product it belongs to"),
      'handler' => 'views_handler_relationship',
      'base' => 'commerce_product',
      'base field' => 'product_id',
      'field' => 'product_id',
      'label' => t('Product'),
    ),
  );

  $data['commerce_event_ticket']['valid'] = array(
    'title' => t('Validity'),
    'help' => t('Whether the ticket is currently valid.'),
    'field' => array(
      'handler' => 'commerce_event_ticket_views_handler_field_valid',
      'click sortable' => FALSE,
    ),
    'real field' => 'ticket_id',
  );

  $data['commerce_event_ticket']['barcode_token'] = array(
    'title' => t('Barcode token'),
    'help' => t('The unique (randomly generated) barcode token for the ticket.'),
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
