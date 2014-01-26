(function($) {
  Drupal.behaviors.initialRedirect = {
    attach: function (context, settings) {
      // Require that:
      // 1. Settings are loaded.
      // 2. URL is not blank.
      // 3. jquery.cookie is ready / working.
      // 4. We haven't redirected here before.
      if (Drupal.settings.initialRedirect &&
          Drupal.settings.initialRedirect.url &&
          $.cookie &&
          Drupal.settings.initialRedirect.ts > $.cookie('initialRedirectTimestamp')) {
        // We store (1) the last redirect we sent and (2) where it
        // went, in case we ever need to check / compare later.
        if (!window.location.href.match('/admin')) {
          $.cookie('initialRedirectTimestamp', Drupal.settings.initialRedirect.ts);
          $.cookie('initialRedirectURL', Drupal.settings.initialRedirect.url);
          // Redirect, appending redirectFrom URL param.
          sep = Drupal.settings.initialRedirect.url.indexOf('?') > 0 ? '&' : '?';
          window.location.href = Drupal.settings.initialRedirect.url + sep +
            'redirectFrom=' + window.location.href;
        }
      }
    }
  };
})(jQuery);
