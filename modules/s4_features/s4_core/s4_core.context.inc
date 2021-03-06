<?php
/**
 * @file
 * s4_core.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function s4_core_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'anonymous-site';
  $context->description = 'Anonymous user is viewing a site';
  $context->tag = 'anonymous';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'site' => 'site',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-site_coordinators-block' => array(
          'module' => 'views',
          'delta' => 'site_coordinators-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Anonymous user is viewing a site');
  t('anonymous');
  $export['anonymous-site'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'authenticated';
  $context->description = 'User is authenticated';
  $context->tag = 'user';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_help-s4_contextual_help' => array(
          'module' => 's4_help',
          'delta' => 's4_contextual_help',
          'region' => 'search',
          'weight' => '-10',
        ),
        's4_core-user_progress' => array(
          'module' => 's4_core',
          'delta' => 'user_progress',
          'region' => 'content_top_wide',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is authenticated');
  t('user');
  $export['authenticated'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'basic-page';
  $context->description = '';
  $context->tag = 'content';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'page' => 'page',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('content');
  $export['basic-page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'forms-listing-page';
  $context->description = 'User is viewing the form listing page';
  $context->tag = 'sites';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'forms' => 'forms',
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
        's4_core-s4_add_forms' => array(
          'module' => 's4_core',
          'delta' => 's4_add_forms',
          'region' => 'content_subscriptions',
          'weight' => '-10',
        ),
        'views-site_forms-block_1' => array(
          'module' => 'views',
          'delta' => 'site_forms-block_1',
          'region' => 'content_right',
          'weight' => '-10',
        ),
      ),
    ),
    'menu' => 'form',
    'theme_html' => array(
      'class' => 'equal-columns',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is viewing the form listing page');
  t('sites');
  $export['forms-listing-page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'frontpage-anonymous';
  $context->description = 'An anonymous user use viewing the homepage';
  $context->tag = 'frontpage';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'homepage' => 'homepage',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_pages-overview_paragraph' => array(
          'module' => 's4_pages',
          'delta' => 'overview_paragraph',
          'region' => 'content_top_left',
          'weight' => '-10',
        ),
        's4_core-s4_user_login' => array(
          'module' => 's4_core',
          'delta' => 's4_user_login',
          'region' => 'content_top_left',
          'weight' => '-9',
        ),
        's4_pages-program_listing' => array(
          'module' => 's4_pages',
          'delta' => 'program_listing',
          'region' => 'content_top_left',
          'weight' => '-8',
        ),
        's4_core-s4_welcome_message' => array(
          'module' => 's4_core',
          'delta' => 's4_welcome_message',
          'region' => 'content_top_right',
          'weight' => '-10',
        ),
        's4_map-s4_map_site_map' => array(
          'module' => 's4_map',
          'delta' => 's4_map_site_map',
          'region' => 'footer_map',
          'weight' => '-10',
        ),
      ),
    ),
    'menu' => '<front>',
    'theme_html' => array(
      'class' => 'front',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('An anonymous user use viewing the homepage');
  t('frontpage');
  $export['frontpage-anonymous'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'frontpage-staff';
  $context->description = 'A staff member is on the front page';
  $context->tag = 'frontpage';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'homepage' => 'homepage',
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
        'menu-menu-staff-actions' => array(
          'module' => 'menu',
          'delta' => 'menu-staff-actions',
          'region' => 'content_top_left',
          'weight' => '-47',
        ),
        's4_reporting-course_summary' => array(
          'module' => 's4_reporting',
          'delta' => 'course_summary',
          'region' => 'content_top_left',
          'weight' => '-46',
        ),
        's4_reporting-site_summary' => array(
          'module' => 's4_reporting',
          'delta' => 'site_summary',
          'region' => 'content_top_right',
          'weight' => '-50',
        ),
        'views-sites-block_1' => array(
          'module' => 'views',
          'delta' => 'sites-block_1',
          'region' => 'content_top_right',
          'weight' => '-49',
        ),
        'views-recent_actions-block' => array(
          'module' => 'views',
          'delta' => 'recent_actions-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'staff-frontpage',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('A staff member is on the front page');
  t('frontpage');
  $export['frontpage-staff'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search';
  $context->description = 'User is on the site-wide search page';
  $context->tag = 'search';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        's4_search' => 's4_search',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-s4_search-page' => array(
          'module' => 'views',
          'delta' => '-exp-s4_search-page',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'site-search',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the site-wide search page');
  t('search');
  $export['search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search-staff';
  $context->description = 'A staff member is on the search page';
  $context->tag = 'search';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'staff' => 'staff',
      ),
    ),
    'views' => array(
      'values' => array(
        's4_search:page' => 's4_search:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-s4_search_students-block' => array(
          'module' => 'views',
          'delta' => 's4_search_students-block',
          'region' => 'content_right',
          'weight' => '-10',
        ),
        'views-s4_search-block_1' => array(
          'module' => 'views',
          'delta' => 's4_search-block_1',
          'region' => 'content_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('A staff member is on the search page');
  t('search');
  $export['search-staff'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'signup-form-page';
  $context->description = 'User is viewing the signup form list';
  $context->tag = 'signup';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'forms/download' => 'forms/download',
        'forms/download/*' => 'forms/download/*',
      ),
    ),
    'views' => array(
      'values' => array(
        'site_forms:page_3' => 'site_forms:page_3',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_core-s4_signup_forms' => array(
          'module' => 's4_core',
          'delta' => 's4_signup_forms',
          'region' => 'content_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is viewing the signup form list');
  t('signup');
  $export['signup-form-page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = '';
  $context->tag = 'sitewide';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_core-s4_site_settings' => array(
          'module' => 's4_core',
          'delta' => 's4_site_settings',
          'region' => 'search',
          'weight' => '-10',
        ),
        'views--exp-s4_search-page' => array(
          'module' => 'views',
          'delta' => '-exp-s4_search-page',
          'region' => 'search',
          'weight' => '-9',
        ),
        's4_core-s4_current_user_link' => array(
          'module' => 's4_core',
          'delta' => 's4_current_user_link',
          'region' => 'search',
          'weight' => '-8',
        ),
        'system-help' => array(
          'module' => 'system',
          'delta' => 'help',
          'region' => 'help',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('sitewide');
  $export['sitewide'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'staff';
  $context->description = 'User has the "staff" role and can manage content';
  $context->tag = 'user';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'staff' => 'staff',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User has the "staff" role and can manage content');
  t('user');
  $export['staff'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user-login-page';
  $context->description = 'User is on the login screen and is not authenticated';
  $context->tag = 'user';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user' => 'user',
        'user/*' => 'user/*',
        'user?*' => 'user?*',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        's4_core-s4_user_login_message' => array(
          'module' => 's4_core',
          'delta' => 's4_user_login_message',
          'region' => 'content_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the login screen and is not authenticated');
  t('user');
  $export['user-login-page'] = $context;

  return $export;
}
