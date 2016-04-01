<?php
//Function for getting the node details & adding it to CSV variable.
function get_village_persons($house_hold_id){

  $dow_state = $_SESSION['dow_state_value'];
  $dow_district = $_SESSION['dow_district_value'];
  $dow_tehsil = $_SESSION['dow_tehsil_value'];
  $dow_village = $_SESSION['dow_village_value'];
  $csv_output = '';
  $dow_rural_urban = $_SESSION['dow_rural_urban'];

  $fst = $_SESSION['secc_uw_data'];
  $tbl_state = $_SESSION['dow_state_value'];
  
  $sec = $dow_rural_urban;

  if(($dow_rural_urban != '') && ($fst !='')){

                 $tbl = $fst.''.$sec;
                try{
                        $query = db_select($tbl.".individual_".$tbl_state, "n");
                        $query->fields('n');
                        //$query->condition('n.house_hold_id',db_like($house_hold_id) . '%', 'LIKE');
                        //$query->addExpression('SUBSTRING(house_hold_id,1,11)',$house_hold_id);
                     //   $query->where('substr(house_hold_id,1,11) = :hid',array(':hid' => $house_hold_id));
                        $query->condition('n.statecode', $dow_state, '=');
                         $query->condition('n.districtcode', $dow_district, '=');
                         $query->condition('n.tehsilcode', $dow_tehsil, '=');
                         $query->condition('n.towncode', $dow_village, '=');
                        //$query->orderBy('n.house_hold_id','ASC');
                        //$query->orderBy('n.slnomember','ASC');
                        $result = $query->execute();
                } catch (Exception $ex) {
                        watchdog('State Table not found', 'error message');
                }
                
                
                //$md = md5($house_hold_id);
                foreach($result as $r){
                 
                  //$csv_output .= "\n";
                $md = md5($gen_ekey = $r->house_hold_id.''.$r->name.''.$r->ahl_tin.''.$r->slnomember.''.$r->genderid.''.$r->fathername.$r->yob);
$csv_output .= $r->house_hold_id.",".$r->tin_npr.",".$r->slnomember.",".$r->ahltypeofeb.",".$r->livinginshelter.",".$r->hhd_sectwocodes.",".$r->hhd_landownedcodes.",".$r->totalirrigated.",".$r->totalunirrigated.",".$r->otherirrigated.",".$r->name.",".$r->name_sl.",".$r->relation.",".$r->genderid.",".$r->dob.",".$r->mstatusid.",".$r->fathername.",".$r->mothername.",".$r->occupation.",".$r->educode.",".$r->education_other.",".$r->incomesource_urban.",".$r->wages_urban.",".$r->disabilitycode.",".$r->hhd_housingcodes.",".$r->hhd_otherassetscodes.",".$r->hhd_employmentcodes.",".$r->ahl_tin.",".$r->member_status.",".$r->age.",".$r->yob.",".$r->hof.",".$r->e_id.",".$r->aadhaar.",".$r->bank_account_no.",".$r->bank_name.",".$r->bank_branch.",".$r->primary_occupation_code.",".$r->secondary_occupation_code.",".$r->p_address1.",".$r->p_address2.",".$r->p_villagetown.",".$r->p_district.",".$r->p_tehsil.",".$r->p_state.",".$r->p_pincode.",".$r->c_address1.",".$r->c_address2.",".$r->c_villagetown.",".$r->c_district.",".$r->c_tehsil.",".$r->c_state.",".$r->c_pincode.",".$r->aadhaar_yesno.",".$r->beggars_dw_sv_hbw_adwi_wages.",".$r->construction_pl_sw_tw_sw.",".$r->lessthan_10000.",".$r->landlessthan_4acres.",".$r->house_based.",".$md.",".$r->uw_record;
                  $csv_output .= "\r\n";
                } 
  
  }
  return $csv_output;
}
//Called function from .module file for downloading CSV.
function village_data_download(){
  $house_hold_id = arg(1);  
  module_load_include('inc', 'data_download');
  $csv_output = '';
  $csv_output .= 'house_hold_id, tin_npr,slnomember,ahltypeofeb,livinginshelter,hhd_sectwocodes,hhd_landownedcodes,totalirrigated,totalunirrigated, otherirrigated, name,name_sl,relation,genderid,dob,mstatusid,fathername,mothername,occupation,educode,education_other,incomesource_urban,wages_urban,disabilitycode,hhd_housingcodes,hhd_otherassetscodes,hhd_employmentcodes,ahl_tin,member_status,age,yob,hof,e_id,aadhaar,bank_account_no,bank_name,bank_branch,primary_occupation_code,secondary_occupation_code,p_address1,p_address2,p_villagetown,p_district,p_tehsil,p_state,p_pincode,c_address1,c_address2,c_villagetown,c_district,c_tehsil,c_state,c_pincode,aadhaar_yesno,beggars_dw_sv_hbw_adwi_wages,construction_pl_sw_tw_sw,lessthan_10000,landlessthan_4acres,house_based,E-key,unorganised_marked_by';  
  $csv_output .= "\r\n";
  $csv_output .= get_village_persons($house_hold_id); 
  $file_name = $house_hold_id.'-'.date('Y-m-d').'-'.date('H-i-s').'.csv';
  //$file_name = 'ajay.csv';
  
  //Save log in log table
  
  save_log($house_hold_id,$file_name);
  
  //save file in folder
        //global $base_url;
        //$save_file_path = '10.21.173.46:8080/trunck/rural-postgres/download/'.$file_name;
      // die();
         // file_put_contents($save_file_path);

        $csv_handler = fopen('download/'.$file_name,'w');
        //fwrite ($csv_handler,$csv_output);
        fputs($csv_handler, $csv_output);
  //end of the file
  header('Content-type: application/vnd.ms-excel');
  header('Content-Disposition: attachment; filename='.$file_name.'');
  //Save log activity
   print $csv_output;
           fclose ($csv_handler);

   exit; 
}

function save_log($house_hold_id,$file_name){
//drupal_set_message('Thanks user to show me..');
//echo 'Storing data in database...';
global $user;    
$state = substr($house_hold_id,0,2);
$district = substr($house_hold_id,2,2);
$tehsil = substr($house_hold_id,4,3);
$village = substr($house_hold_id,7,4);
$download_r_u = isset($_SESSION['dow_rural_urban']) ? $_SESSION['dow_rural_urban'] : '';
if($download_r_u == 'rural'){
    $r_u = r;
}elseif ($download_r_u == 'urban') {
       $r_u = r; 
    }
$current_time = date('Y-m-d H-i-s', time());  
$client_ip = ip_address();
    
$sch = 'activity';

$tbl_state = $_SESSION['dow_state_value'];
$tbl = 'uw_'.$download_r_u;
                $query = db_select($tbl.".individual_".$tbl_state, "n");
                $query->fields('n');
                $query->condition('n.house_hold_id',db_like($house_hold_id) . '%', 'LIKE');
                $query->orderBy('n.house_hold_id','ASC');
                $query->orderBy('n.slnomember','ASC');
                $result = $query->execute();
                $data_count = $result->rowCount();
                

db_insert($sch.".filedownload_log")
        ->fields(array(
        'state_code' => $state,
        'district_code' => $district,
        'tehsil_code' => $tehsil,
        'villagetown_code' => $village,
        'urban_rural' => $r_u,
        'filename' => $file_name,
        //'downloaded_time' => REQUEST_TIME,
        'userid' => $user->uid,
        'ipaddress' => $client_ip,
        'record_count' => $data_count,  
        ))
        ->execute();
    
}
?>