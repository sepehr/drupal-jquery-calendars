// $Id$

Description
===========
Extends Form API to be able to use jQuery World Calendars Datepicker as a form field type.


Dependencies
============
- jQuery Calendars module and its requirements.


Form API Example
================
/**
 * MyModule form callback.
 */
function mymodule_settings_form() {
  $form = array();

  $form['mymodule_date'] = array(
    '#type' => 'datepicker',
    ...
  );

  return system_settings_form($form);
}


Author and Maintainer
=====================
Sepehr Lajevardi (http://drupal.org/user/668010)

