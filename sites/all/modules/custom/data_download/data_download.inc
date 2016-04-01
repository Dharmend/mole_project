<?php

function encryptRJ256($key,$iv,$string_to_encrypt)
{
   $rtn = mcrypt_encrypt(MCRYPT_RIJNDAEL_256, $key, $string_to_encrypt, MCRYPT_MODE_CBC, $iv);
    $rtn = base64_encode($rtn);
   return($rtn);
}


function get_village_persons($house_hold_id){
  
  $limit = explode('-', $_GET['mode']);
  //echo "<pre>";
  $start_limit =$limit[0]-1;
  $end_limit = $limit[1];
  // print_r($limit);
  // die('sss');
 

 $dow_state = $_SESSION['dow_state_value'];
  $dow_district = $_SESSION['dow_district_value'];
  $dow_tehsil = $_SESSION['dow_tehsil_value'];
  $dow_village = $_SESSION['dow_village_value'];


  $csv_output = '';
  $dow_rural_urban = $_SESSION['dow_rural_urban'];

  $fst = $_SESSION['secc_uw_data'];
  $tbl_state = $_SESSION['dow_state_value'];
  
  $sec = $dow_rural_urban;
  
  $ky = 'lkirwf897+22#bbtrm8814z5qq=498j5'; // 32 * 8 = 256 bit key
  $iv = '741952hheeyy66#cs!9hjv887mxx7@8y'; // 32 * 8 = 256 bit iv


  if(($dow_rural_urban != '') && ($fst !='')){

                 $tbl = $fst.''.$sec;
                  //drupal_set_message($tbl.".individual_".$tbl_state);

                 // count data


                 $querycount = db_select($tbl.".individual_".$tbl_state, "n");
                                  $querycount->fields('n');       
                                  $querycount->condition('n.statecode', $dow_state, '=');
                                  $querycount->condition('n.districtcode', $dow_district, '=');
                                  $querycount->condition('n.tehsilcode', $dow_tehsil, '=');
                                  $querycount->condition('n.towncode', $dow_village, '=');
                                   $totaltrecordcount = $querycount->execute()->rowCount(); 

                //try{
                        $query = db_select($tbl.".individual_".$tbl_state, "n");
                        $query->fields('n');
                        //$query->where('substr(house_hold_id,1,11) = :hid',array(':hid' => $house_hold_id));
                          $query->condition('n.statecode', $dow_state, '=');
                         $query->condition('n.districtcode', $dow_district, '=');
                         $query->condition('n.tehsilcode', $dow_tehsil, '=');
                         $query->condition('n.towncode', $dow_village, '=');
                         $query->orderBy('n.house_hold_id','ASC');
                      //  $query->condition('n.download_flag','1','!=');
                       // $query->isNull('n.download_flag');
                       $query->range($start_limit, '5000');

                      
                        $result = $query->execute();
                       
                foreach($result as $r){
                 
                 
                  $csv_output .= "\n";
                $agency_id = $_SESSION['agency'];
                $agency_detail = node_load($agency_id);
                //$md = md5($gen_ekey = $r->house_hold_id.''.$r->name.''.$r->ahl_tin.''.$r->slnomember.''.$r->genderid.''.$r->fathername.$r->yob);

                $q = trim(trim($r->house_hold_id).trim($r->name).trim($r->ahl_tin).trim($r->slnomember).trim($r->genderid).trim($r->fathername).trim($r->yob));
              $ekeyv = trim(str_replace(' ', '', $q));
              $md = md5($ekeyv);

             // $encrypted_csv_line =  $r->house_hold_id.",".$r->tin_npr.",".$dow_rural_urban.",".$r->slnomember.",".$r->name.",".$r->name_sl.",".$r->relation.",".$r->genderid.",".$r->dob.",".$r->mstatusid.",".$r->fathername.",".$r->mothername.",".$r->occupation.",".$r->educode.",".$r->education_other.",".$r->ahl_tin.",".$r->age.",".$r->yob.",".$r->hof.",".$r->e_id.",".$r->aadhaar.",".$r->bank_account_no.",".$r->bank_name.",".$r->bank_branch.",".$r->primary_occupation_code.",".$r->secondary_occupation_code.",".$r->p_address1.",".$r->p_address2.",".$r->p_villagetown.",".$r->p_district.",".$r->p_state.",".$r->p_pincode.",".$r->c_address1.",".$r->c_address2.",".$r->c_villagetown.",".$r->c_district.",".$r->c_state.",".$r->c_pincode.",".$r->aadhaar_yesno.",".$r->beggars_dw_sv_hbw_adwi_wages.",".$r->construction_pl_sw_tw_sw.",".$r->p_tehsil.",".$r->c_tehsil.",".$r->lessthan_10000.",".$r->landlessthan_4acres.",".$r->house_based.",".$md.",".$r->uw_record.",".$agency_id.",".$agency_detail->title;
//$csv_output .= $encrypted_csv_line;

 $encrypted_csv_line = trim(encryptRJ256($ky, $iv, trim($r->house_hold_id))).",".trim(encryptRJ256($ky, $iv,trim($r->tin_npr))).",".trim(encryptRJ256($ky, $iv,trim($dow_rural_urban))).",".trim(encryptRJ256($ky, $iv,trim($r->slnomember))).",".trim(encryptRJ256($ky, $iv,trim($r->name))).",".$r->name_sl.",".trim(encryptRJ256($ky, $iv,trim($r->relation))).",".trim(encryptRJ256($ky, $iv,trim($r->genderid))).",".trim(encryptRJ256($ky, $iv,trim($r->dob))).",".trim(encryptRJ256($ky, $iv,trim($r->mstatusid))).",".trim(encryptRJ256($ky, $iv,trim($r->fathername))).",".trim(encryptRJ256($ky, $iv,trim($r->mothername))).",".trim(encryptRJ256($ky, $iv,trim($r->occupation))).",".trim(encryptRJ256($ky, $iv,trim($r->educode))).",".trim(encryptRJ256($ky, $iv,trim($r->education_other))).",".trim(encryptRJ256($ky, $iv,trim($r->ahl_tin))).",".trim(encryptRJ256($ky, $iv,trim($r->age))).",".trim(encryptRJ256($ky, $iv,trim($r->yob))).",".trim(encryptRJ256($ky, $iv,trim($r->hof))).",".''.",".''.",".''.",".''.",".''.",".''.",".''.",".''.",".''.",".''.",".''.",".''.",".''.",".''.",".''.",".''.",".''.",".''.",".''.",".''.",".''.",".''.",".''.",".''.",".''.",".''.",".trim(encryptRJ256($ky, $iv,trim($totaltrecordcount))).",".trim(encryptRJ256($ky, $iv,trim($md))).",".trim(encryptRJ256($ky, $iv,trim($_GET['mode']))).",".trim(encryptRJ256($ky, $iv,trim($agency_id))).",".trim(encryptRJ256($ky, $iv,trim($agency_detail->title)));

  



$csv_output .= $encrypted_csv_line;
//$csv_output .= "\r\n";
                } 
                
  
  }
    //$final_encrypted = SimpleTripleDes($csv_output);
    //return $final_encrypted;
    return $csv_output;
}
//Called function from .module file for downloading CSV.
function village_data_download(){
  
  $house_hold_id = arg(1);  
  module_load_include('inc', 'data_download');
  $csv_output = '';
  $csv_output .= 'house_hold_id,tin_npr,r_u,slnomember, name,name_sl,relation,genderid,dob,mstatusid,fathername,mothername,occupation,educode,education_other,ahl_tin,age,yob,hof,e_id,aadhaar,bank_account_no,bank_name,bank_branch,primary_occupation_code,secondary_occupation_code,p_address1,p_address2,p_villagetown,p_district,p_state,p_pincode,c_address1,c_address2,c_villagetown,c_district,c_state,c_pincode,aadhaar_yesno,beggars_dw_sv_hbw_adwi_wages,construction_pl_sw_tw_sw,p_tehsil,c_tehsil,lessthan_10000,landlessthan_4acres,total_record_count,ekey,data_range,agency_id,agency_name';  
 // $csv_output .= "\r\n";
  $csv_output .= get_village_persons($house_hold_id); 

  $limit = explode('-', $_GET['mode']);
  $start_limit = $limit[0]-1;
  $end_limit = $limit[1];
  $fname_range = $_GET['mode'];  
  
  //  $dow_rural_urban = $_SESSION['dow_rural_urban'];
  
  // $dow_state = $_SESSION['dow_state_value'];
  // $dow_district = $_SESSION['dow_district_value'];
  // $dow_tehsil = $_SESSION['dow_tehsil_value'];
  // $dow_village = $_SESSION['dow_village_value'];
  // $agency_sees = $_SESSION['agency'];
  // $fst = $_SESSION['secc_uw_data'];
  // $sec = $dow_rural_urban;
  // $tbl = $fst.''.$sec;
  //  $tbl_state = $_SESSION['dow_state_value'];

  // $query = db_select($tbl.".individual_".$tbl_state, "n");
  //       $query->fields('n');       
  //         $query->condition('n.statecode', $dow_state, '=');
  //         $query->condition('n.districtcode', $dow_district, '=');
  //         $query->condition('n.tehsilcode', $dow_tehsil, '=');
  //         $query->condition('n.towncode', $dow_village, '=');
  //         $result = $query->execute()->rowCount(); 


  //                   $divison_value = '5000';
  //                         $divsion = $result/$divison_value;
  //                         $arr = explode(".", $divsion);
  //                          $chunk = $arr[0];
  //                         $remaing_data = fmod($result,$divison_value);


  //                         $i = 1;
  //                         $s = 1;
  //                         $e =0;
  //                         for ($x = 1; $x <= $chunk; $x++) { 
  //                           $e = $e+5000;

  //                           }

  //                           $countv = $e/5000;                          




  $file_name = $house_hold_id.'-'.$_SESSION['dow_rural_urban'].'-'.date('Y-m-d').'-'.date('H-i-s').'-'.$fname_range.'.csv';
  //$file_name = 'ajay.csv';
  //Save log in log table
  
  save_log($house_hold_id,$file_name);
  
  

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

global $user;    
$state = substr($house_hold_id,0,2);
$district = substr($house_hold_id,2,2);
$tehsil = substr($house_hold_id,4,3);
$village = substr($house_hold_id,7,4);
$download_r_u = isset($_SESSION['dow_rural_urban']) ? $_SESSION['dow_rural_urban'] : '';
if($download_r_u == 'rural'){
    $r_u = r;
}elseif ($download_r_u == 'urban') {
       $r_u = u; 
    }
$current_time = date('Y-m-d H-i-s', time());  
$client_ip = ip_address();
    
$sch = 'activity';

$tbl_state = $_SESSION['dow_state_value'];
$tbl = 'secc_'.$download_r_u;
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
                    'up_down' => 'download'    
                    ))
                    ->execute();
    
}



