<?php
/**
 * @file
 * commerce_event_ticket_pdf.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function commerce_event_ticket_pdf_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'commerce_event_ticket-ticket-cet_pdf'
  $field_instances['commerce_event_ticket-ticket-cet_pdf'] = array(
    'bundle' => 'ticket',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'file_entity',
        'settings' => array(
          'text' => 'Download ticket',
        ),
        'type' => 'file_download_link',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_event_ticket',
    'field_name' => 'cet_pdf',
    'label' => 'PDF',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'description_field' => 0,
      'file_directory' => 'commerce_event_ticket',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('PDF');

  return $field_instances;
}
