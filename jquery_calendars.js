/**
 * @file
 * Contains a jQuery Calendars Datepicker demonstration JS behaviors.
 */

/**
 * jQuery Calendars demo initializer.
 */
Drupal.behaviors.jqueryCalendarsDemo = function(context) {
  var $picker = $(context).find('#datepicker-demo'),
      $calendars = $(context).find('#datepicker-demo-calendars');

  // Initialize the library.
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

  // Bind onchange handler.
  $calendars.bind('change', function() {
    try {
      var calendar = $.calendars.instance($calendars.val());
      $picker
        .calendarsPicker('option', {
          calendar: calendar,
        })
        .calendarsPicker('showMonth');
    }
    catch (e) {
      alert(e);
    }
  });
};

