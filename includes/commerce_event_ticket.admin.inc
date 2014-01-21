<?php
/**
 * @file
 * Admin functions for the Commerce Event Ticket module.
 */

/**
 * Configuration form.
 */
function commerce_event_ticket_config($form, &$form_state) {
  $form = array();

  $form['commerce_event_ticket_product_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Product types'),
    '#description' => t('The product types that are considered to be tickets.'),
    '#options' => commerce_product_type_options_list(),
    '#default_value' => variable_get('commerce_event_ticket_product_types', array('ticket')),
  );

  $status_options = commerce_order_status_options_list();

  $form['commerce_event_ticket_statuses_create'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('When to create tickets'),
    '#description' => t('Select the order statuses that trigger the creation of ticket entities.'),
    '#options' => $status_options,
    '#default_value' => variable_get('commerce_event_ticket_statuses_create', array('checkout_complete')),
    '#required' => TRUE,
  );

  $form['commerce_event_ticket_valid_statuses'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('Validating tickets'),
    '#description' => t('Select the order statuses that are considered to be valid to allow entry with a ticket.'),
    '#options' => $status_options,
    '#default_value' => variable_get('commerce_event_ticket_valid_statuses', array('checkout_complete')),
  );

  return system_settings_form($form);
}
