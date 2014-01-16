<?php

/**
 * Form builder function for module settings.
 */
function initial_redirect_settings() {
  $form['initial_redirect_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirect URL'),
    '#default_value' => variable_get('initial_redirect_url', NULL),
    '#description' => t('URL to redirect initial visitors to.'),
  );
  $form['initial_redirect_reset'] = array(
    '#type' => 'checkbox',
    '#title' => t('Reset "initial visit" for previous visitors.'),
    '#default_value' => FALSE,
  );
  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['advanced']['initial_redirect_json2_uri'] = array(
    '#type' => 'textfield',
    '#title' => t('JSON2 library URI'),
    '#default_value' => variable_get('initial_redirect_json2_uri', INITIAL_REDIRECT_JSTORAGE_URI),
    '#description' => t('URI to include !json2 library from.', array('!json2' => l('JSON2', 'https://github.com/douglascrockford/JSON-js'))),
  );
  $form['advanced']['initial_redirect_jstorage_uri'] = array(
    '#type' => 'textfield',
    '#title' => t('jStorage library URI'),
    '#default_value' => variable_get('initial_redirect_jstorage_uri', INITIAL_REDIRECT_JSTORAGE_URI),
    '#description' => t('URI to include !jstorage library from.', array('!jstorage' => l('jStorage', 'http://jstorage.info'))),
  );
  $form['advanced']['initial_redirect_ts'] = array(
    '#type' => 'textfield',
    '#title' => t('Timestamp'),
    '#default_value' => variable_get('initial_redirect_ts', time()),
    '#description' => t('Incrementing this value will cause previously redirected visitors to be affected on their next visit.'),
  );
  //$form['#validate'][] = 'initial_redirect_settings_validate';
  return system_settings_form($form);
}

/**
 * Additional validator.
 */
function initial_redirect_settings_validate($form, &$form_state) {
  if ($form_state['values']['initial_redirect_reset']) {
    $form_state['values']['initial_redirect_ts'] = time();
    cache_clear_all();
  }
}