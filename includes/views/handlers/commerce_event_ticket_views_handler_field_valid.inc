<?php

/**
 * @file
 * Views field handler to display an event ticket's validity.
 */

class commerce_event_ticket_views_handler_field_valid extends views_handler_field_boolean {

  /**
   * Overrides parent::init().
   */
  public function init(&$view, &$options) {
    parent::init($view, $options);
    $this->additional_fields['ticket_id'] = array(
      'table' => 'commerce_event_ticket',
      'field' => 'ticket_id',
    );
  }

  /**
   * Overrides parent::get_value().
   */
  public function get_value($values, $field = NULL) {
    $ticket_id = parent::get_value($values, 'ticket_id');
    $ticket = commerce_event_ticket_load($ticket_id);
    return commerce_event_ticket_is_valid($ticket);
  }

}
