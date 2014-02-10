<?php
/**
 * @file
 * Default Views for the Commerce Event Ticket PDF module.
 */

/**
 * Implements hook_views_default_views_alter().
 */
function commerce_event_ticket_pdf_views_default_views_alter(&$views) {
  if (isset($views['commerce_event_tickets'])) {
    require_once drupal_get_path('module', 'commerce_event_ticket_pdf') . '/includes/views/commerce_event_tickets.inc';
    $views[$view->name] = $view;
  }
}
