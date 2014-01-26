<?php

/**
 * Form builder function for module settings.
 */
function initial_redirect_settings() {
  $form['initial_redirect_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirect URL'),
    '#default_value' => variable_get('initial_redirect_url', NULL),
    '#description' => t('URL to redirect initial visitors to. No redirects will occur if this is left blank or the "Enable" box below is unchecked.'),
  );
  $form['initial_redirect_active'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable initial redirect.'),
    '#description' => t('Redirect visitors to the URL above on first visit to the site. Uncheck to disable.'),
    '#default_value' => variable_get('initial_redirect_active', FALSE),
  );
  $form['initial_redirect_reset'] = array(
    '#type' => 'checkbox',
    '#title' => t('Reset "initial visit" for previous visitors.'),
    '#description' => t('Reset the timestamp which prevents prior visitors from being redirected again.'),
    '#default_value' => FALSE,
  );
  $form['initial_redirect_ts'] = array(
    '#type' => 'hidden',
    '#title' => t('Timestamp'),
    '#default_value' => variable_get('initial_redirect_ts', time()),
    '#description' => t('Incrementing this value will cause previously redirected visitors to be affected on their next visit. This happens automatically if you check the <em>Reset "initial visit" for previous visitors</em> box above.'),
  );
  return system_settings_form($form);
}

/**
 * Additional validator.
 */
function initial_redirect_settings_validate($form, &$form_state) {
  if ($form_state['values']['initial_redirect_reset']) {
    $form_state['values']['initial_redirect_ts'] = time();
  }
  cache_clear_all();
}