<?php

/**
 * @file
 * Views field handler to display a download link for an order's tickets.
 */

class commerce_event_ticket_pdf_views_handler_field_link_order extends commerce_event_ticket_pdf_views_handler_field_link {

  /**
   * Overrides parent::option_definition().
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['text']['default'] = t('Download tickets');
    return $options;
  }

  /**
   * Overrides parent::render().
   */
  public function render($values) {
    $order_id = $this->get_value($values);

    $order = commerce_order_load($order_id);
    if (!_commerce_event_ticket_order_should_have_tickets($order)) {
      return;
    }

    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = 'commerce-event-ticket-pdf/download/order/' . $order_id;
    $this->options['alter']['query'] = array(
      'token' => drupal_get_token($order_id),
    );

    $text = !empty($this->options['text']) ? $this->options['text'] : t('Download tickets');
    return $text;
  }
}
