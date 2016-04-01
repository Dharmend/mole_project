<?php
function danland_page_class($sidebar_first, $sidebar_second) {
	if ($sidebar_first && $sidebar_second) {
		$id = 'layout-type-2';	
	}
	else if ($sidebar_first || $sidebar_second) {
		$id = 'layout-type-1';
	}

	if(isset($id)) {
		print ' id="'. $id .'"';
	}
}

function danland_preprocess_html(&$vars) {
  // Add conditional CSS for IE6.
drupal_add_css(path_to_theme() . '/style.ie6.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'IE 6', '!IE' => FALSE), 'preprocess' => FALSE));
}

function danland_preprocess_maintenance_page(&$variables) {
  if (!$variables['db_is_active']) {
    unset($variables['site_name']);
  }
  drupal_add_css(drupal_get_path('theme', 'danland') . '/maintenance.css');
  drupal_add_js(drupal_get_path('theme', 'danland') . '/scripts/jquery.cycle.all.js');
}

if (drupal_is_front_page()) {
  drupal_add_js(drupal_get_path('theme', 'danland') . '/scripts/jquery.cycle.all.js');
}

function danland_form_alter(&$form, &$form_state, $form_id) {
	global $user;
  $role = end($user->roles);
// print $form_id;
	if(($form_id == 'taxonomy_form_term') && ($role == 'MOLE')){
		//echo "<pre>";
		drupal_set_title('Add Type of Card');
  $form['description']['#access'] = FALSE;	}

    if(($form_id == 'agency_node_form')){
    //echo "<pre>";
    drupal_set_title('Add Registration Agency');
 }


}

function danland_preprocess_page(&$vars) {
  if (drupal_is_front_page()) {
    if (user_is_logged_in()) {
      drupal_goto('user');
    }
  }
  /*if (isset($vars['node']->type)) { 
  $vars['theme_hook_suggestions'][] = 'page__' . $vars['node']->type;
  } */
}
