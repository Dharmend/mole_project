<?php


function update_relationship($form,&$form_state){
    
  if($_SESSION['rural_urban_value'] != ''){
      $edit_sch = 'secc_'.$_SESSION['rural_urban_value'];
  }
  $data = labour_load($edit_sch,arg(1));
  $form['read-only'] = array(
    '#type' => 'fieldset',
    '#title' => 'Read Only',  
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
  $options = array(1 => t('Yes'),0 => t('No'));
  $form['read-only']['hof'] = array(
    '#type' => 'radios',
    '#default_value' => get_hof($data['hof']),  
    '#attributes' => array('readonly' => 'readonly'),
    '#options' => $options, 
    '#title' => t('HoF'),  
    '#size' => 30,
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
   $form['markup_data'] = array(
               '#type' => 'markup',
               '#markup' => ('Click Here To Edit Above Field'),
                '#prefix' => '<div class="editseccdata"><span>',
                 '#suffix' => '</span></div>',  
               );


$form['correction_name'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['correction_name'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Name'),
    '#prefix' => '<div class="correction_personal_info">',  
    '#size' => 30,
    );


   $active = array(1 => t('Yes'), 0 => t('No'));
   $form['correction_hof'] = array(
    '#type' => 'radios',
    '#title' => t('HOF'),
    '#default_value' => $data['correction_hof'],
    '#options' => $active,
    '#size' => 30,
    
  );
   
   $form['correction_dob'] = array(
    '#type' => 'date_popup',
    '#default_value' => $data['correction_dob'],
      '#date_format' => 'Y-m-d',  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('DOB'),  
    '#size' => 30,
      '#date_year_range' => '-90:+3',
    );
   
$marital_arr = array(0=>'Select',1 => 'Never married',2 => 'Currently married',3 => 'Widowed', 4 => 'Separated',5 => 'Divorced');
   
   $form['correction_marital_status'] = array(
    '#type' => 'select',
    '#default_value' => $data['correction_marital_status'],
    '#options' => $marital_arr,   
    '#title' => t('Marital Status'),  
    //'#size' => 30,
    );
   
   $education_array = array(0 => 'Select',1 => 'Illiterate',2 => 'Literate but below primary',3 => 'Primary', 4 => 'Middle',5 => 'Secondary',6 => 'Higher Secondary',7 => 'Graduate or higher',8 => 'Other(specify)');
   $form['correction_eductaion'] = array(
    '#type' => 'select',
    '#default_value' => $data['correction_eductaion'],  
    '#title' => t('Education'),  
    '#options' => $education_array,
    //'#size' => 30,
    );

   $form['correction_fathername'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['correction_fathername'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Father Name'),  
    '#size' => 30,
    );

   $form['correction_mothername'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['correction_mothername'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Mother Name'),  
    '#size' => 30,
    );

    $form['correction_occupation'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['correction_occupation'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Occupation'),  
    '#size' => 30,
    '#suffix' => '</div>',
    );
  
   /////////////////////////////////////////////


   $form['aadhaar'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['aadhaar'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Aadhaar Number'),
    '#prefix' => '<div class="personal_info">',  
    '#size' => 30,
    );
   $form['e_id'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['e_id'],
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('EID (if Aadhar card is not available)'),  
    '#size' => 30,
    );
   
   $form['bank_account_no'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['bank_account_no'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Bank Account No.'),  
    '#size' => 30,
    );
   
   $form['bank_name'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['bank_name'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Bank Name'),  
    '#size' => 30,
    );
   
   $form['bank_branch'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['bank_branch'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Bank Branch'),  
    '#size' => 30,
    );
   $primary_occupation = array(0 => 'Select',1 => 'Farmer',2 => 'Fisherman',3 => 'Own business',4 => 'Govt job','5' => 'Others');
   $form['primary_occupation_code'] = array(
    '#type' => 'select',
    '#default_value' => $data['primary_occupation_code'],
    '#options' => $primary_occupation,   
    '#title' => t('Primary Occupation'),  
    //'#size' => 30,
    );
   $secondary_occupation = array(0 => 'Select',1 => 'Tailor',2 => 'Milk vendor',3 => 'Money Lander',4 => 'Others');
   $form['secondary_occupation_code'] = array(
    '#type' => 'select',
    '#default_value' => $data['secondary_occupation_code'],
    '#options' => $secondary_occupation,  
    '#title' => t('Secondary Occupation'),
    '#suffix' => '</div>',   
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
   $form['current-address']['c_address1'] = array(
    '#type' => 'textfield',
    '#default_value' => $data['c_address1'],  
    //'#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Current Address'),  
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
        '#required' => TRUE,
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
        '#required' => TRUE,
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
         '#required' => TRUE,
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
        '#required' => TRUE,
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
                        'c_address1' => $form_state['values']['c_address1'],
                        'c_address2' => $form_state['values']['c_address2'],
                        'c_villagetown' => $form_state['values']['village_p'],
                        'c_tehsil' => $form_state['values']['tehsil_p'],
                        'c_district' => $form_state['values']['district_p'],
                        'c_state' => $form_state['values']['state_p'],
                        'c_pincode' => $form_state['values']['c_pincode'],        
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
  custom_valdiation_bank_name($form_state['values']['bank_name']);
  custom_valdiation_bank_name($form_state['values']['bank_branch']);
  
  custom_valdiation_address($form_state['values']['p_address1']);
  custom_valdiation_address($form_state['values']['p_address2']);
  custom_valdiation_address($form_state['values']['c_address1']);
  custom_valdiation_address($form_state['values']['c_address2']);
  
  custom_valdiation_pincode();
  
}

function self_declation_form($form, $form_id, $form_state){
       $state = $_SESSION['state_value'];

    if($_SESSION['rural_urban_value'] != ''){
      $edit_sch = 'online_reg_'.$_SESSION['rural_urban_value'];
  }
    $form = array();
    //$data = labour_load($edit_sch,arg(1));

     $qry = db_select($edit_sch.'.individual_'.$state,'fm')
        ->fields('fm',array('house_hold_id'))
        ->condition('ahl_tin',arg(1))
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
      $photo = $data['photograph'];

     $form[$i]['div'] = array(
         '#type' => 'item',
        '#prefix' => '<div class="startdiv">',

    );
   $form[$i]['full_name'] = array(
         '#type' => 'item',
        '#markup' => '<strong> Full Name :</strong> '.$data['name'].'',    
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

$form[$i]['uwgender'] = array(
    '#type' => 'item',
    '#markup' => '<strong>Gender :</strong> '.$data['genderid'].'',     
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
    '#markup' => t('1. I wish to apply for registration as unorganized worker per the provisions of Section 10(3) of the Unorganized Workers’ Social Security Act 2008 and issuance of Mahatma Phule National Social Security (MPNSS) Card.'),
    
    );

    $form[$i]['further_declare'] = array(
    '#type' => 'item',
    '#markup' => t('2.  Further, I hereby declare that-<br>
                        <span style="margin: 0px 0px 0px 17px;"> a) I am an Indian Citizen</span> <br>
                        <span style="margin: 0px 0px 0px 17px;"> b) I am an unorganized worker</span><br>
                        <span style="margin: 0px 0px 0px 17px;"> c) I am NOT a member of Employee Provident Fund Organization (EPFO) or Employee State Insurance Corporation (ESIC)</span><br>
                        <span style="margin: 0px 0px 0px 17px;"> d) my average income per month is less than Rs. 10,000 per month and</span><br>
                       <span style="margin: 0px 0px 0px 17px;">  e) I am above 18 years of age.</span>
'),
    );


       $form[$i]['further_declare'] = array(
    '#type' => 'item',
    '#markup' => t('3.  I hereby authorize the appropriate Authorities to utilize and store my Aadhar details, including my biometric information and photograph in the MPNSS Card. '),
    
    );
      $form[$i]['authorize_ministry'] = array(
    '#type' => 'item',
    '#markup' => t('4. I also authorize Ministry of Labour and employment to share this information with the Ministries / Departments operating Social Security Schemes '),
    
    );
        $form[$i]['furnishing'] = array(
    '#type' => 'item',
    '#markup' => t('5.  I am not having/furnishing my Aadhar number  '),
    
    );
 //echo $photo;
if(!empty($photo)){

 $form[$i]['rs30'] = array(
    '#type' => 'item',
    '#markup' => t('6. I am furnishing Rs 30/- for the registration and MPNSS card. '),
    
  );

  $form[$i]['declare'] = array(
    '#type' => 'item',
    '#markup' => t('7. I have provided all the information here true to the best of my knowledge'),
    
  );
}
else{
    $form[$i]['dveclare'] = array(
    '#type' => 'item',
    '#markup' => t('6. I have provided all the information here true to the best of my knowledge'),
    
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
    return $form;

}

