<?php

/**
*	The base class for all S4 web cases
*/
class s4WebTestCase extends DrupalWebTestCase {
  
  protected $privileged_user;
	
	var $profile = 'student_signup';
	
	var $roles = array(
		'authenticated' => array(
			'access content',
			'access own webform submissions',
			'access s4 dashboard',
			'create signup content',
			'create subscriptions',
			'get file expiration notifications',
			'maintain own subscriptions',
			'manage own subscriptions',
			'search content',
			'signup for service',
			'subscribe to content',
			'view date repeats'
		),
		'staff' => array(
		  'access all webform results',
			'access comments',
			'access contextual links',
			'access own webform results',
			'access user profiles',
			'administer users',
			'create contact_record content',
			'create coordinator content',
			'create course content',
			'create course_term content',
			'create file content',
			'create page content',
			'create site content',
			'create webform content',
			'delete all webform submissions',
			'delete any contact_record content',
			'delete any coordinator content',
			'delete any course content',
			'delete any course_term content',
			'delete any file content',
			'delete any page content',
			'delete any signup content',
			'delete any site content',
			'delete any webform content',
			'delete own contact_record content',
			'delete own coordinator content',
			'delete own course content',
			'delete own course_term content',
			'delete own file content',
			'delete own page content',
			'delete own signup content',
			'delete own site content',
			'delete own webform content',
			'delete own webform submissions',
			'delete revisions',
			'delete terms in 1',
			'delete terms in 2',
			'delete terms in 3',
			'delete terms in 4',
			'delete terms in 5',
			'delete terms in 6',
			'edit any contact_record content',
			'edit any coordinator content',
			'edit any course content',
			'edit any course_term content',
			'edit any file content',
			'edit any page content',
			'edit any signup content',
			'edit any site content',
			'edit any webform content',
			'edit boxes',
			'edit own comments',
			'edit own contact_record content',
			'edit own coordinator content',
			'edit own course content',
			'edit own course_term content',
			'edit own file content',
			'edit own page content',
			'edit own signup content',
			'edit own site content',
			'edit own webform content',
			'edit own webform submissions',
			'edit terms in 1',
			'edit terms in 2',
			'edit terms in 3',
			'edit terms in 4',
			'edit terms in 5',
			'edit terms in 6',
			'post comments',
			'revert revisions',
			'save draft',
			'skip comment approval',
			'subscribe to content type',
			'use advanced search',
			'use views savedsearch',
			'view own unpublished content',
			'view revisions',
		),
		'administrator' => array(
			'access administration pages',
			'access all views',
			'access all webform results',
			'access comments',
			'access content overview',
			'access contextual links',
			'access dashboard',
			'access own webform results',
			'access own webform submissions',
			'access site in maintenance mode',
			'access site reports',
			'access toolbar',
			'administer actions',
			'administer blocks',
			'administer boxes',
			'administer comments',
			'administer content types',
			'administer date tools',
			'administer fancybox',
			'administer features',
			'administer fieldgroups',
			'administer filters',
			'administer flags',
			'administer image styles',
			'administer imce',
			'administer languages',
			'administer menu',
			'administer messaging',
			'administer modules',
			'administer nodes',
			'administer notifications',
			'administer page manager',
			'administer pathauto',
			'administer permissions',
			'administer search',
			'administer shortcuts',
			'administer site configuration',
			'administer software updates',
			'administer taxonomy',
			'administer themes',
			'administer url aliases',
			'administer users',
			'administer views',
			'administer views calc',
			'block IP addresses',
			'bypass node access',
			'cancel account',
			'change own username',
			'create contact_record content',
			'create coordinator content',
			'create course content',
			'create course_term content',
			'create file content',
			'create gmap macro',
			'create page content',
			'create signup content',
			'create site content',
			'create url aliases',
			'create views calc',
			'create webform content',
			'delete all webform submissions',
			'delete any contact_record content',
			'delete any coordinator content',
			'delete any course content',
			'delete any course_term content',
			'delete any file content',
			'delete any page content',
			'delete any signup content',
			'delete any site content',
			'delete any webform content',
			'delete own contact_record content',
			'delete own coordinator content',
			'delete own course content',
			'delete own course_term content',
			'delete own file content',
			'delete own page content',
			'delete own signup content',
			'delete own site content',
			'delete own webform content',
			'delete own webform submissions',
			'delete revisions',
			'delete terms in 1',
			'delete terms in 2',
			'delete terms in 3',
			'delete terms in 4',
			'delete terms in 5',
			'delete terms in 6',
			'delete terms in 7',
			'edit all webform submissions',
			'edit any contact_record content',
			'edit any coordinator content',
			'edit any course content',
			'edit any course_term content',
			'edit any file content',
			'edit any page content',
			'edit any signup content',
			'edit any site content',
			'edit any webform content',
			'edit boxes',
			'edit own comments',
			'edit own contact_record content',
			'edit own coordinator content',
			'edit own course content',
			'edit own course_term content',
			'edit own file content',
			'edit own page content',
			'edit own signup content',
			'edit own site content',
			'edit own webform content',
			'edit own webform submissions',
			'edit terms in 1',
			'edit terms in 2',
			'edit terms in 3',
			'edit terms in 4',
			'edit terms in 5',
			'edit terms in 6',
			'edit terms in 7',
			'manage all subscriptions',
			'manage features',
			'notify of path changes',
			'post comments',
			'revert revisions',
			'save draft',
			'select account cancellation method',
			'show input filter select menu',
			'skip comment approval',
			'skip notifications',
			'submit latitude/longitude',
			'subscribe to content type',
			'translate interface',
			'use advanced search',
			'use all savedsearches',
			'use page manager',
			'Use PHP for title patterns',
			'Use PHP input for field settings (dangerous - grant with care)',
			'use text format full_html',
			'use views savedsearch',
			'view location directory',
			'view node location table',
			'view node map',
			'view own unpublished content',
			'view revisions',
			'view the administration theme',
			'view user location details',
			'view user location table',
			'view user map'
		),
	);
	
}