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

  return system_settings_form($form);
}
