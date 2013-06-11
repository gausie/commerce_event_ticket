<?php
/**
 * @file
 * Entity class for Commerce Event Ticket.
 */

class CommerceEventTicketEntity extends Entity {

  public $ticket_id;
  public $type = 'ticket';
  public $barcode_token;
  public $order_id;
  public $line_item_id;
  public $product_id;
  public $uid;
  public $number = 1;
  public $created;
  public $changed;

}
