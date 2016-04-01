<?php


//function institute_view($institute, $view_mode='full') {
//  $entity_type = 'institute';
//  $entity_id = entity_id($entity_type, $institute);
//
//  // Remove previously built content, if exists
//  $institute->content = array();
//  $institute->title = filter_xss($institute->title);
//
//  // Build the fields content
//  field_attach_prepare_view($entity_type, array($entity_id => $institute), $view_mode);
//  entity_prepare_view($entity_type, array($entity_id => $institute));
// 
//  $institute->content += field_attach_view($entity_type, $institute, $view_mode);
// 
//  $institute->content += array(
//    '#theme'     => $entity_type,
//    '#element'   => $institute,
//    '#view_mode' => $view_mode,
//    '#language'  => LANGUAGE_NONE,
//  );
// 
//  return $institute->content;
//}
//
//
//function institution_theme($existing, $type, $theme, $path) {
//  return array(
//    'institute' => array(
//      'variables' => array('element' => null),
//      'template' => 'institute_template'
//    ),
//  );
//}



function ins_view($entity, $view_mode='full') {
  $entity_type = 'institute';
  $entity_id = entity_id($entity_type, $entity);
 
  //
  // Remove previously built content, if exists
  //
  $entity->content = array();
  $entity->title = filter_xss($entity->ins_type);
 
  //
  // Build the fields content
  //
  field_attach_prepare_view($entity_type, array($entity_id => $entity), $view_mode);
  entity_prepare_view($entity_type, array($entity_id => $entity));
 
  $entity->content += field_attach_view($entity_type, $entity, $view_mode);
 
   // Specify the theme to use and set the #element. Note that the key
   // you use to pass the entity object must match the key you set in the
   // variables in my_module_theme(). So in the case below, we use the key
   // named #element because in my_module_theme() we set the following code:
   //
   // array(
   //   'my_entity' => array(
   //     'variables' => array('element' => null),
   //     'template' => 'my_entity'
   //   ),
   // );
   //
  $entity->content += array(
    '#theme'     => $entity_type,
    '#element'   => $entity,
    '#view_mode' => $view_mode,
    '#language'  => LANGUAGE_NONE,
  );
 
  return $entity->content;
}


//function institution_theme($existing, $type, $theme, $path) {
//  return array(
//    'institute' => array(
//      'variables' => array('element' => null),
//      'template' => 'institute_template'
//    ),
//      
//  );
//}

