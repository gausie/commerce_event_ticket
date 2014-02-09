<?php
/**
 * @file
 * Rules integration for the Commerce Event Ticket PDF module.
 */

/**
 * Implements hook_rules_event_info().
 */
function commerce_event_ticket_pdf_rules_event_info() {
  $defaults = array(
    'group' => t('Commerce Event Ticket'),
    'module' => 'commerce_event_ticket_pdf',
    'access callback' => 'commerce_event_ticket_rules_config_access',
  );
  $events = array();
  $events['commerce_event_ticket_pdf_created'] = $defaults + array(
    'label' => t('After PDF tickets have been created for an order'),
    'variables' => array(
      'tickets' => array(
        'type' => 'list<commerce_event_ticket>',
        'label' => t("The order's tickets"),
        'skip save' => TRUE,
      ),
      'order' => array(
        'type' => 'commerce_order',
        'label' => t('The Commerce order'),
        'skip save' => TRUE,
      ),
      'allow_email' => array(
        'type' => 'boolean',
        'label' => t('Allow emailing'),
        'description' => t('This shows whether it is appropriate to email the tickets to the customer: if testing, or creating tickets in bulk, this should probably be FALSE.'),
      ),
    ),
  );
  return $events;
}

/**
 * Implements hook_rules_action_info().
 */
function commerce_event_ticket_pdf_rules_action_info() {

  $actions = array();

  $defaults = array(
    'group' => t('Commerce Event Ticket'),
  );

  $actions['commerce_event_ticket_pdf_aggregate'] = $defaults + array(
    'label' => t('Aggregate ticket PDFs into a single file'),
    'parameter' => array(
      'order' => array(
        'type' => 'commerce_order',
        'label' => t('The order associated with the tickets'),
      ),
      'tickets' => array(
        'type' => 'list<commerce_event_ticket>',
        'label' => t('The tickets'),
      ),
    ),
    'provides' => array(
      'aggregate' => array(
        'type' => 'file',
        'label' => t("The PDF file containing all the order's tickets."),
      ),
    ),
  );

  return $actions;
}
