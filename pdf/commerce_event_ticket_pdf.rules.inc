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
    'label' => t('After a PDF ticket file has been created for an order'),
    'variables' => array(
      'file' => array(
        'type' => 'file',
        'label' => t('The PDF file containing the tickets for the order.'),
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
