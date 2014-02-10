<?php

/**
 * @file
 * Views field handler to display a download link for a single event ticket PDF.
 */

class commerce_event_ticket_pdf_views_handler_field_link extends views_handler_field {

  /**
   * Overrides parent::option_definition().
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array(
      'default' => t('Download ticket'),
      'translatable' => TRUE,
    );
    return $options;
  }

  /**
   * Overrides parent::options_form().
   */
  public function options_form(&$form, &$form_state) {
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
    parent::options_form($form, $form_state);
  }

  /**
   * Overrides parent::render().
   */
  public function render($values) {
    $ticket_id = $this->get_value($values);

    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = 'commerce-event-ticket-pdf/download/' . $ticket_id;
    $this->options['alter']['query'] = array(
      'token' => drupal_get_token($ticket_id),
    );

    $text = !empty($this->options['text']) ? $this->options['text'] : t('Download ticket');
    return $text;
  }
}
