<?php
/**
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

  $form['commerce_event_ticket_valid_statuses'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('Order statuses'),
    '#description' => t('The order statuses that are considered to be valid to allow entry with a ticket.'),
    '#options' => commerce_order_status_options_list(),
    '#default_value' => variable_get('commerce_event_ticket_valid_statuses', array('completed')),
  );

  return system_settings_form($form);
}
