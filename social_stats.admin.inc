<?php

/**
 * @file
 * Administrative page callbacks for Service Links module.
 */

/**
 * Settings form to select the social media for content types.
 */
function social_stats_content_types_form() {
  $form['basic_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Basic Settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#tree' => FALSE,
  );

  $form['basic_settings']['social_stats_start_date'] = array(
    '#title' => t('Start Date'),
    '#type' => 'textfield',
    '#maxlength' => 20,
    '#default_value' => variable_get('social_stats_start_date', '-1 day'),
    '#description' => t('The oldest date for which the statistics will be retrieved. Enter any valid !url.',
        array('!url' => l(t('PHP date format'), 'http://www.php.net/manual/en/datetime.formats.php'))),
  );

  $node_types = node_type_get_types();
  $i = 0;
  foreach ($node_types as $types) {
    $form['social_stats'][$i] = array(
      '#type' => 'fieldset',
      '#title' => $types->name,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['social_stats'][$i]['social_stats_' . $types->type] = array(
      '#type' => 'checkboxes',
      '#options' => drupal_map_assoc(array(
        t('Facebook'),
        t('Twitter'),
        t('Google Plus'),
        t('LinkedIn'),
      )),
      '#default_value' => variable_get('social_stats_' . $types->type, NULL),
    );
    $i++;
  }
  return system_settings_form($form);
}
