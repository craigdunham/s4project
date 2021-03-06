<?php
/**
 * @file
 * s4_sites.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function s4_sites_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'map';
  $context->description = 'User is on the large site map';
  $context->tag = 'sites';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'map' => 'map',
        'map*' => 'map*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-location_gmap-page' => array(
          'module' => 'views',
          'delta' => '-exp-location_gmap-page',
          'region' => 'content_top_left',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the large site map');
  t('sites');
  $export['map'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site';
  $context->description = 'User is on a site page';
  $context->tag = 'sites';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'site' => 'site',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        '~node/*/talk' => '~node/*/talk',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_sites-s4_sites_merge_link' => array(
          'module' => 's4_sites',
          'delta' => 's4_sites_merge_link',
          'region' => 'content_subscriptions',
          'weight' => '1',
        ),
        's4_mail-s4_mail_subscribe' => array(
          'module' => 's4_mail',
          'delta' => 's4_mail_subscribe',
          'region' => 'content_subscriptions',
          'weight' => '2',
        ),
      ),
    ),
    'menu' => 'site',
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on a site page');
  t('sites');
  $export['site'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site-file';
  $context->description = 'User is on a site file page';
  $context->tag = 'site';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'file' => 'file',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'site',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on a site file page');
  t('site');
  $export['site-file'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site-form-view';
  $context->description = 'User is viewing a site form';
  $context->tag = 'sites';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'file' => 'file',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_sites-s4_sites_form_webform' => array(
          'module' => 's4_sites',
          'delta' => 's4_sites_form_webform',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is viewing a site form');
  t('sites');
  $export['site-form-view'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site-list';
  $context->description = 'User is on the site list and search page';
  $context->tag = 'sites';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'site-list' => 'site-list',
        'site-list*' => 'site-list*',
        '~site-list/manage' => '~site-list/manage',
        '~site-list/manage/*' => '~site-list/manage/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_core-s4_add_new_site' => array(
          'module' => 's4_core',
          'delta' => 's4_add_new_site',
          'region' => 'content_subscriptions',
          'weight' => '-10',
        ),
        's4_courses-s4_courses_add_message' => array(
          'module' => 's4_courses',
          'delta' => 's4_courses_add_message',
          'region' => 'content_subscriptions',
          'weight' => '-9',
        ),
        's4_core-site_list_course_restriction' => array(
          'module' => 's4_core',
          'delta' => 'site_list_course_restriction',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
    'menu' => 'site',
    'theme_html' => array(
      'class' => 'site-list',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the site list and search page');
  t('sites');
  $export['site-list'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site-list-link';
  $context->description = 'Site menu should be enabled';
  $context->tag = 'sites';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'site-list/*' => 'site-list/*',
        'site-list' => 'site-list',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'site-list',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Site menu should be enabled');
  t('sites');
  $export['site-list-link'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site-list-staff';
  $context->description = 'User is on the site list for staff page';
  $context->tag = 'sites';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        's4_manage_sites:page' => 's4_manage_sites:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_mail-s4_manage_subscriptions' => array(
          'module' => 's4_mail',
          'delta' => 's4_manage_subscriptions',
          'region' => 'content_subscriptions',
          'weight' => '-10',
        ),
        's4_core-s4_add_new_site' => array(
          'module' => 's4_core',
          'delta' => 's4_add_new_site',
          'region' => 'content_subscriptions',
          'weight' => '-9',
        ),
      ),
    ),
    'menu' => 'site',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the site list for staff page');
  t('sites');
  $export['site-list-staff'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site-location-list';
  $context->description = 'User is on the site location listing';
  $context->tag = 'sites';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'sites/*/locations' => 'sites/*/locations',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_sites-s4_sites_search_map' => array(
          'module' => 's4_sites',
          'delta' => 's4_sites_search_map',
          'region' => 'content_right',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'site-list',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the site location listing');
  t('sites');
  $export['site-location-list'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site-log';
  $context->description = 'User is on the log tab of a site.';
  $context->tag = 'sites';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*/site-log' => 'node/*/site-log',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_sites-s4_sites_add_log' => array(
          'module' => 's4_sites',
          'delta' => 's4_sites_add_log',
          'region' => 'content_subscriptions',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the log tab of a site.');
  t('sites');
  $export['site-log'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site-manage';
  $context->description = 'User is on the manage sites page';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'site-list/manage' => 'site-list/manage',
        'site-list/manage*' => 'site-list/manage*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'site',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the manage sites page');
  $export['site-manage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site-moderation';
  $context->description = 'User is viewing the site moderation tab';
  $context->tag = 'sites';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*/moderation' => 'node/*/moderation',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-contact_records-block_1' => array(
          'module' => 'views',
          'delta' => 'contact_records-block_1',
          'region' => 'content_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is viewing the site moderation tab');
  t('sites');
  $export['site-moderation'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site-staff';
  $context->description = 'User is on the site staff page';
  $context->tag = 'sites';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*/site-staff' => 'node/*/site-staff',
      ),
    ),
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'staff' => 'staff',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_core-s4_add_new_coordinator' => array(
          'module' => 's4_core',
          'delta' => 's4_add_new_coordinator',
          'region' => 'content_subscriptions',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the site staff page');
  t('sites');
  $export['site-staff'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site-students';
  $context->description = 'User is on the site students list';
  $context->tag = 'site';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*/students' => 'node/*/students',
        'node/*/students*' => 'node/*/students*',
      ),
    ),
    'user' => array(
      'values' => array(
        'staff' => 'staff',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-site_signups-block' => array(
          'module' => 'views',
          'delta' => 'site_signups-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the site students list');
  t('site');
  $export['site-students'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'view-site-staff';
  $context->description = 'User is viewing a site staff';
  $context->tag = 'sites';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'coordinator' => 'coordinator',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'site',
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is viewing a site staff');
  t('sites');
  $export['view-site-staff'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'views-contact-records';
  $context->description = 'User is on a generic view page';
  $context->tag = 'views';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*/contact-records' => 'node/*/contact-records',
        'node/*/contact-records*' => 'node/*/contact-records*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'site-list',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on a generic view page');
  t('views');
  $export['views-contact-records'] = $context;

  return $export;
}
