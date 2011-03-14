Description
===========
Brings jQuery World Calendars API to Drupal.

Disclaimer
==========
This module is in an early development stage, It is not intended to be used in production.

Dependencies
============
 - Libraries API (http://drupal.org/project/libraries)

Requirements
============
 - jQuery 1.4.2 (http://code.jquery.com/jquery-1.4.2.min.js)
  Accessible via sites/all/libraries/jquery/jquery-1.4.2.min.js

 - jQuery Calendars library (http://keith-wood.name/calendars.html)
  Accessible via sites/all/libraries/jquery.calendars

Installation
============
 - Download and install Libraries API module as usual.
 - Download jQuery 1.4.2 and put it in sites/all/libraries/jquery/jquery-1.4.2.min.js
 - Download jQuery Calendars library and put it in sites/all/libraries/jquery.calendars
 - Goto sites/all/settings/jquery-calendars

API Usage
=========
Please see components section below for all available options, here is an API usage example used in the module itself:
  <?php
    jquery_calendars_add('picker, hebrew, persian, taiwan, thai, islamic, ethiopian, coptic, mayan', 'hebrew-he, persian-fa, gregorian-fr', 'smoothness', 'pack');
  ?>

Available Components
====================
  Library
  =======
   - base: base calendar support.
   - plus: additional features, date parsing, formatting, etc.
   - picker: datepicker with full calendar support and localisation.
   - picker.ext: datepicker extensions.
   - validation: validation plugin support for the datepicker.
   - all: contains base, plus and datepicker components all together.
   - lang: contains all Gregorian calendar locales.
   - picker.lang: contains all datepicker locales.

  Calendar Implementations
  ========================
   - Gregorian
   - Hebrew
   - Persian
   - Taiwan
   - Thai
   - Julian
   - Islamic
   - Ethiopian
   - Coptic
   - Mayan

  Themes
  ======
  jQuery UI themes will be supported soon.
   - Flora
   - Redmond
   - Humanity
   - Smoothness
   - jQuery Default

  Locales
  =======
   - Many! As per documented in code.

Author and Maintainer
=====================
Sepehr Lajevardi (http://drupal.org/user/668010)

