<?php
/**
 * @file
 * Default Rules for the Commerce Event Ticket module.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_event_ticket_default_rules_configuration() {
  $configs = array();

  // Create tickets for an order on checkout.
  $rule = rules_reaction_rule();
  $rule->label = 'Create tickets for an order on checkout';
  $rule->active = TRUE;
  $rule->event('commerce_checkout_complete');
  $rule->action('commerce_event_ticket_create_from_order', array(
    'order:select' => 'commerce-order',
  ));
  $configs['commerce_event_ticket_create_on_checkout'] = $rule;

  return $configs;
}
