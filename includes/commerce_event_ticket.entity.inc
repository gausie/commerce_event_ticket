<?php
/**
 * Entity info hooks for the Commerce Event Ticket module.
 */

/**
 * Implements hook_entity_info().
 */
function commerce_event_ticket_entity_info() {
  $entities = array();

  $entities['commerce_event_ticket'] = array(
    'label' => t('Ticket'),
    'entity class' => 'CommerceEventTicketEntity',
    'controller class' => 'CommerceEventTicketController',
    'uri callback' => 'commerce_event_ticket_uri',
    'access callback' => 'commerce_event_ticket_access',
    'label callback' => 'commerce_event_ticket_label',
    'base table' => 'commerce_event_ticket',
    'token type' => 'commerce-event-ticket',
    'entity keys' => array(
      'id' => 'ticket_id',
      'bundle' => 'type',
    ),
    'bundle keys' => array(
      'bundle' => 'type',
    ),
    'bundles' => array(),
    'view modes' => array(
      'customer' => array(
        'label' => t('Customer'),
      ),
      'admin' => array(
        'label' => t('Administrator'),
      ),
      'pdf' => array(
        'label' => t('PDF'),
      ),
    ),
    'view callback' => 'entity_metadata_view_single',
    'static cache' => TRUE,
    'fieldable' => FALSE,
    'module' => 'commerce_event_ticket',
  );

  foreach (commerce_event_ticket_types() as $key => $type) {
    $entities['commerce_event_ticket']['bundles'][$key] = array(
      'label' => $type['name'],
      'admin' => array(
        'path' => 'admin/commerce/config/event-ticket/' . $key,
        'real path' => 'admin/commerce/config/event-ticket/' . $key,
        'bundle argument' => 4,
        'access arguments' => array('administer commerce event ticket'),
      ),
    );
  }

  return $entities;
}
