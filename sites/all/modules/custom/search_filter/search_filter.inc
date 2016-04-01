<?php


function update_relationship($form,&$form_state){
    
  if($_SESSION['rural_urban_value'] != ''){
      $edit_sch = 'secc_'.$_SESSION['rural_urban_value'];
  }
  $data = labour_load($edit_sch,arg(1));
  $form['read-only'] = array(
    '#type' => 'fieldset',
    '#title' => 'Indivdual detail as per SECC record',  
    '#prefix' => '<div class="read-only-fields">',
   );
  $form['read-only']['tin_npr'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['tin_npr'],  
    '#attributes' => array('readonly' => 'readonly'),  
    '#title' => t('AHL TIN(SECC)'),
    '#size' => 30,
    );
  $form['read-only']['ahl_tin'] = array(
    '#type' => 'hidden',
    '#default_value' => $data['ahl_tin'],  
    //'#attributes' => array('readonly' => 'readonly'),  
    //'#title' => t('AHL TIN(SECC)'),
    '#size' => 30,
    );
  $form['read-only']['update_schema'] = array(
    '#type' => 'hidden',
    '#default_value' => $edit_sch,  
    //'#attributes' => array('readonly' => 'readonly'),  
    //'#title' => t('AHL TIN(SECC)'),
    '#size' => 30,
    );
    
  $form['read-only']['name'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['name'],  
    '#attributes' => array('readonly' => 'readonly'),  
    '#title' => t('Name'),
    //'#element_validate' => array('custom_valdiation_name'),
    '#size' => 30,
    );
  
  $form['read-only']['name_sl'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['name_sl'],  
    '#attributes' => array('readonly' => 'readonly'),  
    '#title' => t('Name (Regional Lang)'),
    '#size' => 30,
    );
  
  $form['read-only']['dob'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['dob'],  
    '#attributes' => array('readonly' => 'readonly'),  
    '#title' => t('DOB'),
    '#size' => 10,
    );
  $form['read-only']['age'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['age'],  
    '#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Age'),  
    '#size' => 5,
    );
  if($data['hof'] == 1){
    $op = 'Yes';
  }else{
        $op = 'No';

  }
  $options = array(1 => t('Yes'),0 => t('No'));
  $form['read-only']['hof'] = array(
    '#type' => 'textfield',
    '#attributes' => array('readonly' => 'readonly'),
   //    '#options' => $options, 
    '#default_value' => $op, 
    '#title' => t('HoF'),  
    '#size' => 5,
    );
  
  $form['read-only']['genderid'] = array(
    '#type' => 'textfield',
    '#default_value' => get_gender($data['genderid']),  
    '#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Gender  ID'),  
    '#size' => 20,
    );
  
  $form['read-only']['mstatusid'] = array(
    '#type' => 'textfield',
    '#default_value' => get_marital_status($data['mstatusid']),  
    '#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Marital Status'),  
    '#size' => 15,
    );
  
  $form['read-only']['fathername'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['fathername'],  
    '#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Father Name'),  
    '#size' => 30,
    );
  $form['read-only']['mothername'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['mothername'],  
    '#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Mother Name'),  
    '#size' => 30,
    );
  $form['read-only']['occupation'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['occupation'],  
    '#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Occupation'),  
    '#size' => 30,
    );
  
  $form['read-only']['educode'] = array(
    '#type' => 'textfield',
    '#default_value' => get_education($data['educode']),  
    '#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Education Code'),  
    '#size' => 30,
    );
   $form['read-only']['education_other'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['education_other'],  
    '#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Education Other'),
    '#suffix' => '</div>',   
    '#size' => 30,
    );
	   // $form['markup_data'] = array(
	   //             '#type' => 'markup',
	   //             '#markup' => ('Click Here To Edit Above Field'),
	   //              '#prefix' => '<div class="editseccdata"><span>',
	   //               '#suffix' => '</span></div>',  
	   //             );
   // echo "<pre>";
   // print_r($data);


 $form['edit-detail'] = array(
    '#type' => 'fieldset',
    '#title' => 'Edit Detail',  
    '#prefix' => '<div class="read-only-fields">',
   );

$form['edit-detail']['correction_name'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['name'],  
    //'#attributes' => array('readonly' => 'readonly'),  
    '#title' => t('Name'),
    '#required' => TRUE,
    //'#element_validate' => array('custom_valdiation_name'),
    '#size' => 30,
    );


   $active = array(1 => t('Yes'), 0 => t('No'));
   $form['edit-detail']['correction_hof'] = array(
    '#type' => 'select',
    '#title' => t('HOF'),
    '#options' => $active,
    '#default_value' => $data['hof'],
    '#required' => TRUE,

  //  '#size' => 30,
    
  );
   
   $form['edit-detail']['correction_dob'] = array(
    '#type' => 'date_popup',
    '#default_value' => $data['dob'],
      '#date_format' => 'Y-m-d',  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('DOB'),  
    '#size' => 30,
      '#date_year_range' => '-90:+3',
    );
   
$marital_arr = array(0=>'Select',1 => 'Never married',2 => 'Currently married',3 => 'Widowed', 4 => 'Separated',5 => 'Divorced');
   
   $form['edit-detail']['correction_marital_status'] = array(
    '#type' => 'select',
    '#options' => $marital_arr,   
    '#default_value' => $data['mstatusid'],

    '#title' => t('Marital Status'),  
    //'#size' => 30,
    );
   
   $education_array = array(0 => 'Select',1 => 'Illiterate',2 => 'Literate but below primary',3 => 'Primary', 4 => 'Middle',5 => 'Secondary',6 => 'Higher Secondary',7 => 'Graduate or higher',8 => 'Other(specify)');
   $form['edit-detail']['correction_eductaion'] = array(
    '#type' => 'select',
    '#title' => t('Education'),  
    '#options' => $education_array,
     '#default_value' => $data['educode'],  

    //'#size' => 30,
    );

   $form['edit-detail']['correction_fathername'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['fathername'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Father Name'),  
        '#required' => TRUE,

    '#size' => 30,
    );

   $form['edit-detail']['correction_mothername'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['mothername'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Mother Name'),  
    '#required' => TRUE,

    '#size' => 30,
    );

    $form['edit-detail']['correction_occupation'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['Occupation'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Occupation'),  
    '#size' => 30,
  //  '#suffix' => '</div>',
    );
  
   /////////////////////////////////////////////
    $form['add-detail'] = array(
    '#type' => 'fieldset',
    '#title' => 'Add Detail',  
    '#prefix' => '<div class="read-only-fields">',
   );



   $form['add-detail']['aadhaar'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['aadhaar'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Aadhaar Number'),
    '#prefix' => '<div id="aadhar_field">', 
    '#suffix' => '</div>',   
 
    '#size' => 30,
    );
   $form['add-detail']['e_id'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['e_id'],
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('EID (if Aadhar card is not available)'),  
    '#prefix' => '<div id="eid_field">', 
    '#suffix' => '</div>',
    '#size' => 30,
    );
   
   $form['add-detail']['bank_account_no'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['bank_account_no'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Bank Account No.'), 
        '#required' => TRUE,
 
    '#size' => 30,
    );
   
   $form['add-detail']['bank_name'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['bank_name'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Bank Name'),  
        '#required' => TRUE,

    '#size' => 30,
    );
   
   $form['add-detail']['bank_branch'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['bank_branch'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Bank Branch'),  
    '#required' => TRUE,

    '#size' => 30,
    );
   $primary_occupation = array(0 => 'Select',1 => 'Farmer',2 => 'Fisherman',3 => 'Own business',4 => 'Govt job','5' => 'Others');
   $form['add-detail']['primary_occupation_code'] = array(
    '#type' => 'select',
    '#default_value' => $data['primary_occupation_code'],
    '#options' => $primary_occupation,   
    '#title' => t('Primary Occupation'),
        '#required' => TRUE,
  
    //'#size' => 30,
    );
   $secondary_occupation = array(0 => 'Select',1 => 'Tailor',2 => 'Milk vendor',3 => 'Money Lander',4 => 'Others');
   $form['add-detail']['secondary_occupation_code'] = array(
    '#type' => 'select',
    '#default_value' => $data['secondary_occupation_code'],
    '#options' => $secondary_occupation,  
    '#title' => t('Secondary Occupation'),
    //'#suffix' => '</div>',   
    //'#size' => 30,
    );

   $form['permanent-address'] = array(
    '#type' => 'fieldset',
    '#title' => 'Permanent Address',  
    '#prefix' => '<div class="permanent-address-fields">',
   );
   $form['permanent-address']['p_address1'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['p_address1'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Permanent Address'),
        '#required' => TRUE,
  
    '#size' => 30,
    );
    
   $form['permanent-address']['p_address2'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['p_address2'],  

    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => '&nbsp;',//t('Permanent Address 2'),  
    '#size' => 30,
    );
 
 // echo "<pre>";
 // print_r($data);
 $p_state =  $data['p_state'];
   $state_list_permanent = _get_location('state');
    // $state_list = _get_location('state');
   if(!empty($p_state)){    
    $state_selected_permanent = isset($form_state['values']['state_permanent']) ? $form_state['values']['state_permanent'] : $p_state;
   }else{
    $state_selected_permanent = isset($form_state['values']['state_permanent']) ? $form_state['values']['state_permanent'] : key($state_list_permanent);
}
    //$state_val = _drupal_session_read('state_value');
    
    $form['permanent-address']['state_permanent'] = array(
        '#title' => 'State',
        '#type' => 'select',
        '#options' => $state_list_permanent,
        '#default_value' => $state_selected_permanent,
        '#required' => TRUE,
        '#ajax' => array(
            'callback' => 'ajax_callback_state_permanent',
            'wrapper' => 'wrapper_state_permanent',
            
        ),
        
    );

     
$district_list_permanent = _get_location('district',$state_selected_permanent);
    
 $p_district =  $data['p_district'];
if(!empty($p_district)){
$district_selected_permanent = isset($form_state['values']['district_permanent']) ? $form_state['values']['district_permanent'] : $p_district;
}else{
    $district_selected_permanent = isset($form_state['values']['district_permanent']) ? $form_state['values']['district_permanent'] : key($district_list_permanent);
}
  //$district_list = _get_location('district',$state_selected);
    
    $form['permanent-address']['district_permanent'] = array(
        '#title' => 'District',
        '#type' => 'select',
        '#options' => $district_list_permanent,
        '#default_value' => $district_selected_permanent,
        '#required' => TRUE,
        '#prefix' => '<div id="wrapper_state_permanent">',
        '#suffix' => '</div>',
        '#ajax' => array(
            'callback' => 'ajax_callback_district_permanent',
            'wrapper' => 'wrapper_tehsil_permanent',
            
        ),
        
    );

   
 $tehsil_list_permanent = _get_location('tehsil',$state_selected_permanent,$district_selected_permanent);
   
 $p_tehsil =  $data['p_tehsil'];

    if(!empty($p_tehsil)){
 $tehsil_selected_permanent = isset($form_state['values']['tehsil_permanent']) ? $form_state['values']['tehsil_permanent'] : $p_tehsil; 
    }else{
    //$tehsil_list = _get_location('tehsil',$state_selected,$district_selected);
    $tehsil_selected_permanent = isset($form_state['values']['tehsil_permanent']) ? $form_state['values']['tehsil_permanent'] : key($tehsil_list_permanent); 
}
    $form['permanent-address']['tehsil_permanent'] = array(
        '#title' => 'Tehsil',
        '#type' => 'select',
        '#options' => $tehsil_list_permanent,
        '#default_value' => $tehsil_selected_permanent,
         '#required' => TRUE,
        '#prefix' => '<div id="wrapper_tehsil_permanent">',
        '#suffix' => '</div>',
        '#ajax' => array(
            'callback' => 'ajax_callback_tehsil_permanent',
            'wrapper' => 'wrapper_village_permanent',
            
        )
    );
    
    $village_list_permanent = _get_location('village',$state_selected_permanent,$district_selected_permanent,$tehsil_selected_permanent);

    $p_villagetown = $data['p_villagetown'];
    if(!empty($p_villagetown)){
$village_selected_permanent = isset($form_state['values']['village_permanent']) ? $form_state['values']['village_permanent'] : $p_villagetown;
    }else{
      $village_selected_permanent = isset($form_state['values']['village_permanent']) ? $form_state['values']['village_permanent'] : key($village_list_permanent);  
    }

    //$village_list = _get_location('village',$state_selected,$district_selected,$tehsil_selected);
   // $village_selected_permanent = isset($form_state['values']['village_permanent']) ? $form_state['values']['village_permanent'] : key($village_list_permanent);
    $form['permanent-address']['village_permanent'] = array(
        '#title' => 'Village/Town',
        '#type' => 'select',
        '#options' => $village_list_permanent,
        '#default_value' => $village_selected_permanent,
        '#required' => TRUE,
        '#prefix' => '<div id="wrapper_village_permanent">',
        '#suffix' => '</div>',
//        '#ajax' => array(
//            'callback' => 'ajax_callback_state',
//            'wrapper' = > 'wrapper_state',
//            
//        )
    );
	
   $form['permanent-address']['p_pincode'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['p_pincode'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('PIN Code'),
    '#suffix' => '</div>',   
    '#size' => 30,
    );
   
    $form['current-address'] = array(
    '#type' => 'fieldset',
    '#title' => 'Current Address',  
    '#prefix' => '<div class="current-address-fields">',
   );

 $form['current-address']['sameasperm'] = array(
  '#type' => 'checkbox',
  //'#options' => drupal_map_assoc(array(t('If current address is same as permanent address'))),
      '#title' => t('If current address is same as permanent address'), 

    );


   $form['current-address']['c_address1'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['c_address1'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Current Address'), 
  //  '#required' => TRUE,
 
    '#size' => 30,
    );
    
   $form['current-address']['c_address2'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['c_address2'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => '&nbsp;',//t('Current Address 2'),  
    '#size' => 30,
    );
    $state_list_p = _get_location('state');
     

   // $state_list = _get_location('state');
    $c_state = $data['c_state'];
    if(!empty($c_state)){
          $state_selected_p = isset($form_state['values']['state_p']) ? $form_state['values']['state_p'] : $c_state;

      }else{
  $state_selected_p = isset($form_state['values']['state_p']) ? $form_state['values']['state_p'] : key($state_list_p);
}
    //$state_val = _drupal_session_read('state_value');
    
    $form['current-address']['state_p'] = array(
        '#title' => 'State',
        '#type' => 'select',
        '#options' => $state_list_p,
        '#default_value' => $state_selected_p,
        '#prefix' => '<div id="wrapper_stated_p">',
        '#suffix' => '</div>',
       // '#required' => TRUE,
        '#ajax' => array(
            'callback' => 'ajax_callback_state_p',
            'wrapper' => 'wrapper_state_p',
            
        ),
        
    );

     
        $district_list_p = _get_location('district',$state_selected_p);
    
$c_district = $data['c_district'];
if(!empty($c_district)){
    $district_selected_p = isset($form_state['values']['district_p']) ? $form_state['values']['district_p'] : $c_district;

}else{
        $district_selected_p = isset($form_state['values']['district_p']) ? $form_state['values']['district_p'] : key($district_list_p);

}
  //  $district_list = _get_location('district',$state_selected);
    $form['current-address']['district_p'] = array(
        '#title' => 'District',
        '#type' => 'select',
        '#options' => $district_list_p,
        '#default_value' => $district_selected_p,
       // '#required' => TRUE,
        '#prefix' => '<div id="wrapper_state_p">',
        '#suffix' => '</div>',
        '#ajax' => array(
            'callback' => 'ajax_callback_district_p',
            'wrapper' => 'wrapper_tehsil_p',
            
        ),
        
    );

   
    $tehsil_list_p = _get_location('tehsil',$state_selected_p,$district_selected_p);
   

    $c_tehsil = $data['c_tehsil'];
if(!empty($c_tehsil)){
    $tehsil_selected_p = isset($form_state['values']['tehsil_p']) ? $form_state['values']['tehsil_p'] : $c_tehsil; 

}else{
     $tehsil_selected_p = isset($form_state['values']['tehsil_p']) ? $form_state['values']['tehsil_p'] : key($tehsil_list_p); 
   
}
  //  $tehsil_list = _get_location('tehsil',$state_selected,$district_selected);
    $form['current-address']['tehsil_p'] = array(
        '#title' => 'Tehsil',
        '#type' => 'select',
        '#options' => $tehsil_list_p,
        '#default_value' => $tehsil_selected_p,
       //  '#required' => TRUE,
        '#prefix' => '<div id="wrapper_tehsil_p">',
        '#suffix' => '</div>',
        '#ajax' => array(
            'callback' => 'ajax_callback_tehsil_p',
            'wrapper' => 'wrapper_village_p',
            
        )
    );
    
    $village_list_p = _get_location('village',$state_selected_p,$district_selected_p,$tehsil_selected_p);
    
    $p_villagetown = $data['c_villagetown'];
    if(!empty($p_villagetown)){
    $village_selected_p = isset($form_state['values']['village_p']) ? $form_state['values']['village_p'] : $p_villagetown;

    }else{
          $village_selected_p = isset($form_state['values']['village_p']) ? $form_state['values']['village_p'] : key($village_list_p);
  
    }
    //$village_list = _get_location('village',$state_selected,$district_selected,$tehsil_selected);
    $form['current-address']['village_p'] = array(
        '#title' => 'Village/Town',
        '#type' => 'select',
        '#options' => $village_list_p,
        '#default_value' => $village_selected_p,
       // '#required' => TRUE,
        '#prefix' => '<div id="wrapper_village_p">',
        '#suffix' => '</div>',
//        '#ajax' => array(
//            'callback' => 'ajax_callback_state',
//            'wrapper' = > 'wrapper_state',
//            
//        )
    );

   $form['current-address']['c_pincode'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['c_pincode'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('PIN Code'),
    '#suffix' => '</div>',   
    '#size' => 30,
    );
 
 
  $form['deleted'] = array(
      '#type' => 'hidden',
      '#value' => 0,
  );
  
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 100,
  );

//  $form['actions']['delete'] = array(
//      '#type' => 'submit',
//      '#value' => t('Delete'),
//      '#weight' => 110,
//      '#submit' => array('delete_single_labour'),
//  );

  return $form;
}





function update_relationship_submit($form, &$form_state){
    // echo "<pre>";
    // print_r($form_state['values']);
    // die('ssss');
  
  if($form_state['values']['sameasperm']==1){

    $c_add1 = $form_state['values']['p_address1'];
    $c_add2 = $form_state['values']['p_address2'];
    $c_state = $form_state['values']['state_permanent'];
    $c_district = $form_state['values']['district_permanent'];
    $c_tehsil = $form_state['values']['tehsil_permanent'];
    $c_village = $form_state['values']['village_permanent'];
    $c_pin = $form_state['values']['p_pincode'];
  }else{
    $c_add1 = $form_state['values']['c_address1'];
    $c_add2 = $form_state['values']['c_address2'];
    $c_state = $form_state['values']['state_p'];
    $c_district = $form_state['values']['district_p'];
    $c_tehsil = $form_state['values']['tehsil_p'];
    $c_village = $form_state['values']['village_p'];
    $c_pin = $form_state['values']['c_pincode'];
  }

$r_u = $_SESSION['rural_urban_value'];
 $st_code = $_SESSION['state_value'];
$query = db_select('secc_'.$r_u.'.individual_'.$st_code,'secc')      
         ->fields('secc')
         ->condition('secc.ahl_tin',arg(1),'=')
         ->execute()->fetchAssoc();



          $result = db_insert('online_reg_'.$r_u.'.individual_'.$st_code)
                  ->fields(array(
                      'house_hold_id'  => $query['house_hold_id'],
                      'tin_npr'   => $query['tin_npr'],     
                      'statecode' => $query['statecode'],  
                        'districtcode'  => $query['districtcode'],     
                        'tehsilcode'  => $query['tehsilcode'],    
                        'towncode'    => $query['towncode'],    
                        'wardid'    => $query['wardid'],  
                        'blockno'  => $query['blockno'],       
                        'ahlblockno'  => $query['ahlblockno'],    
                        'ahlsubblockno'  => $query['ahlsubblockno'],     
                        'slnohhd'       => $query['slnohhd'],  
                        'slnomember'    => $query['slnomember'],  
                        'ahlslnohhd'     => $query['ahlslnohhd'], 
                        'ahltypeofeb'   => $query['ahltypeofeb'],      
                        'typeofhhd'     => $query['typeofhhd'], 
                        'livinginshelter'  => $query['livinginshelter'],      
                        'name'       => $query['name'], 
                        'name_sl'     => $query['name_sl'],    
                        'relation'     => $query['relation'],   
                        'genderid'    => $query['genderid'],     
                        'dob'        => $query['dob'], 
                        'mstatusid'    => $query['mstatusid'],    
                        'fathername'   => $query['fathername'],   
                        'mothername'   => $query['mothername'],   
                        'occupation'     => $query['occupation'], 
                        'educode'        => $query['educode'], 
                        'education_other'    => $query['education_other'],     
                        'incomesource_urban'   => $query['incomesource_urban'],  
                        'wages_urban'         => $query['wages_urban'], 
                        'disabilitycode'     => $query['disabilitycode'], 
                        'caste_group'        => $query['caste_group'], 
                        'hhd_housingcodes'  => $query['hhd_housingcodes'],      
                        'hhd_assetcodes'     => $query['hhd_assetcodes'], 
                        'hhd_sectwocodes'   => $query['hhd_sectwocodes'],      
                        'hhd_landownedcodes'  => $query['hhd_landownedcodes'],     
                        'totalirrigated'      => $query['totalirrigated'], 
                        'totalunirrigated'    => $query['totalunirrigated'],    
                        'otherirrigated'     => $query['otherirrigated'], 
                        'hhd_otherassetscodes'  => $query['hhd_otherassetscodes'],      
                        'hhd_employmentcodes'    => $query['hhd_employmentcodes'],   
                        'ahl_tin'        => $query['ahl_tin'], 
                        'member_status'       => $query['member_status'], 
                        'age'        => $query['age'], 
                        'yob'         => $query['yob'], 
                        'hof'        => $query['hof'], 
                        'lessthan_10000'   => $query['lessthan_10000'],    
                        'landlessthan_4acres'  => $query['landlessthan_4acres'],        
                        'house_based'         => $query['house_based'], 
                        'beggars_dw_sv_hbw_adwi_wages'  => $query['beggars_dw_sv_hbw_adwi_wages'],    
                        'construction_pl_sw_tw_sw'     => $query['construction_pl_sw_tw_sw'],    
                        'aadhaar' => $form_state['values']['aadhaar'],
                        'e_id' => $form_state['values']['e_id'],
                        'bank_account_no' => $form_state['values']['bank_account_no'],
                        'bank_name' => $form_state['values']['bank_name'],
                        'bank_branch' => $form_state['values']['bank_branch'],
                        'primary_occupation_code' => $form_state['values']['primary_occupation_code'],
                        'secondary_occupation_code' => $form_state['values']['secondary_occupation_code'],
                        'p_address1' => $form_state['values']['p_address1'],
                        'p_address2' => $form_state['values']['p_address2'],
                        'p_villagetown' => $form_state['values']['village_permanent'],
                        'p_tehsil' => $form_state['values']['tehsil_permanent'],
                        'p_district' => $form_state['values']['district_permanent'],
                        'p_state' => $form_state['values']['state_permanent'],
                        'p_pincode' => $form_state['values']['p_pincode'],
                        'c_address1' => $c_add1,
                        'c_address2' => $c_add2,
                        'c_villagetown' => $c_village,
                        'c_tehsil' => $c_tehsil,
                        'c_district' => $c_district,
                        'c_state' => $c_state,
                        'c_pincode' => $c_pin,        
                        'correction_name' => $form_state['values']['correction_name'],
                        'correction_hof' => $form_state['values']['correction_hof'],
                        'correction_dob' => $form_state['values']['correction_dob'],
                        'correction_marital_status' => $form_state['values']['correction_marital_status'],
                        'correction_eductaion' => $form_state['values']['correction_eductaion'],
                        'correction_fathername' => $form_state['values']['correction_fathername'],
                        'correction_mothername' => $form_state['values']['correction_mothername'],
                        'correction_occupation' => $form_state['values']['correction_occupation'],
                  ))
                ->execute();

    $slip_arg =$query['ahl_tin'];
   // $form_state['redirect'] = 'uw/'.$slip_arg.'/self_declation_form';
    $form_state['redirect'] = 'family/'.$query['house_hold_id'].'/uw-listing';
    	

                       
}

function update_relationship_validate($form, &$form_state){
    $p_pincode = $form_state['values']['p_pincode'];
    $c_pincode = $form_state['values']['c_pincode'];
    $aadhaar_no = $form_state['values']['aadhaar'];
    $eid_no = $form_state['values']['e_id'];

    
    if(strlen($p_pincode) >6){
        form_set_error('p_pincode',t('Pincode should be 6 Digit only'));
    }
    
    if(strlen($c_pincode) >6){
        form_set_error('c_pincode',t('Pincode should be 6 Digit only'));
    }

  custom_valdiation_name($form_state['values']['correction_name'],'Name');  
  custom_valdiation_name($form_state['values']['correction_fathername'],'Father Name'); 
  custom_valdiation_name($form_state['values']['correction_mothername'],'Mother Name'); 
  custom_valdiation_aadhaar($form_state['values']['aadhaar']);
  custom_valdiation_bank_name($form_state['values']['bank_name'] ,'Bank Name');
  custom_valdiation_bank_name($form_state['values']['bank_branch'], 'Bank Branch');  
  custom_valdiation_address($form_state['values']['p_address1']);
  custom_valdiation_address($form_state['values']['p_address2']);
  custom_valdiation_address($form_state['values']['c_address1']);
  custom_valdiation_address($form_state['values']['c_address2']);
  custom_valdiation_eid($eid_no);
  
  custom_valdiation_pincode();
  
}

function self_declation_form($form, $form_id, $form_state){
    // echo "<pre>";
    // print_r($_SESSION);
       $state = $_SESSION['state_value_ack'];

       $options = array(
  'target_id' => 'startdiv',
  'button_id' => 'my_print_button',
  'value' => t('Print Declaration'),
  'type' => 'link',
  'custom_css' => path_to_theme().'/css/style.css',
  );

  $print = area_print_form($options);

    if($_SESSION['rural_urban_value_ack'] != ''){
     $edit_sch = 'online_reg_'.$_SESSION['rural_urban_value_ack'];
  }
    $form = array();
    //$data = labour_load($edit_sch,arg(1));
     $qry = db_select($edit_sch.'.individual_'.$state,'fm')
        ->fields('fm',array('house_hold_id'))
        ->condition('fm.ahl_tin',arg(1))
        ->execute()->fetchAssoc();

       $house_hold =   $qry['house_hold_id'];

      $query = db_select($edit_sch.'.individual_'.$state,'ah')
        ->fields('ah',array('ahl_tin'))
        ->condition('house_hold_id',$house_hold)
        ->execute();
        $i=0;
        while ( $result = $query->fetchAssoc()) {
            $ahl = $result['ahl_tin'];
           // print_r($result);

 $dbq = db_select($edit_sch.'.individual_'.$state,'onl')
         ->fields('onl')
         ->condition('onl.ahl_tin',$ahl,'=')
         ->execute();
         //echo "<pre>";
  while ($data = $dbq->fetchAssoc()) {
    // echo "<pre>";
    // print_r($data);
 
      $photo = $data['photograph'];

     $form[$i]['div'] = array(
         '#type' => 'item',
        '#prefix' => '<div class="startdiv">',

    );
      $form[$i]['date'] = array(
         '#type' => 'item',
        '#markup' => '<strong>'.date('d/m/Y  H:i:s').' </strong>',    
        '#prefix' => '<div class="header_right">',

    );
       $form[$i]['refno'] = array(
         '#type' => 'item',
        '#markup' => '<strong>  Ref.No- :</strong> '.$data['ahl_tin'].'',    
        '#suffix' => '</div>',

    );

        $form[$i]['titlese'] = array(
         '#type' => 'item',
        '#markup' => '<strong>Self Declartion Form</strong>',  
             '#prefix' => '<div class="titlese">',
  
        '#suffix' => '</div>',

    );
   $form[$i]['full_name'] = array(
         '#type' => 'item',
        '#markup' => '<strong>  Name :</strong> '.$data['name'].'',    
        '#prefix' => '<div class="leftside">',

    );
    $form[$i]['fat_name'] = array(
        '#type' => 'item',
        '#markup' => '<strong> Father Name :</strong> '.$data['fathername'].'',    
   
    );

     $form[$i]['mother_name'] = array(
        '#type' => 'item',
        '#markup' => '<strong> Mother Name :</strong> '.$data['mothername'].'', 
    
    );

$form[$i]['uwdob'] = array(
    '#type' => 'item',
    '#markup' => '<strong>Date Of Birth :</strong> '.$data['dob'].'', 
  
    );

// if($data['genderid'] =='1'){
//     $gen = "Male";
// }else{
//     $gen = "Female";
// }
$gen = ($data['genderid'] =='1')? 'male': 'female';
$form[$i]['uwgender'] = array(
    '#type' => 'item',
    '#markup' => '<strong>Gender :</strong> '.$gen.'',     
    '#suffix' => '</div>',   

    );
$phto = 'data:image/gif;base64,'.$data['photograph'];
// $form['markup_data'] = array(
//                '#type' => 'markup',
//                '#markup' => '<img src="'.$phto.'">',
//                 '#prefix' => '<div class="rightimg"><span>',
//                  '#suffix' => '</span></div>',  
//                );

$form[$i]['permanent-address'] = array(
    '#type' => 'fieldset',
    '#title' => 'Permanent Address',  
    '#prefix' => '<div class="permanent-address-fields">',
   );
   $form[$i]['permanent-address']['p_address1'] = array(
     '#type' => 'item',
    '#markup' => '<strong>Address 1 :</strong> '.$data['p_address1'].'', 
    
    );
    
   $form[$i]['permanent-address']['p_address2'] = array(
     '#type' => 'item',
    '#markup' => '<strong>Address 2 :</strong> '.$data['p_address2'].'',
   
    );
 
     $village_list_p = _get_location('village',$data['p_state'],$data['p_district'],$data['p_tehsil']);
     $pvill = $village_list_p[$data['p_villagetown']];


 $form[$i]['permanent-address']['vill_town'] = array(
     '#type' => 'item',
    '#markup' => '<strong>Village :</strong> '.$pvill.'',
    
    );
 $district_list_ackc = _get_location('district',$data['p_state']);
$pdistrict_d = $district_list_ackc[$data['p_district']];
$form[$i]['permanent-address']['district'] = array(
     '#type' => 'item',
    '#markup' => '<strong>District :</strong> '.$pdistrict_d.'',
    
    );
$state_listack = _get_location('state');
  $pstate_d = $state_listack[$data['p_state']];
 $form[$i]['permanent-address']['state'] = array(
     '#type' => 'item',
    '#markup' => '<strong>State :</strong> '.$pstate_d.'',
    
    );
 

   $form[$i]['permanent-address']['p_pincode'] = array(
     '#type' => 'item',
    '#markup' => '<strong>PIN Code :</strong> '.$data['p_pincode'].'',
    
     '#suffix' => '</div>',   
    );
   
    $form[$i]['current-address'] = array(
    '#type' => 'fieldset',
    '#title' => 'Current Address',  
    '#prefix' => '<div class="current-address-fields">',
   );
   $form[$i]['current-address']['c_address1'] = array(
     '#type' => 'item',
    '#markup' => '<strong>Address 1 :</strong> '.$data['c_address1'].'',
  
    );
    
   $form[$i]['current-address']['c_address2'] = array(
    '#type' => 'item',
    '#markup' => '<strong>Address 2 :</strong> '.$data['c_address2'].'',
    
    );

   $village_list_c = _get_location('village',$data['c_state'],$data['c_district'],$data['c_tehsil']);
     $cvill = $village_list_c[$data['c_villagetown']];

   $form[$i]['current-address']['cvill_town'] = array(
     '#type' => 'item',
    '#markup' => '<strong>Village :</strong> '.$cvill.'',
    
    );
 $district_list_ackc = _get_location('district',$data['c_state']);
$cdistrict_d = $district_list_ackc[$data['c_district']];
$form[$i]['current-address']['cdistrict'] = array(
     '#type' => 'item',
    '#markup' => '<strong>District :</strong> '.$cdistrict_d.'',
   
    );
$state_listackc = _get_location('state');
  $cstate_d = $state_listackc[$data['c_state']];
 $form[$i]['current-address']['cstate'] = array(
    '#type' => 'item',
    '#markup' => '<strong>State :</strong> '.$cstate_d.'',
    
    );
 
   $form[$i]['current-address']['c_pincode'] = array(
    '#type' => 'item',
    '#markup' => '<strong>PIN Code :</strong> '.$data['c_pincode'].'',   
     '#suffix' => '</div>',   
    );

   $form[$i]['uwsection'] = array(
    '#type' => 'item',
    '#markup' => t('1. I wish to apply for registration as unorganized worker per the provisions of Section 10(3) of the Unorganized Workers’ Social Security Act 2008 and issuance of Mahatma Phule National Social Security (MPNSS) Card. <strong>[YES]</strong>'),
    
    );

    $form[$i]['further_declaretion'] = array(
    '#type' => 'item',
    '#markup' => t('2.  Further, I hereby declare that-<br>
                        <span style="margin: 0px 0px 0px 17px;"> a) I am an Indian Citizen <strong>[YES]</strong></span> <br>
                        <span style="margin: 0px 0px 0px 17px;"> b) I am an unorganized worker <strong>[YES]</strong></span><br>
                        <span style="margin: 0px 0px 0px 17px;"> c) I am NOT a member of Employee Provident Fund Organization (EPFO) or Employee State Insurance Corporation (ESIC) <strong>[YES]</strong></span><br>
                        <span style="margin: 0px 0px 0px 17px;"> d) my average income per month is less than Rs. 10,000 per month and <strong>[YES]</strong></span><br>
                       <span style="margin: 0px 0px 0px 17px;">  e) I am above 18 years of age. <strong>[YES]</strong></span>
'),
    );


       $form[$i]['further_declare'] = array(
    '#type' => 'item',
    '#markup' => t('3.  I hereby authorize the appropriate Authorities to utilize and store my Aadhar details, including my biometric information and photograph in the MPNSS Card. <strong>[YES]</strong>'),
    
    );
      $form[$i]['authorize_ministry'] = array(
    '#type' => 'item',
    '#markup' => t('4. I also authorize Ministry of Labour and employment to share this information with the Ministries / Departments operating Social Security Schemes <strong>[YES]</strong>'),
    
    );
        $form[$i]['furnishing'] = array(
    '#type' => 'item',
    '#markup' => t('5.  I am not having/furnishing my Aadhar number  <strong>[YES]</strong>'),
    
    );

         $form[$i]['personal_detail'] = array(
    '#type' => 'item',
    '#markup' => t('6.  Personal Details:-<br>
                        <span style="margin: 0px 0px 0px 17px;"> a) Mobile Number - '.$data['mobile_num'].'</span> <br>
                        <span style="margin: 0px 0px 0px 17px;"> b) Bank Name - '.$data['bank_name]'].'</span><br>
                        <span style="margin: 0px 0px 0px 17px;"> c) Bank Account Number- '.$data['bank_account_no'].'</span><br>
                        <span style="margin: 0px 0px 0px 17px;"> d) Branch- '.$data['bank_branch'].'</span><br>
'),
    );


         $form[$i]['occupation_d'] = array(
    '#type' => 'item',
    '#markup' => t('7.  Occupation Details:-<br>
                        <span style="margin: 0px 0px 0px 17px;"> a) My Primary Occupation* is _Occ1_ (Code - '.$data['primary_occupation_code'].' ).</span> <br>
                        <span style="margin: 0px 0px 0px 17px;"> b) My Secondary Occupation* is occ2 (Code - '.$data['secondary_occupation_code'].' )</span><br>

'),
    );
 //echo $photo;
if(!empty($photo)){

 $form[$i]['rs30'] = array(
    '#type' => 'item',
    '#markup' => t('8. I am furnishing Rs 30/- for the registration and MPNSS card. <strong>[YES]</strong>'),
    
  );

  $form[$i]['declare'] = array(
    '#type' => 'item',
    '#markup' => t('9. I have provided all the information here true to the best of my knowledge'),
    
  );
}
else{
    $form[$i]['dveclare'] = array(
    '#type' => 'item',
    '#markup' => t('8. I have provided all the information here true to the best of my knowledge'),
    
  );
}



   $form[$i]['endiv'] = array(
         '#type' => 'item',
        '#prefix' => '</div>',

    );
  
 // );

}
$i++;
}
$form['print_decaltion']  = array(
      '#type' => 'markup',
      '#markup' =>t($print),      
       );


   $form['hof_acknowledment'] = array(
                  '#type' => 'link',
                  '#title' => t('Next to print acknowledment slip'),
                  '#prefix' => '<div class="hof_acknowledment"><strong>',
                  '#suffix' => '</strong></div>',  
                  //'#weight' => 10,  
                  '#href' => 'hof/'.arg(1).'/hof_acknowledgement',
                 // '#validate' => array('go_to_delcation_form_validate'), 

                );
    return $form;

}

 function validate_uw($form,&$form_state){

 	if($_SESSION['rural_urban_value'] != ''){
      $edit_sch = 'secc_'.$_SESSION['rural_urban_value'];
  }
  $data = labour_load($edit_sch,arg(1));


   $ahl_tin = arg(1);
    $state_val = $_SESSION['state_value'];
   $r_u = $_SESSION['rural_urban_value'];
  
        $query = db_select('secc_'.$r_u.'.individual_'.$state_val,'secc')      
         ->fields('secc',array('ahl_tin','slnomember','name','genderid','yob','house_hold_id'))
         ->condition('secc.ahl_tin',$ahl_tin,'=')
         ->execute()->fetchAssoc();

  // echo "<pre>";
  // print_r($data);
  $form['vaildat-read-only'] = array(
    '#type' => 'fieldset',
    '#title' => 'Individual detail as per SECC record',  
    '#prefix' => '<div class="read-only-fields">',
   );
  $form['vaildat-read-only']['vaildat_tin_npr'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['tin_npr'],  
    '#attributes' => array('readonly' => 'readonly'),  
    '#title' => t('AHL TIN(SECC)'),
    '#size' => 30,
    );
  $form['vaildat-read-only']['vaildat_ahl_tin'] = array(
    '#type' => 'hidden',
    '#default_value' => $data['ahl_tin'],  
    //'#attributes' => array('readonly' => 'readonly'),  
    //'#title' => t('AHL TIN(SECC)'),
    '#size' => 30,
    );
  $form['vaildat-read-only']['vaildat_update_schema'] = array(
    '#type' => 'hidden',
    '#default_value' => $edit_sch,  
    //'#attributes' => array('readonly' => 'readonly'),  
    //'#title' => t('AHL TIN(SECC)'),
    '#size' => 30,
    );
    
  $form['vaildat-read-only']['vaildat_name'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['name'],  
    '#attributes' => array('readonly' => 'readonly'),  
    '#title' => t('Name'),
    //'#element_validate' => array('custom_valdiation_name'),
    '#size' => 30,
    );
   $form['vaildat-read-only']['hof_relation'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['relation'],  
    '#attributes' => array('readonly' => 'readonly'),  
    '#title' => t('Realtion With HoF as per SECC'),
    //'#element_validate' => array('custom_valdiation_name'),
    '#size' => 30,
    );
  
  $form['vaildat-read-only']['vaildat_name_sl'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['name_sl'],  
    '#attributes' => array('readonly' => 'readonly'),  
    '#title' => t('Name (Regional Lang)'),
    '#size' => 30,
    );
  
  $form['vaildat-read-only']['vaildat_dob'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['dob'],  
    '#attributes' => array('readonly' => 'readonly'),  
    '#title' => t('DOB'),
    '#size' => 10,
    );
  $form['vaildat-read-only']['vaildat_age'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['age'],  
    '#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Age'),  
    '#size' => 5,
    );
  $options = array(1 => t('Yes'),0 => t('No'));
  $form['vaildat-read-only']['vaildat_hof'] = array(
    '#type' => 'radios',
    '#attributes' => array('readonly' => 'readonly'),
    '#options' => $options, 
    '#default_value' => $data['hof'],  

    '#title' => t('HoF'),  
    '#size' => 30,
    );
  
  $form['vaildat-read-only']['vaildat_genderid'] = array(
    '#type' => 'textfield',
    '#default_value' => get_gender($data['genderid']),  
    '#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Gender  ID'),  
    '#size' => 20,
    );
  
  $form['vaildat-read-only']['vaildat_mstatusid'] = array(
    '#type' => 'textfield',
    '#default_value' => get_marital_status($data['mstatusid']),  
    '#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Marital Status'),  
    '#size' => 15,
    );
  
  $form['vaildat-read-only']['vaildat_fathername'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['fathername'],  
    '#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Father Name'),  
    '#size' => 30,
    );
  $form['vaildat-read-only']['vaildat_mothername'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['mothername'],  
    '#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Mother Name'),  
    '#size' => 30,
    );
  $form['vaildat-read-only']['vaildat_occupation'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['occupation'],  
    '#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Occupation'),  
    '#size' => 30,
    );
  
  $form['vaildat-read-only']['vaildat_educode'] = array(
    '#type' => 'textfield',
    '#default_value' => get_education($data['educode']),  
    '#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Education Code'),  
    '#size' => 30,
    );
   $form['vaildat-read-only']['vaildat_education_other'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['education_other'],  
    '#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Education Other'),
    '#suffix' => '</div>',   
    '#size' => 30,
    );


    $form['household_hidden'] = array('#type' => 'hidden', '#value' => $query['house_hold_id']);
   $form['name_hidden'] = array('#type' => 'hidden', '#value' => $query['name']);
   $form['slomember_hidden'] = array('#type' => 'hidden', '#value' => $query['slnomember']);
   $form['genderid_hidden'] = array('#type' => 'hidden', '#value' => $query['genderid']);
   $form['yob_hidden'] = array('#type' => 'hidden', '#value' => $query['yob']);

$form['save-validate'] = array(
    '#type' => 'fieldset',
    '#title' => 'Save and validate',  
    '#prefix' => '<div class="vaidate_read-only-fields">',
   );

$form['save-validate']['sv-alive-decease'] = array(
        '#type' => 'select',
        '#title' => t('Is alive/Deceased'),
        '#options' => array(
          'Alive' => t('Alive'),
          'Decease' => t('Decease'),
          
       ),
    );  
$qry = db_select('activity.family_relation','fm')
        ->fields('fm')
        ->execute()->fetchAll();
   
         $relation_list = array('0' => 'Select');
   
           foreach ($qry as $q){
               $relation_list[$q->code] = t($q->name);
       
           }

$form['save-validate']['sv-hof'] = array(
        '#type' => 'select',
        '#title' => t('Relationship With HoF'),
        '#options' => $relation_list,
        '#required' => TRUE,
        //'#markup' => '<strong> Name :</strong> '.$query['name'].'',
   );


 $form['save-validate']['sv-income'] = array(
        '#type' => 'select',
        '#title' => t('Income'),
        '#options' => array(
          '10000' => t('less than 10,000'),
          '15000' => t('less than 15,000'),
       ),
        '#required' => TRUE,

        //'#markup' => '<strong> Name :</strong> '.$query['name'].'',
   );
    
   
    $form['save-validate']['sv-uw'] = array(
        '#type' => 'select',
        '#title' => t('Unorganised Workers'),
        '#options' => array(
          'No' => t('No'),
          'Yes' => t('Yes'),
       ),
        '#required' => TRUE,

        //'#markup' => '<strong> Name :</strong> '.$query['name'].'',
   );
    
     
     
   
  
    $form['save-validate']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save and validate to proceed'),
    '#weight' => 100,
  );
    
    return $form;

 }


 function validate_uw_validate($form, $form_state){
 	
 	$alive_decease = $form_state['values']['sv-alive-decease'];
 	$income = $form_state['values']['sv-income'];
 	$unorganised =	$form_state['values']['sv-uw'];
 	$relation_with_hof = $form_state['values']['sv-hof'];
 	if(($alive_decease == 'Decease') && ($unorganised == 'Yes') ){

 		form_set_error('', t('Deceased person is not to be Un organised Worker'));
 	}

 	if(($income == '15000') && ($unorganised == 'Yes') ){

 		form_set_error('', t('Income must be less than 10,000 for Un organised worker'));
 	}

 	$age = date('Y') - $form_state['values']['yob_hidden'];

              if(($age < '18') && ($unorganised == 'Yes')) {
 		form_set_error('', t('Age Must be above 18 years for Un organised worker'));
}
 	
 }
 function validate_uw_submit($form,&$form_state){

 	  global $user;
    $ahl_tin = arg(1);

    $r_u = $_SESSION['rural_urban_value'];
 	$st_code = $_SESSION['state_value'];
	$query = db_select('secc_'.$r_u.'.individual_'.$st_code,'secc')      
         ->fields('secc')
         ->condition('secc.ahl_tin',arg(1),'=')
         ->execute()->fetchAssoc();
   
     $age = date('Y') - $form_state['values']['yob_hidden'];

              
    $fqry = db_select('activity.family_registration','a')
            ->fields('a',array('ahl_tin'))
            ->condition('ahl_tin',$ahl_tin)
            ->execute()->fetchcolumn();
            if($fqry != ''){
                
                
                $update_qry = db_update('activity.family_registration')
                              ->fields(array(
                                  'relation_hof' => $form_state['values']['sv-hof'],
                                  'uw_workers' => $form_state['values']['sv-uw'],
                                  'alive_decease' => $form_state['values']['sv-alive-decease'],                                  
                                   'house_hold_id' => $form_state['values']['household_hidden'],
                                   'name' => $form_state['values']['name_hidden'],
                                   'slnomember' => $form_state['values']['slomember_hidden'],
                                   'genderid' => $form_state['values']['genderid_hidden'],
                                   'age' => $form_state['values']['yob_hidden'],                                  
                                  'uid' => $user->uid,
                                  'created' => REQUEST_TIME,
                                  'update_flag' => 1,
                              ))
                              ->condition('ahl_tin',arg(1))
                              ->execute();
                if($update_qry){
                    drupal_set_message(t('Data has been updated successfully.'));
                    $options['absolute'] = TRUE;
                    if($form_state['values']['sv-uw'] == 'Yes'){
         		   $url = url('uw_worker/'.arg(1).'/registration', $options);
         		} else{
         			   $url = url('family/'.$query['house_hold_id'].'/uw-listing', $options);

         		}
           		   //header('Location: '.$url);
           		   drupal_goto($url);	
                }
                              
                
                

            }else{
                    $insert_qry = db_insert('activity.family_registration')
                                    ->fields(array(
                                        'ahl_tin' => arg(1),
                                        'relation_hof' => $form_state['values']['sv-hof'],
                                  		'uw_workers' => $form_state['values']['sv-uw'],
		                               'alive_decease' => $form_state['values']['sv-alive-decease'],                                  
		                                'house_hold_id' => $form_state['values']['household_hidden'],
		                                'name' => $form_state['values']['name_hidden'],
		                                'slnomember' => $form_state['values']['slomember_hidden'],
		                                'genderid' => $form_state['values']['genderid_hidden'],
		                                'age' => $form_state['values']['yob_hidden'],                                  
		                                'uid' => $user->uid,
		                                'created' => REQUEST_TIME,
		                                'update_flag' => 1,
                                    ))
                                    ->execute();
                    if($insert_qry){
                      //  drupal_set_message(t('Data has been updated successfully.'));

 				$options['absolute'] = TRUE;
         		if($form_state['values']['sv-uw'] == 'Yes'){
         		   $url = url('uw_worker/'.arg(1).'/registration', $options);
         		} else{
         			   $url = url('family/'.$query['house_hold_id'].'/uw-listing', $options);

         		}
           		   //header('Location: '.$url);
           		   drupal_goto($url);


                    }

    }
  


 }


 function hof_acknowledgement($form, &$form_state){
    // echo "<pre>";
    // print_r($_SESSION);

 	  $state = $_SESSION['state_value_ack'];
 	  if($_SESSION['rural_urban_value_ack'] == 'rural'){
 	  	$r_u = 'R';
 	  }
 if($_SESSION['rural_urban_value_ack'] == 'urban'){
 	  	$r_u = 'U';
 	  }

       
    if($_SESSION['rural_urban_value_ack'] != ''){
      $edit_sch = 'online_reg_'.$_SESSION['rural_urban_value_ack'];
  }
    $form = array();
    //$data = labour_load($edit_sch,arg(1));
     $qry = db_select($edit_sch.'.individual_'.$state,'fm')
        ->fields('fm')
        ->condition('ahl_tin',arg(1))
        ->execute()->fetchAssoc();
      
 $ahl_tin = $qry['ahl_tin'];
 $nameaspersecc = $qry['name'];
 $correction_name = $qry['correction_name'];
 $aadhaar = $qry['aadhaar'];
 $fathername = $qry['fathername'];
 $correction_fathername = $qry['correction_fathername'];
 $mothername = $qry['mothername'];
 $correction_mothername = $qry['correction_mothername'];
 $yob = $qry['yob'];
 $correction_dob = $qry['correction_dob'];
 $genderid = $qry['genderid'];
 $statecode = $qry['statecode'];
 $districtcode = $qry['districtcode'];
 $tehsilcode = $qry['tehsilcode'];
 $towncode = $qry['towncode'];
 $p_pincode = $qry['p_pincode'];
 $p_address1 = $qry['p_address1'];


 $village_list_c = _get_location('village',$statecode,$districtcode,$tehsilcode,'',	$r_u);
  $cvill = $village_list_c[$towncode];

 $district_list_ackc = _get_location('district',$statecode);
  $cdistrict_d = $district_list_ackc[$districtcode];

  $tehsil_list_ackc = _get_location('tehsil',$statecode,$districtcode);
  $tehsil_d = $tehsil_list_ackc[$tehsilcode];

$state_listackc = _get_location('state');
 $cstate_d = $state_listackc[$statecode];

 	$options = array(
	'target_id' => 'ack_header',
	'button_id' => 'my_print_button',
	'value' => t('Print'),
	'type' => 'link',
	'custom_css' => path_to_theme().'/css/style.css',
	);

	  $print = area_print_form($options);


$form['ackacknolegmnet'] = array(
         '#type' => 'item',
        '#prefix' => '<div class="ackacknolegmnet">',
        // '#suffix' => '</div>',  

    );

 	$form['header'] = array(
         '#type' => 'item',
        '#prefix' => '<div class="ack_header">',
        // '#suffix' => '</div>',  

    );
    //print $base_url;
    $satymeo = base_path() . path_to_theme().'/images/satyamev_jayate.png';

$form['satymew_logo'] = array(
               '#type' => 'markup',
               '#markup' => '<img src="'.$satymeo.'">',
                '#prefix' => '<div class="satymew_logo"><span>',
                 '#suffix' => '</div>',  
               );

$form['headermiddle'] = array(
         '#type' => 'item',
        '#prefix' => '<div class="header_middle_ack">',

    );
   $form['govt_of_india'] = array(
         '#type' => 'item',
        '#markup' => '<strong> Government of India</strong>',    
        '#prefix' => '<div class="govt_of_india">',
         '#suffix' => '</div>',  

    );
    $form['npssc'] = array(
        '#type' => 'item',
        '#markup' => '<strong>Mahatma Phule National Social Security Card</strong> ',    
   	 	'#prefix' => '<div class="npssc">',
         '#suffix' => '</div>', 
    );

     $form['ack_slip'] = array(
        '#type' => 'item',
        '#markup' => '<strong>ACKNOWLEDGEMENT SLIP</strong> ', 
    	'#prefix' => '<div class="ack_slip">',
         '#suffix' => '</div>', 
    );
     $form['headermiddleend'] = array(
         '#type' => 'item',
        '#prefix' => '</div>',

    );
      $shrmeo = base_path() . path_to_theme().'/images/RSBY_Logo.jpg';

     $form['sharmeo_logo'] = array(
               '#type' => 'markup',
               '#markup' => '<img src="'.$shrmeo.'">',
                '#prefix' => '<div class="shrameo_logo"><span>',
                 '#suffix' => '</div>',  
               );

    //   $form['headerclose'] = array(
    //      '#type' => 'item',
    //     '#prefix' => '</div>',

    // );
      $form['ack_midle'] = array(
         '#type' => 'item',
        '#prefix' => '<div class="ack_miidle_second">',

    );

$form['ack_midle1'] = array(
         '#type' => 'item',
        '#prefix' => '<div class="ack_midle1">',

    );
     $phto = 'data:image/gif;base64,'.$qry['photograph'];
$form['hof_img'] = array(
               '#type' => 'markup',
               '#markup' => '<img src="'.$phto.'">',
                '#prefix' => '<div class="hof_img"><span>',
                 '#suffix' => '</span></div>',  
               );
 $form['ack_midle1close'] = array(
         '#type' => 'item',
        '#prefix' => '</div>',

    );

$form['ack_midle2'] = array(
         '#type' => 'item',
        '#prefix' => '<div class="ack_midle2">',

    );


$form['reference_number'] = array(
    '#type' => 'item',
    '#markup' => '<strong>Reference Number(AHL TIN) :</strong>'.$ahl_tin.'',
    '#prefix' => '<div class="reference_number">',
    '#suffix' => '</div>',  
  
    );

$form['date_registration'] = array(
    '#type' => 'item',
    '#markup' => '<strong>Date of Registration :</strong> 29/02/2016',     
    '#prefix' => '<div class="date_registration">',
    '#suffix' => '</div>', 
    );



   $form['name_as_per_secc'] = array(
     '#type' => 'item',
    '#markup' => '<strong>Name as per SECC :</strong>'. $nameaspersecc.'', 
    '#prefix' => '<div class="name_as_per_secc">',
    '#suffix' => '</div>',
    );
    
   $form['modified_name'] = array(
     '#type' => 'item',
    '#markup' => '<strong>Modified Name :</strong>'.$correction_name.'',
    '#prefix' => '<div class="modified_name">',
    '#suffix' => '</div>',
    );

   $form['aadhaar-ack'] = array(
     '#type' => 'item',
    '#markup' => '<strong>Aadhar Number :</strong>'.$aadhaar.'',
    '#prefix' => '<div class="aadhaar_ack">',
    '#suffix' => '</div>',
    );
    $form['ack_midle2close'] = array(
         '#type' => 'item',
        '#prefix' => '</div>',

    );
     $form['ack_midleclose'] = array(
         '#type' => 'item',
        '#prefix' => '</div>',

    );
      $form['hofdetail'] = array(
    '#type' => 'item',
   // '#title' => 'Indivdual detail as per SECC record',  
    '#prefix' => '<div class="hofdetail">',
   );

  
   $form['fathersecc'] = array(
     '#type' => 'item',
    '#markup' => '<strong>Father name as per SECC :</strong>'. $fathername.'',
    '#prefix' => '<div class="fathersecc">',
    '#suffix' => '</div>',
    );
   
   $form['modifiedfather'] = array(
     '#type' => 'item',
    '#markup' => '<strong>Modified father name :</strong>'.$correction_fathername.'' ,
    '#prefix' => '<div class="modifiedfather">',
    '#suffix' => '</div>',
    );
   $form['mothersecc'] = array(
     '#type' => 'item',
    '#markup' => '<strong>Mother name as per SECC :</strong>'.$mothername.'',
    '#prefix' => '<div class="mothersecc">',
    '#suffix' => '</div>',
    );
   $form['modifiedmother'] = array(
     '#type' => 'item',
    '#markup' => '<strong>Modified mother name :</strong>'. $correction_mothername.'',
    '#prefix' => '<div class="modifiedmother">',
    '#suffix' => '</div>',
    );
    $form['yobsecc'] = array(
     '#type' => 'item',
    '#markup' => '<strong>Year of birth as per SECC :</strong>'.$yob.'',
    '#prefix' => '<div class="yobsecc">',
    '#suffix' => '</div>',
    );
    $form['modifieddob'] = array(
     '#type' => 'item',
    '#markup' => '<strong>Modified Date of Birth :</strong>'.$correction_dob.'',
    '#prefix' => '<div class="modifieddob">',
    '#suffix' => '</div>',
    );
    if($genderid ==1){
    	$male = 'Male';
    }else{
    	$male = 'Female';
    }
    $form['gender'] = array(
     '#type' => 'item',
    '#markup' => '<strong>Gender :</strong>'.$male.'',
    '#prefix' => '<div class="gender">',
    '#suffix' => '</div></div>',
    );



$form['hofaddressdetail'] = array(
    '#type' => 'item',
   // '#title' => 'Indivdual detail as per SECC record',  
    '#prefix' => '<div class="hofaddressdetail">',
   );
   $form['state'] = array(
     '#type' => 'item',
    '#markup' => '<strong>State :</strong>'.$cstate_d.'',
    '#prefix' => '<div class="state_ack">',
    '#suffix' => '</div>',
    );
   
   $form['district'] = array(
     '#type' => 'item',
    '#markup' => '<strong>District :</strong>'.$cdistrict_d.'',
    '#prefix' => '<div class="district_ack">',
    '#suffix' => '</div>',
    );
   $form['tehsil'] = array(
     '#type' => 'item',
    '#markup' => '<strong>Tehsil :</strong>'.$tehsil_d.'',
    '#prefix' => '<div class="mothersecc_ack">',
    '#suffix' => '</div>',
   );
   $form['village'] = array(
     '#type' => 'item',
    '#markup' => '<strong>Village :</strong>'.$cvill.'',
    '#prefix' => '<div class="village_ack">',
    '#suffix' => '</div>',
    );
    $form['pin'] = array(
     '#type' => 'item',
    '#markup' => '<strong>PIN :</strong>'.$p_pincode.'',
    '#prefix' => '<div class="pin_ack">',
    '#suffix' => '</div>',
    );
    $form['address'] = array(
     '#type' => 'item',
    '#markup' => '<strong>Address :</strong>'.$p_address1.'',
    '#prefix' => '<div class="address_ack">',
    '#suffix' => '</div></div>',
    );
    
$form['unorganisedworker'] = array(
     '#type' => 'item',
    '#markup' => '<strong>List of other Unorganised woker in family</strong>',
    '#prefix' => '<div class="unorganisedworker">',
    '#suffix' => '</div>',
    );
    

      $header = array('S.No','Name');
      $otherqry = db_select($edit_sch.'.individual_'.$state,'fm')
        ->fields('fm',array('house_hold_id'))
        ->condition('ahl_tin',arg(1))
        ->execute()->fetchAssoc();

        $house =$otherqry['house_hold_id'];

         $workerqry = db_select($edit_sch.'.individual_'.$state,'fma')
        ->fields('fma')
        ->condition('house_hold_id',$house)
        ->condition('hof','1','!=')
        ->isNull('photograph')
       // ->condition('fma.photograph','','=')
        ->execute();
        $i =1;	
        while ($workername = $workerqry->fetchAssoc()) {


        	$rows[]= array(
                              $i,    
                              $workername['name'],                               
                          );
                            $i++;

                             $form['table'] = array(
                                 '#theme' => 'table',
                                 '#header' => $header,
                                 '#rows' => $rows,
                                 '#empty' => t('Table has no row!'),
                                 // '#prefix' => "<div id='my_printable_div'>",
                                 // '#suffix' => "</div>",
                               );
        }

        $form['thumb'] = array(
     '#type' => 'item',
    '#markup' => '<strong>Signature of Registration agency Representative</strong> ',
    '#prefix' => '<div class="thumb">',
    '#suffix' => '</div></div>',
    );
         $form['close'] = array(
         '#type' => 'item',
        '#prefix' => '</div>',

    );

     $form['print_acknolegmnet']  = array(
      '#type' => 'markup',
      '#markup' =>t($print),
     '#prefix' => '<div class="print_acknolegmnet">',
    '#suffix' => '</div></div></div>',    
       );
   
    return $form;
 }

 function print_self_declartion_ack($form, &$form_state){
    
  global $user;
  $role = end($user->roles);
  $user_info = user_load($user->uid);

 $options = array(
  'target_id' => 'my_printable_div',
  'button_id' => 'my_print_button',
  'value' => t('Print Record'),
  'type' => 'link',
  'custom_css' => path_to_theme().'/css/style.css',
  );

 $ru = $form_state['values']['rural_urban'];
 if($ru == 'rural'){
    $ru_val = 'R';
 } else{
        $ru_val = 'U';

 }

//print $ru_val;
 //area_print_form($options);

  //print "aaaaaaa";
  $print = area_print_form($options);

/*if($_SESSION['village_value_ack'] !='0'){
  $session_village = $_SESSION['village_value_ack'];
}*/

if($_SESSION['secc_uw_value_ack'] !=''){
  $session_sec = $_SESSION['secc_uw_value_ack'];
}
if($_SESSION['rural_urban_value_ack'] !=''){
  $session_rural = $_SESSION['rural_urban_value_ack'];
}

//Add Code for agency role
global $user;
$aa = user_load($user->uid);
$usermail = $user->mail;
$querynode = db_select('node', 'n');
              $querynode->fields('n');
              $querynode->condition('type','agency','=');
  $resultn = $querynode->execute();
  while ($datanode = $resultn->fetchAssoc()) {
//echo $datanode['nid'];

 $node =  node_load($datanode['nid']);
   $emailvalue = field_get_items('node', $node, 'field_email_id');
   foreach ($emailvalue as $key => $email) {

  $agency_detail = array();
if($email['email'] == $usermail){
 $agency_detail = array( 'agency_id' =>$datanode['nid'],
                        'agency_mail' =>$email['email'],
  ); 
   }
  
} 
  }
 $query = db_select('agency_record', 'ag_r');
              $query->fields('ag_r');
              $query->condition('ag_r.agency',$agency_detail['agency_id'],'=');
  $result = $query->execute()->fetchAssoc();

//End code for agency role
   
    $form['secc_uw'] = array(
        '#type' => 'radios',
        '#title' => t('Select Data Source'),
        '#options' => array(
        //'secc_' => t('Socio-Economic Caste Census'),//Socio-Economic Caste Census
        'uw_' => t('Socio-Economic Caste Census'),//Possible Unorganised Workers based on MoLE Criteria
        ),
        '#required' => TRUE,
        '#default_value' => $session_sec, 
        '#prefix' => '<div id="wrapper_area_sec_uowd">',
        '#suffix' => '</div>',
      );
    
    $form['rural_urban'] = array(
      '#type' => 'radios',
      '#title' => t('Select Area'),
       '#options' => array(
         'rural' => t('Rural'),
         'urban' => t('Urban'),
        ),
       '#required' => TRUE,
      '#default_value' => $session_rural, 
      '#prefix' => '<div id="wrapper_area_choice">',
      '#suffix' => '</div>',
       '#ajax' => array(
            'callback' => 'ajax_callback_rural_urban',
            'wrapper' => 'wrapper_rurul_urban',
            
        ),

      );

     $aa = user_load($user->uid);
 $usermail = $user->mail;

$querynode = db_select('node', 'n');
              $querynode->fields('n');
              $querynode->condition('type','agency','=');
  $resultn = $querynode->execute();
                  $agency_detail = array();

  while ($datanode = $resultn->fetchAssoc()) {


 $node =  node_load($datanode['nid']);
 $emailvalue = field_get_items('node', $node, 'field_email_id');
 foreach ($emailvalue as $key => $email) {

            if($email['email'] == $usermail){
                $agency_detail = array( 'agency_id' =>$datanode['nid'],
                                       'agency_mail' =>$email['email'],
                 ); 
               }  
        } 
  }
 $query = db_select('agency_record', 'ag_r');
              $query->fields('ag_r');
              $query->condition('ag_r.agency',$agency_detail['agency_id'],'=');
  $data = $query->execute();



    if(($role == 'MOLE') ||($user->uid == 1)){
            $state_list = _get_location('state','','','','',$ru_val);
          }
          if(($role == 'State') || ($role == 'District') || ($role == 'Tehsil') || ($role == 'Agent')){
            $state_value_ack = $user_info->field_state['und'][0]['value'];
            $state_list_data = _get_location('state','','','','',$ru_val);
            $state_list[$state_value_ack] = $state_list_data[$state_value_ack];
          }
          // if(($role == 'Agency')){
          //   $state_value_ack = $result['state'];
          //   $state_list_data = _get_location('state');
          //   $state_list[$state_value_ack] = $state_list_data[$state_value_ack];
          // }

 if(($role == 'Agency')){
            while($result = $data->fetchAssoc()){
            $state_value_ack = $result['state'];
            $state_list_data = _get_location('state','','','','',$ru_val);
            $state_list['0'] = 'Select';
            $state_list[$state_value_ack] = $state_list_data[$state_value_ack];
            }
            
          }

   $session_state = ($_SESSION['state_value_ack'] !='') ? $_SESSION['state_value_ack']: key($state_list);

   // $state_list = _get_location('state');
    
  $state_selected = isset($form_state['values']['state']) ? $form_state['values']['state'] : $session_state;
    //$state_val = _drupal_session_read('state_value_ack');
    
    $form['state'] = array(
        '#title' => 'State',
        '#type' => 'select',
        '#options' => $state_list,
        '#default_value' => $state_selected,
        '#required' => TRUE,
        '#ajax' => array(
            'callback' => 'ajax_callback_state',
            'wrapper' => 'wrapper_state',
            
        ),
        
    );

     if(($role == 'District') || ($role == 'Tehsil') || ($role == 'Agent')){
          $district_value_ack = $user_info->field_district['und'][0]['value'];
          $district_list_data = _get_location('district',$state_selected,'','','',$ru_val);
          $district_list[$district_value_ack] = $district_list_data[$district_value_ack];
     }

    if(($role == 'State')||($role == 'MOLE') ||(($user->uid == 1))){
        $district_list = _get_location('district',$state_selected,'','','',$ru_val);
    }
    // if(($role == 'Agency') ){
    //       $district_value_ack = $result['district'];
    //       $district_list_data = _get_location('district',$state_selected);
    //       $district_list[$district_value_ack] = $district_list_data[$district_value_ack];
    // }


     if(($role == 'Agency') && ($state_selected !='0') ){
      $query = db_select('agency_record', 'ag_r');
              $query->fields('ag_r');
              $query->condition('ag_r.agency',$agency_detail['agency_id'],'=');
              $query->condition('ag_r.state',$state_selected,'=');
              $datas = $query->execute();
          //   $result = $data->fetchAssoc();
                 while ($result  = $datas->fetchAssoc()) {
                    // echo "<pre>";
                    //  print_r($result);
            //drupal_set_message('<pre> Agency record data'.print_r($result,TRUE).'</pre>');
            $district_value_ack = $result['district'];
            $district_list_data = _get_location('district',$state_selected,'','','',$ru_val);
            $district_list['0'] = 'Select';
            $district_list[$district_value_ack] = $district_list_data[$district_value_ack];
          }
        }
        if($state_selected =='0'){
                        $district_list['0'] = 'Select';

        }
        
     $session_district = ($_SESSION['district_value_ack'] !='') ? $_SESSION['district_value_ack']: key($district_list);


  //  $district_list = _get_location('district',$state_selected);
    $district_selected = isset($form_state['values']['district']) ? $form_state['values']['district'] : $session_district;
    $form['district'] = array(
        '#title' => 'District',
        '#type' => 'select',
        '#options' => $district_list,
        '#default_value' => $district_selected,
        '#required' => TRUE,
        '#prefix' => '<div id="wrapper_state">',
        '#suffix' => '</div>',
        '#ajax' => array(
            'callback' => 'ajax_callback_district',
            'wrapper' => 'wrapper_tehsil',
            
        ),
        
    );

    if(($role == 'Tehsil') || ($role == 'Agent')){
          $tehsil_value_ack = $user_info->field_tehsil['und'][0]['value'];
          $tahsil_list_data = _get_location('tehsil',$state_selected,$district_selected,'','',$ru_val);
          $tehsil_list[$tehsil_value_ack] = $tahsil_list_data[$tehsil_value_ack];
        }

    if(($role == 'State') || ($role == 'District') || ($role == 'MOLE')||($user->uid == 1)){
    $tehsil_list = _get_location('tehsil',$state_selected,$district_selected,'','',$ru_val);
    }
    
    // if( ($role == 'Agency')){
    
    // $tehsil_value_ack = $result['tehsil'];
    // $tehsil_list_data = _get_location('tehsil',$state_selected,$district_selected);
    // $tehsil_list[$tehsil_value_ack] = $tehsil_list_data[$tehsil_value_ack];
    // $tehsil_selected = isset($form_state['values']['tehsil']) ? $form_state['values']['tehsil'] : key($tehsil_list); 

    // }

    if( ($role == 'Agency')){
        
$queryagency = db_select('agency_record', 'ag_r');
              $queryagency->fields('ag_r');
              $queryagency->condition('ag_r.agency',$agency_detail['agency_id'],'=');
              $queryagency->condition('ag_r.state',$state_selected,'=');
              $queryagency->condition('ag_r.district',$district_selected,'=');

  $dataqueryagency = $queryagency->execute();

  $tehsil = array();
            while ( $resulttehsil  = $dataqueryagency->fetchAssoc()) {
              $tehsil[] = $resulttehsil['tehsil'];
            }
                $tehsil_value_ack = $tehsil;
                $tehsil_list_data = _get_location('tehsil',$state_selected,$district_selected,'','',$ru_val);

                    $tehsil_list = array();
                    $tehsil_list['0'] = 'Select';
                  foreach ($tehsil_value_ack as $key => $tehsil_data) {
                    $tehsil_list[$tehsil_data] = $tehsil_list_data[$tehsil_data];
                  }
        //$session_tehsil = ($_SESSION['dow_tehsil_value_ack'] !='') ? $_SESSION['dow_tehsil_value_ack']: key($tehsil_list);
   //$tehsil_selected = isset($form_state['values']['tehsil']) ? $form_state['values']['tehsil'] : $session_tehsil; 


    }

     $session_tehsil = ($_SESSION['tehsil_value_ack'] !='') ? $_SESSION['tehsil_value_ack']: key($tehsil_list);

    
  //  $tehsil_list = _get_location('tehsil',$state_selected,$district_selected);
    $tehsil_selected = isset($form_state['values']['tehsil']) ? $form_state['values']['tehsil'] : $session_tehsil; 
    $form['tehsil'] = array(
        '#title' => 'Tehsil',
        '#type' => 'select',
        '#options' => $tehsil_list,
        '#default_value' => $tehsil_selected,
         '#required' => TRUE,
        '#prefix' => '<div id="wrapper_tehsil">',
        '#suffix' => '</div>',
        '#ajax' => array(
            'callback' => 'ajax_callback_tehsil',
            'wrapper' => 'wrapper_village',
            
        )
    );
    

        if(($role == 'Agent')){
      
         $village_value_ack = $user_info->field_village['und'][0]['value'];
          $village_list_data = _get_location('village',$state_selected,$district_selected,$tehsil_selected,'',$ru_val);
          $village_list[$village_value_ack] = $village_list_data[$village_value_ack];
        }

    if(($role == 'Tehsil') || ($role == 'State') || ($role == 'District') || ($role == 'MOLE')||($user->uid == 1)){
    $village_list = _get_location('village',$state_selected,$district_selected,$tehsil_selected,'',$ru_val);
    }
    
    // if( ($role == 'Agency')){
    //         $village_list_data = _get_location('village',$state_selected,$district_selected,$tehsil_selected);
    //         $vill_value = explode(',', $result['village']);
                 
    //         $village_list = array();
    //         foreach ($vill_value as $key => $village_data) {
    //                 $village_list[$village_data] = $village_list_data[$village_data];
    //         }
    //         $vill_session_value = isset($_SESSION['dow_village_value_ack']) ? $_SESSION['dow_village_value_ack'] : key($village_list);
    //         $village_selected = isset($form_state['values']['village']) ? $form_state['values']['village'] : $vill_session_value;

    // }


     if( ($role == 'Agency')){

              $village_list_data = _get_location('village',$state_selected,$district_selected,$tehsil_selected,'',$ru_val);
              //drupal_set_message('<pre>'.print_r($village_list_data).'');
              $queryagencyvill = db_select('agency_record', 'ag_r');
              $queryagencyvill->fields('ag_r');
              $queryagencyvill->condition('ag_r.agency',$agency_detail['agency_id'],'=');
              $queryagencyvill->condition('ag_r.state',$state_selected,'=');
              $queryagencyvill->condition('ag_r.district',$district_selected,'=');
             $queryagencyvill->condition('ag_r.tehsil',$tehsil_selected,'=');

              $queryagencyvilldata = $queryagencyvill->execute();
              $village = array();
                while ( $result  = $queryagencyvilldata->fetchAssoc()) {
                  $village[] = $result;
            }
             $vill_value = $village;
            
             $village_s = array();
             foreach ($vill_value as $key => $village_data) {
                    
                  $currentDate = strtotime(date("Y-m-d"));
                  $DateBegin = strtotime($village_data['dowload_date_from']);
                  $DateEnd = strtotime($village_data['dowload_date_to']);

                  //if($currentDate > $DateBegin && $currentDate < $DateEnd) {
                          $village_s[] = explode(',', $village_data['village']);
                  //} 
      }
      //drupal_set_message('<pre>'.print_r($village_s).'');
                     $resultvill = array();
                      foreach ($village_s as $key => $village_svalue) {
                      $resultvill = array_merge($resultvill, $village_svalue);

                    }
                 // print_r($resultvill);
                    $village_list = array();
                    $village_list['0'] = 'Select';
                    foreach ($resultvill as $key => $resultvilldata) {
                    $village_list[$resultvilldata] = $village_list_data[$resultvilldata];
                  }
                   $vill_session_value = isset($_SESSION['dow_village_value_ack']) ? $_SESSION['dow_village_value_ack'] : key($village_list);
                   $village_selected = isset($form_state['values']['village']) ? $form_state['values']['village'] : $vill_session_value;

}

     $session_village = ($_SESSION['village_value_ack'] !='') ? $_SESSION['village_value_ack']: key($village_list);

    //$village_list = _get_location('village',$state_selected,$district_selected,$tehsil_selected);
    $village_selected = isset($form_state['values']['village']) ? $form_state['values']['village'] : $session_village;
    $form['village'] = array(
        '#title' => 'Village/Town',
        '#type' => 'select',
        '#options' => $village_list,
        '#default_value' => $village_selected,
        '#required' => TRUE,
        '#prefix' => '<div id="wrapper_village">',
        '#suffix' => '</div>',
//        '#ajax' => array(
//            'callback' => 'ajax_callback_state',
//            'wrapper' = > 'wrapper_state',
//            
//        )
    );
     
 $person_selected = ($_SESSION['person_name_ack'] !='') ? $_SESSION['person_name_ack']: '';

 $form['person_name_ack'] = array(
    '#type' => 'textfield', 
    '#title' => t('Name Of Person sounding Like..'), 
    '#default_value' => $person_selected,
    '#size' => 30, 
    '#maxlength' => 128, 
);
 $find_house_hold_id_ack = ($_SESSION['house_hold_id_ack'] !='') ? $_SESSION['house_hold_id_ack']: '';
 $form['house_hold_id_ack'] = array(
    '#type' => 'textfield', 
    '#title' => t('AHL Tin'), 
    '#default_value' => $find_house_hold_id_ack,
    '#size' => 30, 
    '#maxlength' => 128, 
);
    
 $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

 $form['reset'] = array(
    '#type' => 'submit',
    '#submit' => array('search_reset'),
    '#value' => t('Reset'),
  );

if(!empty($_SESSION['village_value_ack'])){
 $form['print_listperson']  = array(
      '#type' => 'markup',
      '#markup' =>t($print),      
       );
}
 /*Start code to display the results*/
 //$session_id = _drupal_session_read('house_id');
 
 $sec = $_SESSION['rural_urban_value_ack'];
 if($session_district == 0){
  $session_district ='';
 }
 if($session_tehsil == 0){
  $session_tehsil ='';
 }
 if($session_village == 0){
  $session_village ='';
 }

 if(!empty($sec)){

 $person_name_ack = $_SESSION['person_name_ack'];
 $search_ahltin = $_SESSION['house_hold_id_ack'];
  
  $house_hold_id_ack = $session_state.''.$session_district.''.$session_tehsil.''.$session_village;
 //drupal_set_message('And table name'.$tbl.".individual_21".'house hold id'.$house_hold_id_ack.'');
  
 $header = array('S.N','AHL TIN','House-Hold ID', 'Member S.No','Name', 'Name(Regional)','Fathers\'s Name','Mother\'s Name','Occupation','YoB (YYYY)/DoB (DD/MM/YYYY)','HoF','Gender','Relation With HOF','Print Record');
 
        $query = db_select("online_reg_".$sec.".individual_".$_SESSION['state_value_ack'], "n");
        $query->fields('n');
        $query->condition('n.statecode', $session_state, '=');
        $query->condition('n.districtcode', $session_district, '=');
        $query->condition('n.tehsilcode', $session_tehsil, '=');
        $query->condition('n.towncode', $session_village, '=');
        //$query->condition('n.hof', '1', '=');
        $query->condition('n.photograph', '', '!=');

        if(!empty($person_name_ack)){
          $query->condition('n.name', '%'.db_like($person_name_ack) . '%', 'LIKE');
       }
       if(!empty($search_ahltin)){
          $query->condition('n.ahl_tin',$search_ahltin);
       }
       $query->orderBy('n.house_hold_id','ASC');
       $query = $query->extend('TableSort')->extend('PagerDefault')->limit(20);
       $result = $query->execute();
       
 
   $page =($_GET['page']*20);

                $i = $page+1;
                          while($data = $result->fetchObject()){
                          	
                              
                          $print = l('Print','uw/'.$data->ahl_tin.'/self_declation_form');
                            
                              $rows[$data->ahl_tin] = array(
                              $i,    
                              $data->ahl_tin,
                              $data->house_hold_id,
                              $un_worker_status,    
                              $data->name,
                              $data->name_sl,    
                              $data->fathername,
                              $data->mothername,
                              $data->occupation,
                              $data->yob,    
                              get_hof($data->hof),
                              get_gender($data->genderid),
                              $data->relation,
                              $print,
                                
                          );
                              
                            $i++;
                        }
                        
                        
                             $form['table'] = array(
                                 '#theme' => 'table',
                                 '#header' => $header,
                                 '#rows' => $rows,
                                 '#empty' => t('Table has no row!'),
                                 '#prefix' => "<div id='my_printable_div'>",
                                 '#suffix' => "</div>",
                               );
    
       


$form['pager'] = array('#markup' => theme('pager'));

}  

    return $form;
    
}

function print_self_declartion_ack_submit($form,$form_state){
 
    if($form_state['values']['state'] != '0'){
           $_SESSION['state_value_ack'] =  $form_state['values']['state'];

       }
       if ($form_state['values']['district'] != '') {
            $_SESSION['district_value_ack'] =  $form_state['values']['district'];
           
       }
       if ($form_state['values']['tehsil'] != '') {
                    $_SESSION['tehsil_value_ack'] =  $form_state['values']['tehsil'];

       }
       if ($form_state['values']['village'] != '') {

                 $_SESSION['village_value_ack'] =  $form_state['values']['village'];

       }
        if ($form_state['values']['secc_uw'] != '') {

                 $_SESSION['secc_uw_value_ack'] =  $form_state['values']['secc_uw'];

       }
        if ($form_state['values']['rural_urban'] != '') {

                 $_SESSION['rural_urban_value_ack'] =  $form_state['values']['rural_urban'];

       }
       if ($form_state['values']['person_name_ack'] != '') {

                 $_SESSION['person_name_ack'] =  $form_state['values']['person_name_ack'];

       }
       if ($form_state['values']['house_hold_id_ack'] != '') {

                 $_SESSION['house_hold_id_ack'] =  $form_state['values']['house_hold_id_ack'];

       }

       
        //_drupal_session_read('house_id');
}



function self_declation_form_validate($form,$form_state){

	 $choose_state = $form_state['values']['state'];
    $choose_ru_ur = $form_state['values']['rural_urban'];
    $pre_secc = 'secc_';
    $tbl = $pre_secc.''.$choose_ru_ur;
    
    $new_tbl_name = $tbl.".individual_".$choose_state;
    
    if(db_table_exists($new_tbl_name)){
             //form_set_error('', t('State table Does not exist'));  
    }else{
        form_set_error('', t('Table Does Not Exist need state value in session so search on view edit'));  
    }

}


function print_self_declartion_ack_validate($form,$form_state){

	 $choose_state = $form_state['values']['state'];
    $choose_ru_ur = $form_state['values']['rural_urban'];
    $pre_secc = 'online_reg_';
    $tbl = $pre_secc.''.$choose_ru_ur;
    
    $new_tbl_name = $tbl.".individual_".$choose_state;
    
    if(db_table_exists($new_tbl_name)){
             //form_set_error('', t('State table Does not exist'));  
    }else{
        form_set_error('', t('Table Does Not Exist need state value in session so search on view edit'));  
    }

}


