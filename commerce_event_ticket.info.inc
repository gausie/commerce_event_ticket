<?php
/**
 * @file
 * Entity property info hooks for the Commerce Event Ticket module.
 */

/**
 * Implements hook_entity_property_info().
 */
function commerce_event_ticket_entity_property_info() {
  $info = array();
  $properties = &$info['commerce_event_ticket']['properties'];
  $properties = array(
    'ticket_id' => array(
      'label' => t('Ticket ID'),
      'description' => t('Primary key'),
      'type' => 'integer',
      'schema field' => 'id',
      'required' => TRUE,
    ),
    'type' => array(
      'label' => t('Type'),
      'description' => t('The type of ticket.'),
      'type' => 'text',
      'schema field' => 'type',
      'required' => TRUE,
    ),
    'barcode_token' => array(
      'label' => t('Barcode token'),
      'description' => t('The barcode token for the ticket.'),
      'type' => 'int',
      'schema field' => 'barcode_token',
      'required' => TRUE,
    ),
    'owner' => array(
      'label' => t('Owner'),
      'description' => t('The owner of the ticket.'),
      'type' => 'user',
      'schema field' => 'uid',
      'required' => TRUE,
    ),
    'order' => array(
      'label' => t('Order'),
      'description' => t('The Commerce order associated with the ticket.'),
      'type' => 'commerce_order',
      'schema field' => 'order_id',
      'required' => TRUE,
    ),
    'line_item' => array(
      'label' => t('Line item'),
      'description' => t('The Commerce line item associated with the ticket.'),
      'type' => 'commerce_line_item',
      'schema field' => 'line_item_id',
      'required' => TRUE,
    ),
    'product' => array(
      'label' => t('Product'),
      'description' => t('The Commerce product associated with the ticket.'),
      'type' => 'commerce_product',
      'schema field' => 'product_id',
      'required' => TRUE,
    ),
  );
  return $info;
}
