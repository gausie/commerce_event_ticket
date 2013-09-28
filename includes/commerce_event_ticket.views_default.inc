<?php
/**
 * @file
 * Default Views for the Commerce Event Ticket module.
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_event_ticket_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'commerce_event_tickets';
  $view->description = '';
  $view->tag = 'commerce_event_ticket';
  $view->base_table = 'commerce_event_ticket';
  $view->human_name = 'Tickets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Tickets';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view all commerce event tickets';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'ticket_id' => 'ticket_id',
    'barcode_token' => 'barcode_token',
    'created' => 'created',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ticket_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'barcode_token' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Bulk operations: Commerce Event Ticket */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'commerce_event_ticket';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::twitter_actions_set_status_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Commerce Event Ticket: Ticket ID */
  $handler->display->display_options['fields']['ticket_id']['id'] = 'ticket_id';
  $handler->display->display_options['fields']['ticket_id']['table'] = 'commerce_event_ticket';
  $handler->display->display_options['fields']['ticket_id']['field'] = 'ticket_id';
  /* Field: Commerce Event Ticket: Validity */
  $handler->display->display_options['fields']['valid']['id'] = 'valid';
  $handler->display->display_options['fields']['valid']['table'] = 'commerce_event_ticket';
  $handler->display->display_options['fields']['valid']['field'] = 'valid';
  $handler->display->display_options['fields']['valid']['label'] = 'Valid?';
  $handler->display->display_options['fields']['valid']['not'] = 0;
  /* Field: Commerce Event Ticket: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_event_ticket';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Ticket: PDF */
  $handler->display->display_options['fields']['cet_pdf']['id'] = 'cet_pdf';
  $handler->display->display_options['fields']['cet_pdf']['table'] = 'field_data_cet_pdf';
  $handler->display->display_options['fields']['cet_pdf']['field'] = 'cet_pdf';
  $handler->display->display_options['fields']['cet_pdf']['label'] = 'Download';
  $handler->display->display_options['fields']['cet_pdf']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['cet_pdf']['type'] = 'file_download_link';
  $handler->display->display_options['fields']['cet_pdf']['settings'] = array(
    'text' => 'Download ticket',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/commerce/reports/tickets';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Tickets';
  $handler->display->display_options['menu']['name'] = 'management';

  $views[$view->name] = $view;

  return $views;
}
