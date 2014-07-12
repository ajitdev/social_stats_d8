<?php

namespace Drupal\social_stats\Form;

use Drupal\Core\Form\FormBase;

class SocialStatsContentTypeForm extends FormBase {
  public function getFormId() {
    return 'social_stats_content_type_form';
  }
  public function buildForm(array $form, array &$form_state) {
    $node_types = array('node', 'page', 'blog');
    $i = 0;
    foreach ($node_types as $types) {
      $form['social_stats'][$i] = array(
        '#type' => 'fieldset',
        '#title' => $types,
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
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
    return $form;
  }

  public function submitForm(array &$form, array &$form_state) {

  }
}
