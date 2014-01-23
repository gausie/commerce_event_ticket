<?php
/**
 * @file
 * commerce_event_ticket_pdf.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function commerce_event_ticket_pdf_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'cet_pdf'
  $field_bases['cet_pdf'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_event_ticket',
    ),
    'field_name' => 'cet_pdf',
    'field_permissions' => array(
      'type' => 1,
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
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'uri_scheme' => 'private',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  return $field_bases;
}
