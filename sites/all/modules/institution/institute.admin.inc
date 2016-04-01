<?php

function institute_form($form, &$form_state, $task) {
  $form_state['task'] = $task;
 
//$form['entity'] = array( '#type' => 'value', '#value' => $entity, );

  $form['ins_type'] = array(
    '#type' => 'select',
    '#title' => t('Institute Type'),
    '#options' => array(
        'Select' => t('Select'),
        'Individual' => t('Individual'),
        'Organization' => t('Organization'),
    ),
    '#description' => t('Type of Repository/Institute'), 
    '#default_value' => $task->ins_type,
  );

  $form['ins_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Institute Code'),  
    '#default_value' => $task->ins_code,
  );
  
  
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#required' => TRUE,
    '#size' => 30,
    '#description' => t('Name of the Repository/ Institute'), 
    '#default_value' => $task->name,    
  );
  
  $form['ins_local_lng'] = array(
    '#type' => 'textfield',
    '#title' => t('Ins./Rep. in Local Lang'),
    '#size' => 30,
    '#description' => t('Number of Ins./Rep. available in local language'),
    '#default_value' => $task->ins_local_lng,  
  );
  
  $form['address'] = array(
    '#type' => 'textfield',
    '#title' => t('Address'),
    '#required' => TRUE,  
    '#size' => 30,
    '#description' => t('Address of the Repository/Institute'),
    '#default_value' => $task->address,  
  );
  
  $form['district'] = array(
    '#type' => 'textfield',
    '#title' => t('District'),
    '#required' => TRUE,  
    '#size' => 30,
    '#description' => t('City of the Repository/Institute'),
    '#default_value' => $task->district,  
  );

  $form['state'] = array(
    '#type' => 'select',
    '#title' => t('State'),
    '#required' => TRUE,  
    '#options' => array(
        'Select' => t('Select'),
        'Utter Pradesh' => t('Utter Pradesh'),
        'Delhi' => t('Delhi'),
        'Punjab' => t('Punjab'),
        'Haryana' => t('Haryana'),
        'Shimla' => t('Shimla'),
        'Rajasthan' => t('Rajasthan'),
    ),
    '#description' => t('State of the Repository/Institute'),
    '#default_value' => $task->state,  
  );
    
   $form['pin'] = array(
    '#type' => 'textfield',
    '#title' => t('Pin'),
    '#required' => TRUE,  
    '#size' => 30,
    '#description' => t('Pin code of the Repository/Institute'),
    '#default_value' => $task->pin,   
  );
   
   $form['head_of_inst'] = array(
    '#type' => 'textfield',
    '#title' => t('Head of the Institution'),
    '#size' => 30,
    '#description' => t('Name of the Institution/Repository Head (Secretary/Director/Librarian)'),
    '#default_value' => $task->head_of_inst,   
  );
   
   $form['phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Phone No'),
    '#size' => 30,
    '#description' => t('Phone no of the Institution/Repository'),
    '#default_value' => $task->phone,   
  );
   
   $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail'),   
    '#required' => TRUE, 
    '#size' => 30,   
    '#element_validate' => array('institute_email_element_validate'),   
    '#description' => t('E-mail of the Institution/Repository'),
    '#default_value' => $task->email,   
  );
   
   $form['website'] = array(
    '#type' => 'textfield',
    '#title' => t('Website'),
    '#size' => 30,
    '#description' => t('Website of the Institution/Repository'),
    '#default_value' => $task->website,   
  );
   
   $form['total_manu'] = array(
    '#type' => 'textfield',
    '#title' => t('No of Total Manuscripts'),
    '#size' => 10,
    '#required' => TRUE,  
    '#description' => t('Total no of Manuscripts available'),
    '#default_value' => $task->total_manu,   
  );
   
   $form['paper_manu'] = array(
    '#type' => 'textfield',
    '#title' => t('No of Paper Manuscripts'),
    '#size' => 10,
    '#description' => t('Total no of Paper Manuscripts available'),
    '#default_value' => $task->paper_manu,   
  );
   
   $form['palm_leaf_manu'] = array(
    '#type' => 'textfield',
    '#title' => t('No of Palm Leaf Manuscripts'),
    '#size' => 10,
    '#description' => t('No of Manuscripts available in Leaf material'),
    '#default_value' => $task->palm_leaf_manu,   
  );
   
   $form['other_material_manu'] = array(
    '#type' => 'textfield',
    '#title' => t('No of Mss. In Other Material'),
    '#size' => 10,
    '#description' => t('No of Manuscripts available in other Materials'),
    '#default_value' => $task->other_material_manu,   
  );
   $form['illustrated_manu'] = array(
    '#type' => 'textfield',
    '#title' => t('No of Illustrated Manuscripts'),
    '#size' => 10,
    '#description' => t('No of Illustrated Manuscripts available'),
    '#default_value' => $task->illustrated_manu,   
  );
   $form['catalog_published'] = array(
    '#type' => 'textfield',
    '#title' => t('No of Catalogues Published'),
    '#size' => 10,
    '#description' => t('No of Catalogues Published by Institute/Repository'),
    '#default_value' => $task->catalog_published,   
  );
  $form['catalogue_type'] = array(
    '#type' => 'select',
    '#title' => t('Type of Catalogues'),
    '#required' => TRUE,  
    '#options' => array(
        'N.A.' => t('N.A.'),
        'Alphabatical' => t('Alphabatical'),
        'Card Index' => t('Card Index'),
       ),
     '#multiple' => TRUE, 
    '#description' => t('Type of the Catalogue'),  
    '#default_value' => $task->catalogue_type,  
  );
  
  $form['group1'] = array(
  '#type' => 'fieldset',    
  //'#tree' => TRUE,
  '#collapsible' => FALSE,
  '#collapsed' => FALSE,   
  '#title' => t('No of Manuscripts Catalogued- Category wise'),    
  );
  
  $form['group1']['manu_catalog_cat_wise_A'] = array(
    '#type' => 'textfield',
    '#title' => t('A'),
    '#size' => 5,
    //'#description' => t('No of Catalogues Published by Institute/Repository'),
    '#default_value' => $task->manu_catalog_cat_wise_A,  
  );
  
  $form['group1']['manu_catalog_cat_wise_C'] = array(
    '#type' => 'textfield',
    '#title' => t('C'),    
    '#size' => 5,
    '#default_value' => $task->manu_catalog_cat_wise_C,  
  );
  
  $form['group1']['manu_catalog_cat_wise_D'] = array(
    '#type' => 'textfield',
    '#title' => t('D'),    
    '#size' => 5,
    '#default_value' => $task->manu_catalog_cat_wise_D,  
  );
  $form['group1']['manu_catalog_cat_wise_H'] = array(
    '#type' => 'textfield',
    '#title' => t('H'),    
    '#size' => 5,
    '#default_value' => $task->manu_catalog_cat_wise_H,  
  );
  
  $form['catalogue_status'] = array(
    '#type' => 'select',
    '#title' => t('Status of Catalogue.'),
    '#options' => array(
        'Select' => t('Select'),
        'Computerization' => t('Computerization'),
        'Digitization' => t('Digitization'),
  ),
    '#description' => t('Status of Catalogue'), 
    '#default_value' => $task->catalogue_status,  
  );
  
  $form['detail_rare_manu'] = array(
    '#type' => 'textfield',
    '#title' => t('Detail of Rare Manuscripts'),
    '#size' => 10,
    '#description' => t('Total no of Rare Manuscript available.'),
    '#default_value' => $task->detail_rare_manu,  
  );
  
  $form['chronological_ranf_manu'] = array(
    '#type' => 'textfield',
    '#title' => t('Chronological Rang of the Manuscript.'),
    '#size' => 10,
    '#description' => t('Chronological range available for the Manuscripts'), 
    '#default_value' => $task->chronological_ranf_manu,  
  );
  
  $form['state_preservation'] = array(
    '#type' => 'select',
    '#title' => t('Status of Catalogue.'),
    '#options' => array(
        'Select' => t('Select'),
        'Bad' => t('Bad'),
        'Good' => t('Good'),
  ),
    '#description' => t('State of the Manuscript Preservation'),
    '#default_value' => $task->state_preservation,  
  );
  
   $form['type_of_inst'] = array(
    '#type' => 'select',
    '#title' => t('Status of Catalogue'),
    '#options' => array(
        'Select' => t('Select'),
        'Autonomous' => t('Autonomous'),
        'Manual' => t('Manual'),
  ),
    '#description' => t('Type of the Institution'),
    '#default_value' => $task->type_of_inst,   
  );
   
 $form['status_of_conversation'] = array(
    '#type' => 'textfield',
    '#title' => t('Status of Conversation'),
    '#size' => 30,
    '#description' => t('Showing the Status of the conversation'),
    '#default_value' => $task->status_of_conversation, 
  );
 
 $form['brief_history'] = array(
    '#type' => 'textarea',
    '#title' => t('Brief History'),
    '#size' => 8,
    '#description' => t('If Brief history available about the Repository/Institute'),
    '#default_value' => $task->brief_history, 
  );
 
 $form['date_information_collection'] = array(
    '#type' => 'date_popup',
    '#title' => t('Date of Collection of  Information'),
    '#size' => 8,
    '#description' => t('Information collection date about the Repository/Institute'),
    '#default_value' => $task->date_information_collection,
  );
 
  $form['mrc'] = array(
    '#type' => 'select',
    '#title' => t('MRC'),
    '#options' => array(
        'Select' => t('Select'),
        'MRCcenter1' => t('MRCcenter1'),
        'MRCcenter2' => t('MRCcenter2'),
  ),
    '#description' => t('Selection of MRC under which Repository/Institute will be registered.'),
     '#default_value' => $task->mrc, 
  );
  $pub = '';
  if($task->publish == '1'){
      $pub = TRUE;
  }  else {
      $pub = FALSE;
  }
  
  $form['publish'] = array(
    '#type' => 'checkbox',
    '#title' => t('Published'),
    '#default_value' => $pub,
    //'#options' => $checkbox,  
  );
  
  $form['deleted'] = array(
      '#type' => 'hidden',
      '#value' => $task->deleted,
  );
  
  //field_attach_form('basic', $task, $form, $form_state);

  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions'] = array(
    '#weight' => 100,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Institute'),
    '#submit' => $submit + array('institute_form_submit'),
  );

  // Show Delete button if we edit task.
  $task_id = entity_id('institute' ,$task);
  //if (!empty($task_id) && example_task_access('edit', $task)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('edit_delete_single_entity'),
    );
  //}

  $form['#validate'][] = 'institute_form_validate';

  return $form;
}

function institute_form_validate($form, &$form_state){
    
}


function institute_form_submit($form, &$form_state) {

  $task = $form_state['task'];
  
  entity_form_submit_build_entity('institute', $task, $form, $form_state);
//($entity_type, $entity, $form, &$form_state)
  institute_save($task);
  revision_data_save($task);// Insert and update revision table for institute

  $task_uri = entity_uri('institute', $task);

  $form_state['redirect'] = $task_uri['path'];

  drupal_set_message(t('institute %title saved.', array('%title' => entity_label('institute', $task))));
}


function edit_delete_single_entity($form, &$form_state) {
  $task = $form_state['task'];
  $task_uri = entity_uri('institute', $task);
  $form_state['redirect'] = $task_uri['path'] . '/delete';
}


function ins_delete_form($form, &$form_state, $task) {
  $form_state['task'] = $task;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['task_type_id'] = array('#type' => 'value', '#value' => entity_id('institute' ,$task));
  $task_uri = entity_uri('institute', $task);
  return confirm_form($form,
    t('Are you sure you want to delete institute %institute?', array('%institute' => $task->name)),
    $task_uri['path'],
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

function ins_delete_form_submit($form, &$form_state) {
  $task = $form_state['task'];
  //ins_entity_delete($task);//function in .module
  $del = ins_soft_delete($task);
  
  if($del){
    drupal_set_message(t('Institute %name has been deleted.', array('%name' => $task->name)));
    $form_state['redirect'] = '<front>';
    }else{
    
    form_set_error('', t('Unable to delete it please contact to administrator'));
    }
}




