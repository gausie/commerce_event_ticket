<?php
/**
 * @file
 * Rules integration for the Commerce Event Ticket module.
 */

/**
 * Implements hook_rules_action_info().
 */
function commerce_event_ticket_rules_action_info() {

  $actions = array();

  $defaults = array(
    'group' => t('Commerce Event Ticket'),
  );

  $actions['commerce_event_ticket_create_from_order'] = $defaults + array(
    'label' => t('Create event ticket(s) from an order'),
    'parameter' => array(
      'order' => array(
        'type' => 'commerce_order',
        'label' => t('The order associated with the tickets.'),
      ),
    ),
  );

  return $actions;
}
