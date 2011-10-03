<?php

/**
 * @file
 *   Drush interface to drupal_lookup_path() API function.
 *
 */

/**
 * Implementation of hook_drush_command().
 */
function lookup_path_drush_command() {
  $items = array();
  
  $items['lookup-path'] = array(
    'description' => 'Given an alias, return its Drupal system URL if one exists. Given a Drupal system URL return one of its aliases if such a one exists.',
    'arguments' => array(
      'path' => 'Alias or Drupal system URL',
    ),
    'options' => array(
      'alias' => 'Return an alias for a given Drupal system path (if one exists).',
      'source' => 'Return the Drupal system URL for a path alias (if one exists).',
    ),
    'examples' => array(
      'drush lp --source guides/title/what-does-it-mean-close-home' => 'Returns the Drupal system URL for the node with the path alias "guides/title/what-does-it-mean-close-home"',
      'drush lp --alias node/2' => 'Returns the path alias for the node with the Drupal system URL node/2 (if one exists).',
    ),
    'aliases' => array('lp'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  return $items;
}

/**
 * Drush callback.
 */
function drush_lookup_path($path) {
  $action = NULL;
  if (drush_get_option('source')) {
    $action = 'source';
  }
  else if (drush_get_option('alias')) {
    $action = 'alias';
  }
  else {
    // Shouldn't get here.  The action needs to be set.
  }

  if ($lookup = drupal_lookup_path($action, $path)) {
    drush_print($lookup);
  }
  else {
    drush_print("Path \"$path\" not found\n");
  }
}
