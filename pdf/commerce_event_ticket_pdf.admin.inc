<?php
/**
 * @file
 * Admin functions for the Commerce Event Ticket PDF module.
 */

/**
 * Configuration form.
 */
function commerce_event_ticket_pdf_config($form, &$form_state) {
  $form = array();

  $options = _commerce_event_ticket_pdf_elements_options();
  $form['commerce_event_ticket_pdf_elements'] = array(
    '#type' => 'checkboxes',
    '#title' => t('PDF elements'),
    '#description' => t('The elements to add to the generated PDF.'),
    '#options' => $options,
    '#default_value' => variable_get('commerce_event_ticket_pdf_elements', array_keys($options)),
  );

  return system_settings_form($form);
}
