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

  require_once drupal_get_path('module', 'commerce_event_ticket') . '/includes/views/commerce_event_tickets.inc';
  $views[$view->name] = $view;

  return $views;
}
