(function($) {
  Drupal.behaviors.initialRedirect = {
    attach: function (context, settings) {
      // Require that:
      // 1. Settings are loaded.
      // 2. URL is not blank.
      // 3. jStorage is ready / working.
      // 4. We haven't redirected here before.
      if (Drupal.settings.initialRedirect &&
          Drupal.settings.initialRedirect.url &&
          $.jStorage &&
          Drupal.settings.initialRedirect.ts > $.jStorage.get('initialRedirectTimestamp', 1)) {
        // We store (1) the last redirect we sent and (2) where it
        // went, in case we ever need to check / compare later.
        $.jStorage.set('initialRedirectTimestamp', Drupal.settings.initialRedirect.ts);
        $.jStorage.set('initialRedirectURL', Drupal.settings.initialRedirect.url);
        window.location.href = Drupal.settings.initialRedirect.url;
      }
    }
  };
})(jQuery);
