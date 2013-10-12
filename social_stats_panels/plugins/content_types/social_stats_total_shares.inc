<?php

/**
 * @file
 * Returns a content type with 
 * Facebook total + plus one count + tweets count + linkedin shares number 
 * of facebook shares of the node. Only available on on node view i.e. with
 * required context node being viewed
 */

$plugin = array(
  'title' => t('Total shares across social networks'),
  'content_types' => 'total',
  'single' => TRUE,
  'category' => array('Social Stats'),
  'edit form' => 'social_stats_total_form_edit',
  'render callback' => 'social_stats_total_form_render',
  'required context' => array(new ctools_context_required(t('Node'), 'node')),
);

/**
 * Function to render the share count.
 */
function social_stats_total_form_render($subtype, $conf, $args, &$context) {
  $block = new stdClass();
  $query = db_query('SELECT s.total_virality FROM {social_stats_total} s WHERE s.nid = :current_node_id', array(':current_node_id' => $args[0]));
  foreach($query as $result) {
    if($result->total_virality) {
      $block->content = format_plural($result->total_virality, '1 Share', '@count Shares');
    }
    else {
      $block->content = t('0 Shares');
    }
  }
  return $block;
}

/**
 * Function to render the edit form, if not used doesn't get a form at all.
 */
function social_stats_total_form_edit($form, &$form_state) {
  return $form;
}
