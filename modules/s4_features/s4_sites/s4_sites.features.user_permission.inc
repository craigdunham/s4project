<?php
/**
 * @file
 * s4_sites.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function s4_sites_user_default_permissions() {
  $permissions = array();

  // Exported permission: create contact_record content
  $permissions['create contact_record content'] = array(
    'name' => 'create contact_record content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create coordinator content
  $permissions['create coordinator content'] = array(
    'name' => 'create coordinator content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create file content
  $permissions['create file content'] = array(
    'name' => 'create file content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: create site content
  $permissions['create site content'] = array(
    'name' => 'create site content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any contact_record content
  $permissions['delete any contact_record content'] = array(
    'name' => 'delete any contact_record content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any coordinator content
  $permissions['delete any coordinator content'] = array(
    'name' => 'delete any coordinator content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any file content
  $permissions['delete any file content'] = array(
    'name' => 'delete any file content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any site content
  $permissions['delete any site content'] = array(
    'name' => 'delete any site content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own contact_record content
  $permissions['delete own contact_record content'] = array(
    'name' => 'delete own contact_record content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own coordinator content
  $permissions['delete own coordinator content'] = array(
    'name' => 'delete own coordinator content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own file content
  $permissions['delete own file content'] = array(
    'name' => 'delete own file content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own site content
  $permissions['delete own site content'] = array(
    'name' => 'delete own site content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in 1
  $permissions['delete terms in 1'] = array(
    'name' => 'delete terms in 1',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 2
  $permissions['delete terms in 2'] = array(
    'name' => 'delete terms in 2',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 3
  $permissions['delete terms in 3'] = array(
    'name' => 'delete terms in 3',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 4
  $permissions['delete terms in 4'] = array(
    'name' => 'delete terms in 4',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 5
  $permissions['delete terms in 5'] = array(
    'name' => 'delete terms in 5',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 6
  $permissions['delete terms in 6'] = array(
    'name' => 'delete terms in 6',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'taxonomy',
  );
  
  // Exported permission: edit terms in 7
  $permissions['edit terms in 7'] = array(
    'name' => 'edit terms in 7',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'taxonomy',
  );
  
  // Exported permission: delete terms in 7
  $permissions['delete terms in 7'] = array(
    'name' => 'delete terms in 7',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any contact_record content
  $permissions['edit any contact_record content'] = array(
    'name' => 'edit any contact_record content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any coordinator content
  $permissions['edit any coordinator content'] = array(
    'name' => 'edit any coordinator content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any file content
  $permissions['edit any file content'] = array(
    'name' => 'edit any file content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any site content
  $permissions['edit any site content'] = array(
    'name' => 'edit any site content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own contact_record content
  $permissions['edit own contact_record content'] = array(
    'name' => 'edit own contact_record content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own coordinator content
  $permissions['edit own coordinator content'] = array(
    'name' => 'edit own coordinator content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own file content
  $permissions['edit own file content'] = array(
    'name' => 'edit own file content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own site content
  $permissions['edit own site content'] = array(
    'name' => 'edit own site content',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: edit terms in 1
  $permissions['edit terms in 1'] = array(
    'name' => 'edit terms in 1',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 2
  $permissions['edit terms in 2'] = array(
    'name' => 'edit terms in 2',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 3
  $permissions['edit terms in 3'] = array(
    'name' => 'edit terms in 3',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 4
  $permissions['edit terms in 4'] = array(
    'name' => 'edit terms in 4',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 5
  $permissions['edit terms in 5'] = array(
    'name' => 'edit terms in 5',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 6
  $permissions['edit terms in 6'] = array(
    'name' => 'edit terms in 6',
    'roles' => array(
      0 => 'administrator',
      1 => 'staff',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}