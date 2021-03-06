<?php

class views_handler_s4_user_coordinator_select extends views_handler_field {

  function render($values) {
    if (!isset($_SESSION['s4_signup_site'])) {
      return '<div class="signup denied"><div class="icon"></div>' .
        t('Select a site first.')
        . '</div>';
    }
    $coordinator = node_load($values->nid);
    if (_s4_core_object_is_full($coordinator)) {
      return '<div class="signup denied"><div class="icon"></div>' .
        t('Site staff unavailable.')
        . '</div>';
    }
    if (isset($_SESSION['s4_signup_coordinator']) && $_SESSION['s4_signup_coordinator'] == $values->nid) {
      return '<div class="signup signed-up"><div class="icon"></div>Site staff selected</div>';
    }
    return l('<i class="icon-ok-circle icon-white"></i> ' . ('Select this site staff'), 's4/signup/coordinator/' . $values->nid,
        array('html' => TRUE, 'attributes' => array('class' => array('btn', 'btn-primary'), 'data-target' => 'signup-course')));
  }

  function query() {

  }
}