<?php
/**
 * @file
 * Entity class for Commerce Event Ticket.
 *
 * @class CommerceEventTicketEntity
 * @extends Entity
 */

class CommerceEventTicketEntity extends Entity {

  public $ticket_id;
  public $type = 'ticket';
  public $barcode;
  public $order_id;
  public $line_item_id;
  public $product_id;
  public $uid;
  public $created;
  public $changed;

  /**
   * Overrides Entity::construct().
   *
   * {@inheritdoc}
   */
  public function __construct(array $values = array(), $entityType = NULL) {
    parent::__construct($values, $entityType);
    if (!$this->created) {
      $this->created = REQUEST_TIME;
    }
  }

}
