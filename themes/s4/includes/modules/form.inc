<?php

/*
function s4_button(&$vars) {
  $element = $vars['element'];
  $element['#attributes']['type'] = 'submit';
  element_set_attributes($element, array('id', 'name', 'value'));
  
  $element['#attributes']['class'][] = 'btn'; // Add bootstrap class
  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }

  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}
*/
/**
 * Returns HTML for a form.
 *
 * @param $vars
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #action, #method, #attributes, #children
 *
 * @ingroup themeable
 *  
 * 
 * function s4_preprocess_form(&$variables) {
 * }  
 * 
 * function s4_form($variables) {
 *   $element = $variables['element'];
 *   if (isset($element['#action'])) {
 *     $element['#attributes']['action'] = drupal_strip_dangerous_protocols($element['#action']);
 *   }
 *   
 *   element_set_attributes($element, array('method', 'id'));
 *   if (empty($element['#attributes']['accept-charset'])) {
 *     $element['#attributes']['accept-charset'] = "UTF-8";
 *   }
 * 
 *   return '<form' . drupal_attributes($element['#attributes']) . '>' . $element['#children'] . '</form>';
 * }
*/

/**
 * Implements hook_form_alter().
 */
function s4_form_alter(&$form, &$form_state, $form_id) {
  // Id's of forms that should be ignored
  // Make this configurable?
  $form_ids = array(
    'node_form',
    'system_site_information_settings',
    'user_profile_form',
  );
  
}  

/**
 * Returns HTML for a form element.
 */
function s4_form_element(&$variables) {
  $element = &$variables['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array('form-item', 'control-group');
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= '<div class="help-block">' . $element['#description'] . "</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}

/**
 * Returns HTML for a form element label and required marker.
 */
function s4_form_element_label(&$variables) {
  $element = $variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // If title and required marker are both empty, output no label.
  if ((!isset($element['#title']) || $element['#title'] === '') && empty($element['#required'])) {
    return '';
  }

  // If the element is required, a required marker is appended to the label.
  $required = !empty($element['#required']) ? theme('form_required_marker', array('element' => $element)) : '';

  $title = filter_xss_admin($element['#title']);

  $attributes = array();
  // Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after') {
    $attributes['class'][] = 'option';
    $attributes['class'][] = $element['#type'];
  }
  // Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $attributes['class'][] = 'element-invisible';
  }

  if (!empty($element['#id'])) {
    $attributes['for'] = $element['#id'];
  }

  // @Bootstrap: Add Bootstrap control-label class.
  $attributes['class'][] = 'control-label';

  // @Bootstrap: Insert radio and checkboxes inside label elements.
  $output = '';
  if ( isset($variables['#children']) ) {
    $output .= $variables['#children'];
  }

  // @Bootstrap: Append label
  $output .= $t('!title !required', array('!title' => $title, '!required' => $required));

  // The leading whitespace helps visually separate fields from inline labels.
  return ' <label' . drupal_attributes($attributes) . '>' . $output . "</label>\n";
}

/**
 * Preprocessor for theme('button').
 */
function s4_preprocess_button(&$vars) {
  $vars['element']['#attributes']['class'][] = 'btn';
  if(isset($vars['element']['#drop_down'])) {
    $list = array();
    foreach($vars['element']['#drop_down'] as $item) {
      $item['#drop_down_item'] = TRUE;
      $list[] = drupal_render($item);
    }
    $vars['element']['#prefix'] = '<div class="btn-group">';
    $vars['element']['#suffix'] = '<button class="btn dropdown-toggle btn-primary" data-toggle="dropdown">
    <span class="caret"></span>
  </button>'. theme('item_list', array('items' => $list, 'attributes' => array('class' => array('dropdown-menu')))) .
      '</div>';
  }
  if (isset($vars['element']['#drop_down_item']) && $vars['element']['#drop_down_item']) {
    $vars['element']['#attributes']['class'] = array();
    return;
  }
  if (isset($vars['element']['#value'])) {
    $classes = array(
      //specifics
      t('Save and add') => 'btn-info',
      t('Add another item') => 'btn-info',
      t('Add effect') => 'btn-primary',
      t('Add and configure') => 'btn-primary',
      t('Update style') => 'btn-primary',
      t('Download feature') => 'btn-primary',

      //generals
      t('Save') => 'btn-primary',
      t('Apply') => 'btn-primary',
      t('Create') => 'btn-primary',
      t('Confirm') => 'btn-primary',
      t('Submit') => 'btn-primary',
      t('Export') => 'btn-primary',
      t('Import') => 'btn-primary',
      t('Restore') => 'btn-primary',
      t('Rebuild') => 'btn-primary',
      t('Search') => 'btn-primary',
      t('Add') => 'btn-info',
      t('Update') => 'btn-info',
      t('Delete') => 'btn-danger',
      t('Remove') => 'btn-danger',
    );
    foreach ($classes as $search => $class) {
      if (strpos($vars['element']['#value'], $search) !== FALSE) {
        $vars['element']['#attributes']['class'][] = $class;
        break;
      }
    }
  }
}

function s4_form_required_marker($variables) {
  $t = get_t();
  $attributes = array(
    'class' => 'form-required label label-important', 
  );
  return '<span' . drupal_attributes($attributes) . '>' . $t('Required') . '</span>';
}

/**
 * Returns HTML for a button form element.
 */
function s4_button($variables) {
  $element = $variables['element'];
  $label = check_plain($element['#value']);
  element_set_attributes($element, array('id', 'name', 'value', 'type'));

  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }
  $prefix = (isset($element['#prefix'])) ? $element['#prefix'] : '';
  $suffix = (isset($element['#suffix'])) ? $element['#suffix'] : '';
  return $prefix . '<button' . drupal_attributes($element['#attributes']) . '>'. $label .'</button>
  ' . $suffix; // This line break adds inherent margin between multiple buttons
}

