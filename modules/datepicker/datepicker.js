// $Id$

/**
 * @file
 * Contains Datepicker Form Element JS behavior.
 */

/**
 * Datepicker JS behavior that initialized the jQuery World Calendar
 * Datepicker foreach object in Drupal.settings.datepicker.
 */
Drupal.behaviors.datepicker = function(context) {
  for (var id in Drupal.settings.datepicker) {
    var datepicker = Drupal.settings.datepicker[id];

    // Initialize the Calendar.
    datepicker.options.calendar = $.calendars.instance(datepicker.calendar, datepicker.locale);

    // And the Evil Eval!
    // datepicker.options.commands = eval(datepicker.calendar.commands);

    // And initialize the Datepicker.
    $(context).find('#' + id).calendarsPicker(datepicker.options);
  }
};

