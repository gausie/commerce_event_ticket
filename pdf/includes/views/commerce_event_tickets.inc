<?php
/**
 * @file
 * Overrides the default View commerce_event_tickets.
 */

$view = new view();
$view->name = 'commerce_event_tickets';
$view->description = 'A list of tickets.';
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
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '5';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'created' => 'created',
  'ticket_id' => 'ticket_id',
  'valid' => 'valid',
  'order_number' => 'order_number',
  'title' => 'title',
  'commerce_unit_price' => 'commerce_unit_price',
  'name' => 'name',
  'pdf' => 'pdf',
  'event_tickets' => 'pdf',
);
$handler->display->display_options['style_options']['default'] = 'created';
$handler->display->display_options['style_options']['info'] = array(
  'created' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'ticket_id' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'valid' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'order_number' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'commerce_unit_price' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'pdf' => array(
    'align' => 'views-align-center',
    'separator' => ' · ',
    'empty_column' => 0,
  ),
  'event_tickets' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Relationship: Ticket: Order */
$handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
$handler->display->display_options['relationships']['order_id']['table'] = 'commerce_event_ticket';
$handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
$handler->display->display_options['relationships']['order_id']['required'] = TRUE;
/* Relationship: Commerce Order: Owner */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
$handler->display->display_options['relationships']['uid']['relationship'] = 'order_id';
$handler->display->display_options['relationships']['uid']['required'] = TRUE;
/* Relationship: Ticket: Product */
$handler->display->display_options['relationships']['product_id']['id'] = 'product_id';
$handler->display->display_options['relationships']['product_id']['table'] = 'commerce_event_ticket';
$handler->display->display_options['relationships']['product_id']['field'] = 'product_id';
$handler->display->display_options['relationships']['product_id']['required'] = TRUE;
/* Relationship: Ticket: Line item */
$handler->display->display_options['relationships']['line_item_id']['id'] = 'line_item_id';
$handler->display->display_options['relationships']['line_item_id']['table'] = 'commerce_event_ticket';
$handler->display->display_options['relationships']['line_item_id']['field'] = 'line_item_id';
$handler->display->display_options['relationships']['line_item_id']['required'] = TRUE;
/* Field: Ticket: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'commerce_event_ticket';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Created';
$handler->display->display_options['fields']['created']['date_format'] = 'short';
/* Field: Ticket: Ticket ID */
$handler->display->display_options['fields']['ticket_id']['id'] = 'ticket_id';
$handler->display->display_options['fields']['ticket_id']['table'] = 'commerce_event_ticket';
$handler->display->display_options['fields']['ticket_id']['field'] = 'ticket_id';
/* Field: Ticket: Validity */
$handler->display->display_options['fields']['valid']['id'] = 'valid';
$handler->display->display_options['fields']['valid']['table'] = 'commerce_event_ticket';
$handler->display->display_options['fields']['valid']['field'] = 'valid';
$handler->display->display_options['fields']['valid']['label'] = 'Valid?';
$handler->display->display_options['fields']['valid']['not'] = 0;
/* Field: Commerce Order: Order number */
$handler->display->display_options['fields']['order_number']['id'] = 'order_number';
$handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_number']['field'] = 'order_number';
$handler->display->display_options['fields']['order_number']['relationship'] = 'order_id';
$handler->display->display_options['fields']['order_number']['link_to_order'] = 'admin';
/* Field: Commerce Product: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'commerce_product';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'product_id';
$handler->display->display_options['fields']['title']['label'] = 'Product';
$handler->display->display_options['fields']['title']['link_to_product'] = 1;
/* Field: Commerce Line item: Unit price */
$handler->display->display_options['fields']['commerce_unit_price']['id'] = 'commerce_unit_price';
$handler->display->display_options['fields']['commerce_unit_price']['table'] = 'field_data_commerce_unit_price';
$handler->display->display_options['fields']['commerce_unit_price']['field'] = 'commerce_unit_price';
$handler->display->display_options['fields']['commerce_unit_price']['relationship'] = 'line_item_id';
$handler->display->display_options['fields']['commerce_unit_price']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_unit_price']['settings'] = array(
  'calculation' => FALSE,
);
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'User';
/* Field: Ticket: PDF download link */
$handler->display->display_options['fields']['pdf']['id'] = 'pdf';
$handler->display->display_options['fields']['pdf']['table'] = 'commerce_event_ticket';
$handler->display->display_options['fields']['pdf']['field'] = 'pdf';
$handler->display->display_options['fields']['pdf']['label'] = 'Download';
$handler->display->display_options['fields']['pdf']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['pdf']['text'] = 'Download (single)';
/* Field: Commerce Order: Tickets download link */
$handler->display->display_options['fields']['event_tickets']['id'] = 'event_tickets';
$handler->display->display_options['fields']['event_tickets']['table'] = 'commerce_order';
$handler->display->display_options['fields']['event_tickets']['field'] = 'event_tickets';
$handler->display->display_options['fields']['event_tickets']['relationship'] = 'order_id';
$handler->display->display_options['fields']['event_tickets']['label'] = 'Download (order)';
$handler->display->display_options['fields']['event_tickets']['text'] = 'Download (all)';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'admin/commerce/reports/tickets';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Tickets';
$handler->display->display_options['menu']['name'] = 'management';
