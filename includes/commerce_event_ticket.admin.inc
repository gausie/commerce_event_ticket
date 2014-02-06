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
    '#description' => t('Select the product types that are considered to be tickets.'),
    '#options' => commerce_product_type_options_list(),
    '#default_value' => variable_get('commerce_event_ticket_product_types', array('ticket')),
  );

  $form['barcodes'] = array(
    '#type' => 'fieldset',
    '#title' => t('Barcodes'),
  );

  $form['barcodes']['commerce_event_ticket_barcode_length'] = array(
    '#type' => 'select',
    '#title' => t('Length'),
    '#description' => t('Select the length of the barcode tokens.'),
    '#options' => drupal_map_assoc(range(6, 12)),
    '#default_value' => variable_get('commerce_event_ticket_barcode_length', 10),
    '#required' => TRUE,
  );

  $form['barcodes']['commerce_event_ticket_token_type'] = array(
    '#type' => 'select',
    '#title' => t('Token type'),
    '#options' => array(
      'alphanumeric' => t('Alphanumeric'),
      'numeric' => t('Numeric'),
    ),
    '#required' => TRUE,
    '#default_value' => variable_get('commerce_event_ticket_token_type', 'alphanumeric'),
  );

  $form['order_statuses'] = array(
    '#type' => 'fieldset',
    '#title' => t('Order statuses'),
  );

  $status_options = commerce_order_status_options_list();

  $form['order_statuses']['commerce_event_ticket_statuses_create'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('When to create tickets'),
    '#description' => t('Select the order statuses that trigger the creation of ticket entities.'),
    '#options' => $status_options,
    '#default_value' => variable_get('commerce_event_ticket_statuses_create', array('checkout_complete')),
    '#required' => TRUE,
  );

  $form['order_statuses']['commerce_event_ticket_valid_statuses'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('Validating tickets'),
    '#description' => t('Select the order statuses that are considered to be valid to allow entry with a ticket.'),
    '#options' => $status_options,
    '#default_value' => variable_get('commerce_event_ticket_valid_statuses', array('checkout_complete')),
  );

  return system_settings_form($form);
}
