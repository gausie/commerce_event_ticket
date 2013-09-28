<?php
/**
 * @file
 * Default fields for the Commerce Event Ticket PDF module.
 */

/**
 * Implements hook_field_default_fields().
 *
 * Add a file field to event ticket entities: "cet_pdf".
 */
function commerce_event_ticket_pdf_field_default_fields() {
  $fields = array();

  $fields['commerce_event_ticket-ticket-cet_pdf'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array('commerce_event_ticket'),
      'field_name' => 'cet_pdf',
      'field_permissions' => array(
        'type' => '1',
      ),
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'file',
      'settings' => array(
        'display_default' => 0,
        'display_field' => 0,
        'uri_scheme' => 'private',
      ),
      'translatable' => '0',
      'type' => 'file',
    ),
    'field_instance' => array(
      'bundle' => 'ticket',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'file_entity',
          'settings' => array(
            'text' => t('Download ticket'),
          ),
          'type' => 'file_download_link',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'commerce_event_ticket',
      'field_name' => 'cet_pdf',
      'label' => t('PDF'),
      'required' => 0,
      'settings' => array(
        'description_field' => 0,
        'file_directory' => 'commerce_event_ticket',
        'file_extensions' => 'pdf',
        'max_filesize' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'file',
        'type' => 'file_generic',
        'weight' => 0,
      ),
    ),
  );

  return $fields;
}
