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
    '#weight' => -1,
  );

  $form['basic_settings']['social_stats_start_date'] = array(
    '#title' => t('Start Date'),
    '#type' => 'textfield',
    '#maxlength' => 20,
    '#default_value' => variable_get('social_stats_start_date', 'January 1st, 1970'),
    '#description' => t('The oldest date for which the statistics will be retrieved. Enter any valid !url.',
        array('!url' => l(t('PHP date format'), 'http://www.php.net/manual/en/datetime.formats.php'))),
  );

  $form['configuration'] = array(
    '#type' => 'fieldset',
    '#title' => t('Cron configuration'),
    '#weight' => 0,
  );
  $form['configuration']['social_stats_cron_interval'] = array(
    '#type' => 'select',
    '#title' => t('Cron interval'),
    '#description' => t('Time after which social data will be collected.'),
    '#default_value' => variable_get('social_stats_cron_interval', 60 * 60 * 24),
    '#options' => array(
      60 => t('1 minute'),
      300 => t('5 minutes'),
      3600 => t('1 hour'),
      60 * 60 * 6 => t('6 hours'),
      60 * 60 * 12 => t('12 hours'),
      60 * 60 * 24 => t('1 day'),
      60 * 60 * 24 * 7 => t('1 week'),
      60 * 60 * 24 * 7 * 2 => t('2 weeks'),
      60 * 60 * 24 * 7 * 4 => t('1 month'),
    ),
  );

  $form['configuration']['social_stats_cron_duration'] = array(
    '#type' => 'textfield',
    '#title' => t('Cron duration'),
    '#description' => t('Time (in secs) for which the queue should execute.'),
    '#default_value' => variable_get('social_stats_cron_duration', 300),
    '#size' => 3,
    '#maxlength' => 3,
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
      '#default_value' => variable_get('social_stats_' . $types->type, array(0)),
    );
    $i++;
  }
  return system_settings_form($form);
}
