<?php

/**
 * @file
 * Views field handler to display an event ticket with a link option.
 */

class commerce_event_ticket_views_handler_field extends views_handler_field {

  /**
   * Overrides parent::init().
   */
  public function init(&$view, &$options) {
    parent::init($view, $options);
    if (!empty($this->options['link_to_ticket'])) {
      $this->additional_fields['ticket_id'] = array(
        'table' => 'commerce_event_ticket',
        'field' => 'ticket_id',
      );
      $this->additional_fields['order_id'] = array(
        'table' => 'commerce_event_ticket',
        'field' => 'order_id',
      );
    }
  }

  /**
   * Overrides parent::option_definition().
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['link_to_ticket'] = array('default' => TRUE);
    return $options;
  }

  /**
   * Provide 'Link this field to the election' option.
   */
  public function options_form(&$form, &$form_state) {
    $form['link_to_ticket'] = array(
      '#title' => t('Link this field to the ticket'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_ticket']),
    );
    parent::options_form($form, $form_state);
  }

  /**
   * Render whatever the data is as a link to the ticket.
   *
   * Data should be made XSS safe prior to calling this function.
   */
  public function render_link($data, $values) {
    if (!empty($this->options['link_to_ticket'])) {
      if ($data !== NULL && $data !== '') {
        $this->options['alter']['make_link'] = TRUE;
        $order_id = (int) $this->get_value($values, 'order_id');
        $ticket_id = (int) $this->get_value($values, 'ticket_id');
        $this->options['alter']['path'] = 'admin/commerce/orders/' . $order_id . '/tickets/' . $ticket_id;
      }
      else {
        $this->options['alter']['make_link'] = FALSE;
      }
    }
    return $data;
  }

  /**
   * Overrides parent::render().
   */
  public function render($values) {
    $value = $this->get_value($values);
    return $this->render_link($this->sanitize_value($value), $values);
  }

}
