<?php
/**
 * @file
 * Entity controller class for Commerce Event Ticket.
 */

class CommerceEventTicketController extends EntityAPIController {

  /**
   * Overrides EntityAPIController::save().
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {

    // Determine whether the entity is new.
    $entity->is_new = empty($entity->ticket_id);

    // Set the 'created' and 'changed' properties.
    if (empty($entity->created)) {
      $entity->created = REQUEST_TIME;
    }
    $entity->changed = REQUEST_TIME;

    parent::save($entity, $transaction);

  }

}
