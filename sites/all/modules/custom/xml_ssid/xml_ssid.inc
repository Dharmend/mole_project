<?php

define('iv', '741952hheeyy66#cs!9hjv887mxx7@8y');
define('ky', 'lkirwf897+22#bbtrm8814z5qq=498j5');

function XML_encryptRJ256($key,$iv,$string_to_encrypt){
    $rtn = mcrypt_encrypt(MCRYPT_RIJNDAEL_256, $key, $string_to_encrypt, MCRYPT_MODE_CBC, $iv);
    $rtn = base64_encode($rtn);
    return($rtn);
}


function validate_all_schema($data){
    
    
//        //validate schema of all the args
//        if(strlen(trim($data['agency_acronyms'])) == '10'){
//        
//        }else{
//            return services_error('Agency Acronyms is not Valid',5001,'');
//        }
//        // validate reference number
//        if(strlen(trim($data['reference_number'])) == '12'){
//        
//        }else{
//            return services_error('Reference Number is not Valid',5001,'');
//        }
//        // validate reference date
//        if(strlen(trim($data['reference_date'])) == '14'){
//        
//        }else{
//            return services_error('Reference Date is not Valid',5001,'');
//        }
    
}

function get_batch_list($data){
    //print_r($data);
    $error_code = 1001;
    $error_msg = 'Success';
// Valiadte agency acronyms
    $agency_acr = $data['Identifier_Acronym'];
    $ref_param = $data['Reference_Parameter'];
    $ia_csn = $data['IA_CSN'];
    $ip_address = $data['IP_Address'];
    
    if(!isset($agency_acr)){
            $error_code = 8000;
            $error_msg = 'Identifier Acronym Does not find';
            save_batch_log($agency_acr, $ip_address, $error_code, $error_msg, $ref_param, $ia_csn);
            return services_error($error_msg, 8000, '');
    }
    if(!isset($ref_param)){
            $error_code = 8000;
            $error_msg = 'Reference Parameter Does not find';
            save_batch_log($agency_acr, $ip_address, $error_code, $error_msg, $ref_param, $ia_csn);
            return services_error($error_msg, 8000, '');
    }
    if(!isset($ip_address)){
            $error_code = 8000;
            $error_msg = 'IP Address does not Find';
            save_batch_log($agency_acr, $ip_address, $error_code, $error_msg, $ref_param, $ia_csn);
            return services_error($error_msg, 8000,'');
    }
    if(!isset($ia_csn)){
            $error_code = 8000;
            $error_msg = 'IA CSN does not Find';
            save_batch_log($agency_acr, $ip_address, $error_code, $error_msg, $ref_param, $ia_csn);
            return services_error($error_msg, 8000,'');
    }
//Check extra arguments    
    if(count($data) > 4){
            $error_code = 8001;
            $error_msg = 'Extra Invalid Parameter Found';
            return services_error($error_msg, 8001,'');
        }
    
//Valiadte data
        if(strlen($agency_acr) != '3'){
            $error_code = 7000;
            $error_msg = 'Agency Acronyms is not valid, Should be 3 character only';
            save_batch_log($agency_acr, $ip_address, $error_code, $error_msg, $ref_param, $ia_csn);
            return services_error($error_msg, 7000, '');
        }
        if(strlen($ref_param) > 12){
            $error_code = 7000;
            $error_msg = 'Reference Parameters is not valid, Should not be more than 12 character';
            save_batch_log($agency_acr, $ip_address, $error_code, $error_msg, $ref_param, $ia_csn);
            return services_error($error_msg, 7000, '');
        }
        if(strlen($ia_csn) > '100'){
            $error_code = 7000;
            $error_msg = 'IA CSN is not valid, Should not be more than 100 Characters';
            save_batch_log($agency_acr, $ip_address, $error_code, $error_msg, $ref_param, $ia_csn);
            return services_error($error_msg, 7000, '');
        }
//        if(strlen($ip_address) > '100'){
//            $error_code = 7000;
//            $error_msg = 'IA CSN is not valid, Should not be more than 100 Characters';
//            return services_error($error_msg, 7000, '');
//        }
        
//Get the agency name and state and district values
//        $qry = db_select('field_data_field_username','fd');
//        $qry->fields('fd',array('entity_id'));
//        $qry->condition('fd.field_username_value',$agency_acr);
//        $qry->condition('fd.bundle','card_printing_agency');
//        $qry->condition('fd.deleted','0');
//        $qry->condition('fd.entity_type','node');
//        $result = $qry->execute()->fetchField();
    
    $db_qry = db_select('card_created_record','c')
               ->fields('c',array('state','district'))
               ->condition('c.csn_no',$ia_csn)
               ->execute();
    
    $state_exit = $db_qry->rowCount();
    $csn_state = array();
    $csn_district = array();
    
    foreach ($db_qry as $val){
        $csn_state[] = $val->state;
        $csn_district[] = $val->district;     
    }
    
    $uniq_sta = array_unique($csn_state);
    $uniq_dis = array_unique($csn_district);

        
// Process Request Validation
                  
           if($state_exit < 1){
               $error_code = 3000;
               $error_msg = 'IA CSN not found in Database';
               save_batch_log($agency_acr, $ip_address, $error_code, $error_msg, $ref_param, $ia_csn);
               return services_error($error_msg, 3000, '');
           }

//get the available batches for it        
        $res = db_select('ssid_generated_data.uwssid_temp','gb');
               $res->groupBy('gb.ssid_batch');
               $res->addExpression('count(ssid_batch)','total_records');
               $res->havingCondition('gb.statecode', $uniq_sta,'IN');
               $res->havingCondition('gb.districtcode',$uniq_dis,'IN');
               $res->groupBy('gb.statecode');
               $res->groupBy('gb.districtcode');
               $res->groupBy('gb.tehsilcode');
               $res->groupBy('gb.towncode');
               $res->fields('gb',array('ssid_batch','statecode','districtcode','tehsilcode','towncode'));
               
               $result = $res->execute();
               $total_batch = $result->rowCount();
               
               if($total_batch < 1){
                   
                    $error_code = 3000;
                    $error_msg = 'Batches are not available on these state and districts';
                    save_batch_log($agency_acr, $ip_address, $error_code, $error_msg, $ref_param, $ia_csn);
                    return services_error($error_msg, 3000, '');
               }
        
       $agency_detail = array();
       
       
       foreach ($result as $data){
           
            $ky = 'lkirwf897+22#bbtrm8814z5qq=498j5';
            $iv = '741952hheeyy66#cs!9hjv887mxx7@8y';
  
//           $agency_detail['batch_id'] = trim(XML_encryptRJ256($ky, $iv, trim($data->ssid_batch)));
//           $agency_detail['batch_total_record'] = trim(XML_encryptRJ256($ky, $iv, trim($data->total_records)));
//           
//           $state_name = _get_location('state');
//           $agency_detail['state'] = trim(XML_encryptRJ256($ky, $iv, trim($state_name[$data->statecode])));
//           
//           $district_name = _get_location('district',$data->statecode);
//           $agency_detail['district'] = trim(XML_encryptRJ256($ky, $iv, trim($district_name[$data->districtcode])));
//           
//           $tehsil_name = _get_location('tehsil',$data->statecode, $data->districtcode);
//           $agency_detail['tehsil'] = trim(XML_encryptRJ256($ky, $iv, trim($tehsil_name[$data->tehsilcode])));
//           
//           $village_name = _get_location('village',$data->statecode, $data->districtcode, $data->tehsilcode);
//           $agency_detail['village'] =  trim(XML_encryptRJ256($ky, $iv, trim($village_name[$data->towncode])));
//           $all_batches[] = $agency_detail;
           
           
           $agency_detail['batch_id'] = $data->ssid_batch;
           $agency_detail['batch_total_record'] = $data->total_records;
           
           $state_name = _get_location('state');
           $agency_detail['state'] = $state_name[$data->statecode];
           
           $district_name = _get_location('district',$data->statecode);
           $agency_detail['district'] = $district_name[$data->districtcode];
           
           $tehsil_name = _get_location('tehsil',$data->statecode, $data->districtcode);
           $agency_detail['tehsil'] = $tehsil_name[$data->tehsilcode];
           
           $village_name = _get_location('village',$data->statecode, $data->districtcode, $data->tehsilcode);
           $agency_detail['village'] =  $village_name[$data->towncode];
           $all_batches[] = $agency_detail;
           
           
       }
       
               
        $msg = 'Success';
        $error_code = 200;
       
//Save success log 
         save_batch_log($agency_acr,$ip_address,$error_code,$error_msg,$ref_param,$ia_csn);
        
         $resl = array('identifier_acronyms' => $agency_acr,'reference_param' => $ref_param,'ia_csn' => $ia_csn,'ip_address' => $ip_address,'total_count' => $total_batch,'batch_list' => $all_batches);
         return services_error($msg, $error_code, $resl);
    
}



function agency_detail_data($data){
        $error_code = 1001;
        $error_msg = 'Success';
        // Valiadte agency acronyms
        
        $agency_acr = $data['Identifier_Acronym'];
        $ip_address = $data['IP_Address'];
        //print_r($data);
        // Validate Schema
        if(!isset($agency_acr)){
            $error_code = 8000;
            $error_msg = 'Identifier Acronym Does not find';
            return services_error($error_msg, 8000, '');
        }
        if(!isset($ip_address)){
            $error_code = 8000;
            $error_msg = 'IP Address does not Find';
            return services_error($error_msg, 8000,'');
        }
        if(count($data) > 2){
            $error_code = 8001;
            $error_msg = 'Extra Invalid Parameter Found';
            return services_error($error_msg, 8001,'');
        }
        
        //Valiadte data
        if(strlen($agency_acr) != '3'){
            $error_code = 7000;
            $error_msg = 'Agency Acronyms is not valid, Should be 3 character only';
            return services_error($error_msg, 7000, '');
        }
        
        
        
        $qry = db_select('field_data_field_username','fd');
        $qry->fields('fd',array('entity_id'));
        $qry->condition('fd.field_username_value',$agency_acr);
        $qry->condition('fd.bundle','card_printing_agency');
        $qry->condition('fd.deleted','0');
        $qry->condition('fd.entity_type','node');
        $result = $qry->execute()->fetchField();
        
        if(empty($result)){
               
               $error_code = 3000;
               $error_msg = 'Acronyms Not Found in database.';
               return services_error($error_msg, 3000, '');
        }
                
        $records = node_load($result);
        
        $ky = 'lkirwf897+22#bbtrm8814z5qq=498j5';
        $iv = '741952hheeyy66#cs!9hjv887mxx7@8y';
  
        //$agency_detail['batch_id'] = trim(XML_encryptRJ256($ky, $iv, trim($data->ssid_batch)));
           
        $agency_detail = array();
        //print_r($records);
           
                  $agency_detail['agency_id'] = isset($records->nid) ? $records->nid : '';
                  $agency_detail['agency_name'] = isset($records->title) ? $records->title : '';
                  $agency_detail['agency_acronym'] = isset($records->field_username['und'][0]['value']) ? $records->field_username['und'][0]['value'] : '';
                  $agency_detail['addressline1'] = isset($records->field_address_1['und'][0]['value']) ? $records->field_address_1['und'][0]['value'] : '';
                  $agency_detail['addressline2'] =  isset($records->field_office_address_2['und'][0]['value']) ? $records->field_office_address_2['und'][0]['value'] : '';
                  $agency_detail['district'] = district_name($records->field_district_agency['und'][0]['value']) ? district_name($records->field_district_agency['und'][0]['value']) : '';
                  $agency_detail['state'] = state_name($records->field_state_agency['und'][0]['value']) ? state_name($records->field_state_agency['und'][0]['value']) : '';
                  $agency_detail['pincode'] = isset($records->field_pincode['und'][0]['value']) ? $records->field_pincode['und'][0]['value'] : '';
                  
                  $agency_detail['Contact_Person_name'] = isset($records->field_contact_person['und'][0]['value']) ? $records->field_contact_person['und'][0]['value'] : '';
                  $agency_detail['contact_person_email'] = isset($records->field_contact_email['und'][0]['email']) ? $records->field_contact_email['und'][0]['email'] : '';
                  $agency_detail['contact_person_telephone'] = isset($records->field_office_address_1['und'][0]['value']) ? $records->field_office_address_1['und'][0]['value'] : '';
     
//                    $agency_detail['agency_id'] = trim(XML_encryptRJ256($ky, $iv, trim($records->nid)));
//                    $agency_detail['agency_name'] = trim(XML_encryptRJ256($ky, $iv, trim($records->title)));
//                    $agency_detail['agency_acronym'] = trim(XML_encryptRJ256($ky, $iv, trim($records->field_username['und'][0]['value'])));
//                    $agency_detail['addressline1'] = trim(XML_encryptRJ256($ky, $iv, trim($records->field_address_1['und'][0]['value'])));
//                    $agency_detail['addressline2'] =  trim(XML_encryptRJ256($ky, $iv, trim($records->field_office_address_2['und'][0]['value'])));
//                    $agency_detail['district'] = trim(XML_encryptRJ256($ky, $iv, trim(district_name($records->field_district_agency['und'][0]['value']))));
//                    $agency_detail['state'] = trim(XML_encryptRJ256($ky, $iv, trim(state_name($records->field_state_agency['und'][0]['value']))));
//                    $agency_detail['pincode'] = trim(XML_encryptRJ256($ky, $iv, trim($records->field_pincode['und'][0]['value'])));
//
//                    $agency_detail['Contact_Person_name'] = trim(XML_encryptRJ256($ky, $iv, trim($records->field_contact_person['und'][0]['value'])));
//                    $agency_detail['contact_person_email'] = trim(XML_encryptRJ256($ky, $iv, trim($records->field_contact_email['und'][0]['email'])));
//                    $agency_detail['contact_person_telephone'] = trim(XML_encryptRJ256($ky, $iv, trim($records->field_office_address_1['und'][0]['value'])));
//        
        // Process Request Validation
         
                  
           if(!is_numeric($result)){
               $error_code = 3000;
               $error_msg = 'Agency Detail Does not Found';
               return services_error($error_msg, 3000, '');
           }       
                  
                  
        // Save log Details
         
                $data_insert = db_insert('activity.web_services_log')
                       ->fields(array(
                           'agency_acronyms' => isset($agency_acr) ? $agency_acr : '',
                           'ip' => isset($ip_address) ? $ip_address : '',
                           'ws_name' => 'agency/getagencydetail.xml',
                           'error_code' => $error_code,
                           'error_message' => $error_msg,
                       ))
                ->execute();
        //count($records);
        
        
        $msg = '';
        $res = array('identifier_acronyms' => $agency_acr,'ip_address' => $ip_address,'total_count' => '1','agency_details' => $agency_detail);
        return services_error($msg, 200, $res);
   
}


function get_record_list($data){
    
    $error_code = 1001;
    $error_msg = 'Success';
// Valiadte agency acronyms
    $agency_acr = $data['Identifier_Acronym'];
    $ref_param = $data['Reference_Parameter'];
    $batch_id = $data['Batch_Id'];
    $ip_address = $data['IP_Address'];
    
    if(!isset($agency_acr)){
            $error_code = 8000;
            $error_msg = 'Identifier Acronym Does not find';
            save_batch_log($agency_acr, $ip_address, $error_code, $error_msg, $ref_param, $ia_csn);
            return services_error($error_msg, 8000, '');
    }
    if(!isset($ref_param)){
            $error_code = 8000;
            $error_msg = 'Reference Parameter Does not find';
            save_batch_log($agency_acr, $ip_address, $error_code, $error_msg, $ref_param, $ia_csn);
            return services_error($error_msg, 8000, '');
    }
    if(!isset($ip_address)){
            $error_code = 8000;
            $error_msg = 'IP Address does not Find';
            save_batch_log($agency_acr, $ip_address, $error_code, $error_msg, $ref_param, $ia_csn);
            return services_error($error_msg, 8000,'');
    }
    if(!isset($batch_id)){
            $error_code = 8000;
            $error_msg = 'Batch Id does not Find';
            save_batch_log($agency_acr, $ip_address, $error_code, $error_msg, $ref_param, $ia_csn);
            return services_error($error_msg, 8000,'');
    }
// Check All the arguments of the array    
    if(count($data) > 4){
            $error_code = 8001;
            $error_msg = 'Extra Invalid Parameter Found';
            return services_error($error_msg, 8001,'');
        }
    
//Valiadte data
        if(strlen($agency_acr) != '3'){
            $error_code = 7000;
            $error_msg = 'Agency Acronyms is not valid, Should be 3 character only';
            save_batch_log($agency_acr, $ip_address, $error_code, $error_msg, $ref_param, $ia_csn);
            return services_error($error_msg, 7000, '');
        }
        if(strlen($ref_param) > 12){
            $error_code = 7000;
            $error_msg = 'Reference Parameters is not valid, Should not be more than 12 character';
            return services_error($error_msg, 7000, '');
            save_batch_log($agency_acr, $ip_address, $error_code, $error_msg, $ref_param, $ia_csn);
            
        }
        if(strlen($batch_id) > 26){
            $error_code = 7000;
            $error_msg = 'Batch id is not valid, Should not be more than 26 Characters';
            save_batch_log($agency_acr, $ip_address, $error_code, $error_msg, $ref_param, $ia_csn);
            return services_error($error_msg, 7000, '');
        }
        
//Write query to fetch the appropriate records
        $get_famly = db_select('ssid_generated_data.uwssid_temp', "f");
        $get_famly->fields('f',array('house_hold_id'));
        $get_famly->groupBy('f.house_hold_id');
        $get_famly->groupBy('f.ssid_batch');
        //$get_famly->groupBy('f.card_issue');
        //$get_famly->havingCondition('f.house_hold_id','320900200010000000100006');
        $get_famly->havingCondition('f.ssid_batch',$batch_id);
        //$get_famly->havingCondition('f.card_issue',1);
        $city_qry = $get_famly->execute();
        
        $total_house_hold = $city_qry->rowCount();

        
        $card_facia = array();
        $chip_data = array();
        $hsl = array();
        $msl = array();
        $lsl = array();
        $family = array();
        $total_card_despatched = array();
        
        
    $ky = 'lkirwf897+22#bbtrm8814z5qq=498j5';
    $iv = '741952hheeyy66#cs!9hjv887mxx7@8y';
        
        if($total_house_hold >0){
                foreach ($city_qry as $house_id){
                        $query = db_select("ssid_generated_data.uwssid_temp", "n");
                                $query->fields('n');
                                $query->condition('n.house_hold_id',$house_id->house_hold_id);
                                $query->condition('n.card_issue',1);
                                //$query->condition('n.','320900200010000000100006');
                                //$query->range(0,1);
                                $fnl_record = $query->execute();
                                $total_card_despatched[] = $fnl_record->rowCount();
                                //if($fnl_record->rowCount() > 0){
                                
                                foreach ($fnl_record as $qry){
                                    
                                //limit name     
                                    if(strlen($qry->name) > 75){
                                        $name_en = substr($qry->name, 0, 75);
                                        }else{
                                            $name_en = $qry->name;
                                        }
                                //limit namesl
                                        if(strlen($qry->name_sl) > 75){
                                            $name_sl = substr($qry->name_sl, 75);
                                        }else{
                                            $name_sl = $qry->name_sl;
                                        }
                                //limit mother name
                                        if(strlen($qry->mothername_uwssp) > 75){
                                            $mother_name = substr($qry->mothername_uwssp, 75);
                                        }else{
                                            $mother_name = $qry->mothername_uwssp;
                                        }
                                        
                                        
                                //For card facia
                                        $card_facia['Name_en'] = isset($name_en) ? $name_en : '';
                                        $card_facia['Name_vl'] = isset($name_sl) ? $name_sl : '';
                                        $card_facia['Gender'] = $qry->genderid;//get_gender($qry->genderid)
                                        $card_facia['DOB'] = format_custom_date($qry->dob);
                                        $card_facia['Mother Name'] =  isset($mother_name) ? $mother_name : '';
                                        $card_facia['ssid'] = isset($qry->ssid) ? $qry->ssid : '';
                                        $card_facia['ahl_tin'] = isset($qry->ahl_tin) ? $qry->ahl_tin : '';
                                        $card_facia['image'] = isset($qry->photograph) ? $qry->photograph : '';
                                        
//                                        $card_facia['Name_en'] = trim(XML_encryptRJ256($ky, $iv, trim($name_en)));
//                                        $card_facia['Name_vl'] = trim(XML_encryptRJ256($ky, $iv, trim($name_sl)));
//                                        $card_facia['Gender'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->genderid)));//get_gender($qry->genderid)
//                                        $card_facia['DOB'] = trim(XML_encryptRJ256($ky, $iv, trim(format_custom_date($qry->dob))));
//                                        $card_facia['Mother_name'] =  trim(XML_encryptRJ256($ky, $iv, trim($mother_name)));
//                                        $card_facia['ssid'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->ssid)));
//                                        $card_facia['ahl_tin'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->ahl_tin)));
//                                        $card_facia['image'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->photograph)));
                                        
                                        
                                // For Chip of card data
                                        $chip_data['version'] = '1'; 
                                        $chip_data['Name_en'] = isset($name_en) ? $name_en : '';
                                        $chip_data['Name_vl'] = isset($name_sl) ? $name_sl : '';
                                        $chip_data['Gender'] = strtoupper(substr(get_gender($qry->genderid),0,1));
                                        $chip_data['DOB'] = format_custom_date($qry->dob);
                                        $chip_data['Mother Name'] = isset($mother_name) ? $mother_name : '';
                                        $chip_data['ssid'] = isset($qry->ssid) ? $qry->ssid : '';
                                        $chip_data['ahl_tin'] = isset($qry->ahl_tin) ? $qry->ahl_tin : '';
                                        $chip_data['image'] = isset($qry->photograph) ? $qry->photograph : '';
                                        
//                                        $chip_data['version'] = trim(XML_encryptRJ256($ky, $iv, trim('1'))); 
//                                        $chip_data['Name_en'] = trim(XML_encryptRJ256($ky, $iv, trim($name_en)));
//                                        $chip_data['Name_vl'] = trim(XML_encryptRJ256($ky, $iv, trim($name_sl)));
//                                        $chip_data['Gender'] = trim(XML_encryptRJ256($ky, $iv, trim(strtoupper(substr(get_gender($qry->genderid),0,1)))));
//                                        $chip_data['DOB'] = trim(XML_encryptRJ256($ky, $iv, trim(format_custom_date($qry->dob))));
//                                        $chip_data['Mother Name'] = trim(XML_encryptRJ256($ky, $iv, trim($mother_name)));
//                                        $chip_data['ssid'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->ssid)));
//                                        $chip_data['ahl_tin'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->ahl_tin)));
//                                        $chip_data['image'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->photograph)));
                                        
                                
                                //for High Security lavel         
                                        $auth_csn = card_created_record($qry->statecode, $qry->districtcode);
                                        
                                        $hsl['version'] = '1'; 
                                        $hsl['Aadhar'] = isset($qry->aadhaar) ? $qry->aadhaar : '';
                                        $hsl['IAuthCSN'] = isset($qry->aadhaar) ? $qry->aadhaar : '';
                                        
//                                        $hsl['version'] = trim(XML_encryptRJ256($ky, $iv, trim('1'))); 
//                                        $hsl['Aadhar'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->aadhaar)));
//                                        $hsl['IAuthCSN'] = trim(XML_encryptRJ256($ky, $iv, trim($auth_csn)));
                                
                                //For middle sequrity label 
                                       
                                        $msl['version'] = '1';
                                        $msl['HOF'] = isset($qry->hof) ? $qry->hof : '';
                                        $msl['current_address1'] = isset($qry->c_address1) ? $qry->c_address1 : '';
                                        $msl['current_address2'] = isset($qry->c_address2) ? $qry->c_address2 : '';
                                        $msl['current_villagetown'] = isset($qry->c_villagetown) ? $qry->c_villagetown : '';
                                        $msl['current_district'] = isset($qry->c_district) ? $qry->c_district : '';
                                        $msl['current_state'] = isset($qry->c_state) ? $qry->c_state : '';
                                        $msl['current_pincode'] = isset($qry->c_pincode) ? $qry->c_pincode : '';
                                        $msl['DOB'] = actual_self($qry->actual_self_decleration);
                                        $msl['account_no'] = isset($qry->bank_account_no) ? $qry->bank_account_no : '';
                                        $msl['ifsc'] = isset($qry->ifsc) ? $qry->ifsc : ''; 
                                        
//                                        $msl['version'] = trim(XML_encryptRJ256($ky, $iv, trim('1')));
//                                        $msl['HOF'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->hof)));
//                                        $msl['current_address1'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->c_address1)));
//                                        $msl['current_address2'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->c_address2)));
//                                        $msl['current_villagetown'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->c_villagetown)));
//                                        $msl['current_district'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->c_district)));
//                                        $msl['current_state'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->c_state)));
//                                        $msl['current_pincode'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->c_pincode)));
//                                        $msl['DOB'] = trim(XML_encryptRJ256($ky, $iv, trim(actual_self($qry->actual_self_decleration))));
//                                        $msl['account_no'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->bank_account_no)));
//                                        $msl['ifsc'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->ifsc))); 
                                        

                                    //For Low security labels
                                    if(strlen($qry->fathername_uwssp) > 75){
                                        $fname_uwssp = substr($qry->fathername_uwssp, 0, 75);
                                        }else{
                                        $fname_uwssp = $qry->fathername_uwssp;
                                        }
                                        
                                        $lsl['version'] = '1';
                                        $lsl['Father Name'] = isset($fname_uwssp) ? $fname_uwssp : '';
                                        $lsl['Marrital Status'] = $qry->mstatusid;
                                        $lsl['mobile_no'] = isset($qry->mobile) ? $qry->mobile : '';
                                        $lsl['occupation'] = isset($qry->occupation) ? $qry->occupation : '';
                                        $lsl['education'] = get_education($qry->educode);
                                        $lsl['income'] = isset($qry->income) ? $qry->income : '';
                                        
//                                        $lsl['version'] = trim(XML_encryptRJ256($ky, $iv, trim('1')));
//                                        $lsl['Father Name'] = trim(XML_encryptRJ256($ky, $iv, trim($fname_uwssp)));
//                                        $lsl['Marrital Status'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->mstatusid)));
//                                        $lsl['mobile_no'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->mobile)));
//                                        $lsl['occupation'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->occupation)));
//                                        $lsl['education'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->educode)));//get_education($qry->educode)
//                                        $lsl['income'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->income)));
                                        
                                        
                                        
                                    //For family Details    
                                        $family['version'] = '1';
                                        $family['house_hold_id'] = $qry->house_hold_id;
                                        
//                                        $family['version'] = trim(XML_encryptRJ256($ky, $iv, trim('1')));
//                                        $family['house_hold_id'] = trim(XML_encryptRJ256($ky, $iv, trim($qry->house_hold_id)));
                                        
                                        $get_famly = db_select('ssid_generated_data.uwssid_temp', "f");
                                        $get_famly->fields('f',array('name','relation_uwssp','genderid','dob','ssid','aadhaar','ahl_tin'));
                                        $get_famly->condition('f.house_hold_id',$qry->house_hold_id);
                                        $get_famly->condition('f.card_issue',0);
                                        $family_array = $get_famly->execute();
                                        //print_r($family_array);
                                        $my_family = array();
                                        foreach ($family_array as $fm){
                                            
                                            
                                            $my_family['name'] = $fm->name;
                                            $my_family['relation_with_hof'] = $fm->relation_uwssp;
                                            $my_family['gender'] = get_gender($fm->genderid);
                                            $my_family['DOB'] = format_custom_date($fm->dob);
                                            $my_family['SSID'] = $fm->ssid;
                                            $my_family['aadhar-id'] = $fm->aadhaar;
                                            $my_family['aht_tin'] = $fm->ahl_tin;
                                            
//                                            $my_family['name'] = trim(XML_encryptRJ256($ky, $iv, trim($fm->name)));
//                                            $my_family['relation_with_hof'] = trim(XML_encryptRJ256($ky, $iv, trim($fm->relation_uwssp)));
//                                            $my_family['gender'] = trim(XML_encryptRJ256($ky, $iv, trim($fm->genderid)));
//                                            $my_family['DOB'] = trim(XML_encryptRJ256($ky, $iv, trim(format_custom_date($fm->dob))));
//                                            $my_family['SSID'] = trim(XML_encryptRJ256($ky, $iv, trim(format_custom_date($fm->ssid))));
//                                            $my_family['aadhar-id'] = trim(XML_encryptRJ256($ky, $iv, trim(format_custom_date($fm->aadhaar))));
//                                            $my_family['aht_tin'] = trim(XML_encryptRJ256($ky, $iv, trim(format_custom_date($fm->ahl_tin))));

                                            $new_array[] = $my_family;  
                                        }
                                        $family['family_details'] = $new_array;
                                        unset($new_array);
                                        
                                        $allcity_list['card-facia'] = $card_facia;
                                        $allcity_list['chip-data'] = $chip_data;
                                        $allcity_list['hsl'] = $hsl;
                                        $allcity_list['msl'] = $msl;
                                        $allcity_list['lsl'] = $lsl;
                                        $allcity_list['family'] = $family;
                                        $new_list[] = $allcity_list;
                                }
                                
                        //}    
                }

                $msg = '';
                $res = array('identifier_acronyms' => $data['Identifier_Acronym'],'Reference_Parameter' => $ref_param,'Batch_id' => $batch_id,'ip_address' => $data['IP_Address'], 'total_count' => $total_house_hold,'record_list' => $new_list);
                return services_error($msg, 1001, $res);
            
        }else{
            
             $error_code = 3000;
             $error_msg = 'No data Found on this batch';
             save_record_log($agency_acr, $ip_address, $error_code, $error_msg, $ref_param, $batch_id);
             return services_error($error_msg, 3000, '');
            
        }
    
}


function format_custom_date($rep_date){
                $dob_array = explode('-', $rep_date);
                //print_r($dob_array);
                $dob_day = $dob_array[2] != '00' ? $dob_array[2] : 'XX';
                $dob_month = $dob_array[1] != '00' ? $dob_array[1] : 'XX';
                $dob_year = $dob_array[0] != '0000' ? $dob_array[0] : 'XXXX';
                $dob = $dob_day.'/'.$dob_month.'/'.$dob_year;
                
                return $dob;
 }
                
                
 
function card_created_record($state,$dist){
    
    $qry = db_select('card_created_record','cr')
        ->fields('cr')
        ->condition('cr.state',$state)
        ->condition('cr.district',$dist)    
        ->execute()->fetchAssoc();

    return $qry['csn_no'];
    
}

function save_batch_log($agency_acr,$ip_address,$error_code,$error_msg,$ref_param,$ia_csn){
    
                    $data_insert = db_insert('activity.web_services_log')
                       ->fields(array(
                           'agency_acronyms' => isset($agency_acr) ? $agency_acr : '',
                           'ip' => isset($ip_address) ? $ip_address : '',
                           'ws_name' => 'batches/getbatchlist.xml',
                           'error_code' => $error_code,
                           'error_message' => $error_msg,
                           'reference_parameter' => (strlen($ref_param) <= 12) ?  $ref_param : '',
                           'ia_csn' => $ia_csn,
                       ))
                ->execute();
}

function save_record_log($agency_acr,$ip_address,$error_code,$error_msg,$ref_param,$batch_id){
                    $data_insert = db_insert('activity.web_services_log')
                       ->fields(array(
                           'agency_acronyms' => isset($agency_acr) ? $agency_acr : '',
                           'ip' => isset($ip_address) ? $ip_address : '',
                           'ws_name' => 'batches/getbatchlist.xml',
                           'error_code' => $error_code,
                           'error_message' => $error_msg,
                           'reference_parameter' => $ref_param,
                           'batch_id' => $batch_id,
                       ))
                ->execute();
}

function actual_self($code){
//    $declared = array('1' => 'A','2' => 'D');
//    $code_msg = $declared[$code];
    $code_msg = '';
    
    if($code == '1'){
        $code_msg = 'A';
    }elseif ($code == '2') {
        $code_msg = 'D';
    }
    
    return $code_msg;
}