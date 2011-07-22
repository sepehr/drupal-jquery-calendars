<?php

/**
 * @file
 * Contains administration and demonstration form callbacks.
 */

/**
 * Form callback for jQuery World Calendars administration.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function jquery_calendars_admin_settings() {
  $form = array();

  // If the module is not correctly installed, do not show configs.
  $requirements = array_pop(_jquery_calendars_requirements_check());
  if ($requirements['severity'] == REQUIREMENT_ERROR) {
    // Inject the requirements description to a form field.
    $form['jquery_calendars_error'] = array(
      '#type' => 'item',
      '#markup' => $requirements['description'] . ' ' . t('Checkout the <a href="!link">status reports</a>.', array(
        '!link' => url('admin/reports/status')
      )),
    );
    // And let the form be rendered.
    return $form;
  }

  // Library compression level.
  $form['jquery_calendars_compression_level'] = array(
    '#type' => 'radios',
    '#title' => t('Library default compression level'),
    '#description' => t('Choose default library files compression level. This will be used as a fallback in case that the API implementer does not provide a level.'),
    '#default_value' => variable_get('jquery_calendars_compression_level', 'pack'),
    '#options' => array(
      'pack' => t('Packed - <em>7.1K core.</em>'),
      'min' => t('Minified - <em>10.6K core.</em>'),
      'normal' => t('No Compression - <em>30.3K core.</em>'),
    ),
  );
  // Calendars default theme.
  $form['jquery_calendars_datepicker_theme'] = array(
    '#type' => 'select',
    '#title' => t('Datepicker default theme'),
    '#description' => t('Choose which datepicker theme you want to use. This will override datepicker theme settings set by other modules. You can add your own customized theme by placing it into the <code><u>!dir</u></code> directory respecting this filename format: <strong><em>theme-name</em>.calendars.picker.css</strong>',
      array('!dir' => 'sites/all/libraries/jquery.calendar')
    ),
    '#default_value' => variable_get('jquery_calendars_datepicker_theme', 'smoothness'),
    '#options' => _jquery_calendars_datepicker_themes(),
  );

  return system_settings_form($form);
}

/**
 * Form callback for jQuery World Calendars demonstration.
 *
 * @ingroup forms
 */
function jquery_calendars_form_demo() {
  $form = array();

  // If the module is not correctly installed, do not show configs.
  $requirements = array_pop(_jquery_calendars_requirements_check());
  if ($requirements['severity'] == REQUIREMENT_ERROR) {
    // Inject the requirements description to a form field.
    $form['jquery_calendars_error'] = array(
      '#type' => 'item',
      '#markup' => $requirements['description'] . ' ' . t('Checkout the <a href="!link">status reports</a>.', array(
        '!link' => url('admin/reports/status')
      )),
    );
    // And let the form be rendered.
    return $form;
  }

  global $base_path;
  // Calendar select widget:
  $form['datepicker_demo_wrapper']['demo'] = array(
    '#type' => 'select',
    '#title' => t('Choose'),
    '#description' => t('Choose the demonstration calendar system.'),
    '#default_value' => 'gregorian',
    '#attributes' => array('id' => 'datepicker-demo-calendars'),
    '#options' => array(
      'gregorian' => t('Gregorian'),
      'persian' => t('Persian'),
      'thai' => t('Thai'),
      'mayan' => t('Mayan'),
      'hebrew' => t('Hebrew'),
      'coptic' => t('Coptic'),
      'taiwan' => t('Taiwan'),
      'islamic' => t('Islamic'),
      'ethiopian' => t('Ethiopian'),
    ),
    '#suffix' => '<div id="datepicker-demo"></div>',
  );

  // API usage example:
  jquery_calendars_add(
    // Load this list of library components.
    'picker, picker.ext, hebrew, persian, taiwan, thai, islamic, ethiopian, coptic, mayan',
    // Load no locales.
    array(),
    // Load the user theme, or use smoothness theme as default.
    variable_get('jquery_calendars_datepicker_theme', 'smoothness')
  );

  // Add demonstration specific JS and CSS files:
  $path = drupal_get_path('module', 'jquery_calendars');
  drupal_add_js($path . '/jquery_calendars.js');
  drupal_add_css($path . '/jquery_calendars.css');

  return $form;
}
