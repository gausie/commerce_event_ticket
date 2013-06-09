<?php
/**
 * @file
 * Entity controller for the Commerce Event Ticket entity.
 *
 * @class CommerceEventTicketController
 * @extends EntityAPIController
 */

class CommerceEventTicketController extends EntityAPIController {

  /**
   * Overrides EntityAPIController::save().
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $is_new = empty($entity->ticket_id);

    if ($is_new) {
      $entity->created = REQUEST_TIME;
    }
    $entity->changed = REQUEST_TIME;

    parent::save($entity, $transaction);
  }

}
