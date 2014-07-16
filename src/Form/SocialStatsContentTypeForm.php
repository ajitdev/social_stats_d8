<?php

namespace Drupal\social_stats\Form;

use Drupal\Core\Form\FormBase;

class SocialStatsContentTypeForm extends FormBase {
  public function getFormId() {
    return 'social_stats_content_type_form';
  }
  public function buildForm(array $form, array &$form_state) {
    $node_types = node_type_get_types();
    $i = 0;
    // $form['#attached']['library'][] = 'system/drupal.system';
    foreach ($node_types as $types) {
      $form['social_stats'][$i] = array(
        '#type' => 'details',
        '#title' => $types->name,
        '#open' => TRUE,
      );
      $form['social_stats'][$i]['social_stats_' . $types->type] = array(
        '#type' => 'checkboxes',
        '#options' => array(
          0 => t('Facebook'),
          1 => t('Twitter'),
          2 => t('Google Plus'),
          3 => t('LinkedIn'),
        ),
        // '#default_value' => variable_get('social_stats_' . $types->type, array(0)),
      );
      $i++;
    }
    $form['social_stats_submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save Settings')
    );
    return $form;
  }

  public function submitForm(array &$form, array &$form_state) {
    echo "<pre>";
    print_r(node_type_get_types());
    exit;
  }
}
