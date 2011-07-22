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
      '#value' => $requirements['description'] . ' ' . t('Checkout the <a href="!link">status reports</a>.', array(
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
  $theme = variable_get('jquery_calendars_datepicker_theme', 'smoothness');
  $form['jquery_calendars_datepicker_theme'] = array(
    '#type' => 'select',
    '#title' => t('Datepicker default theme'),
    '#description' => t('Choose which datepicker theme you want to use. This will override datepicker theme settings set by other modules. You can add your own customized theme by placing it into the <code><u>!dir</u></code> directory respecting this filename format: <strong><em>theme-name</em>.calendars.picker.css</strong>',
      array('!dir' => 'sites/all/libraries/jquery.calendar')
    ),
    '#default_value' => $theme,
    '#options' => _jquery_calendars_datepicker_themes(),
  );

  global $base_path;
  // Demo wrapper fieldset.
  $form['datepicker_demo_wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Datepicker Demo'),
    '#description' => t('This is a jQuery World Calendars Datepicker demo based on your current saved settings. You might want to read <a href="!module">module</a> and <a href="!library">library</a> API docs.', array(
      '!library' => 'http://keith-wood.name/calendarsRef.html',
      '!module' => $base_path . drupal_get_path('module', 'jquery_calendars') . '/README.txt',
    )),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  // Demo itself.
  $form['datepicker_demo_wrapper']['demo'] = array(
    '#type' => 'item',
    '#markup' => '<select id="datepicker-demo-calendars">
      <option value="gregorian">' . t('Gregorian') . '</option>
      <option value="persian">' . t('Persian') . '</option>
      <option value="thai">' . t('Thai') . '</option>
      <option value="mayan">' . t('Mayan') . '</option>
      <option value="hebrew">' . t('Hebrew') . '</option>
      <option value="coptic">' . t('Coptic') . '</option>
      <option value="taiwan">' . t('Taiwan') . '</option>
      <option value="islamic">' . t('Islamic') . '</option>
      <option value="ethiopian">' . t('Ethopian') . '</option>
    </select>
    <div id="datepicker-demo"></div>',
  );
  // API usage & JS stuffs.
  $path = drupal_get_path('module', 'jquery_calendars');
  jquery_calendars_add('picker, picker.ext, hebrew, persian, taiwan, thai, islamic, ethiopian, coptic, mayan', array(), $theme);
  drupal_add_js($path . '/jquery_calendars.js');
  drupal_add_css($path . '/jquery_calendars.css');

  return system_settings_form($form);
}