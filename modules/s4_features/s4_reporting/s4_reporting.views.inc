<?php

/**
*  @file Views hooks
*/

/**
*  Implementation of hook_views_data
*/
function s4_reporting_views_data() {
  $data['s4_reporting']['table']['group'] = t('Form Evaluation');
  $data['s4_reporting']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  $data['s4_reporting']['webform_report_result'] = array(
    'title' => t('Webform site result'),
    'help' => t('The end user is selecting this course to signup with.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  return $data;
}

/**
 * Implements hook_views_plugins().
 */
function s4_reporting_views_plugins() {
  return array(
    'exposed_form' => array(
      's4_reporting' => array(
        'title' => t('S4 grouped reporting'),
        'help' => t('Groups fields into vertical tabs'),
        'handler' => 's4_reporting_exposed_form_plugin',
        'uses row plugin' => FALSE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'parent' => 'basic',
      ),
    ),
  );
}