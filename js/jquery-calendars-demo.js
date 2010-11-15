// $Id$

/**
 * @file
 * Contains a jQuery World Calendars Datepicker demo javascript code.
 */

$(document).ready(function() {
  var $picker = $('#datepicker-demo'),
      $calendars = $('#datepicker-demo-calendars');
      
  $picker.calendarsPicker({
    monthsToShow: [2, 3],
    showOtherMonths: false,
    calendar: $.calendars.instance($calendars.val()),
    onShow: $.calendars.picker.showStatus,
    renderer: $.calendars.picker.weekOfYearRenderer, 
    onSelect: function(date) {
      alert(Drupal.t('You picked @date.',
        {'@date': date[0].formatDate()}
      ));
    },
  });
  
  $calendars.bind('change', function() {
    try {
      var calendar = $.calendars.instance($calendars.val());
      $picker.calendarsPicker('option', {calendar: calendar} ).calendarsPicker('showMonth');
    }
    catch (e) {
      alert(e);
    }
  });
});

