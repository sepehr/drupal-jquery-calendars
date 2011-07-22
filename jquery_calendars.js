/**
 * @file
 * Contains a jQuery World Calendars Datepicker demo javascript code.
 */

(function($) {
  /**
   * Attaches jQuery World Calendars demonstration behavior.
   */
  Drupal.behaviors.jqueryCalendarsDemo = {
    attach: function(context) {
      $picker = $('#datepicker-demo', context);
      $calendars = $('#datepicker-demo-calendars', context);

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
        }
      });

      // Bind onchange handler.
      $calendars.bind('change', function() {
        try {
          var calendar = $.calendars.instance($calendars.val());
          $picker
            .calendarsPicker('option', {
              calendar: calendar
            })
            .calendarsPicker('showMonth');
        }
        catch (e) {
          alert(e);
        }
      });
    }
  };
})(jQuery);
