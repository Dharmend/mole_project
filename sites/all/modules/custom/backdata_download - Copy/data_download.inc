<?php
// ini_set('display_errors', 1);
// ini_set('display_startup_errors', 1);
// error_reporting(E_ALL);
// //Function for getting the node details & adding it to CSV variable.
// // very simple ASCII key and IV

// $ky = 'lkirwf897+22#bbtrm8814z5qq=498j5'; // 32 * 8 = 256 bit key
// $iv = '741952hheeyy66#cs!9hjv887mxx7@8y'; // 32 * 8 = 256 bit iv

function encryptRJ256($key,$iv,$string_to_encrypt)
{
   $rtn = mcrypt_encrypt(MCRYPT_RIJNDAEL_256, $key, $string_to_encrypt, MCRYPT_MODE_CBC, $iv);
    $rtn = base64_encode($rtn);
   return($rtn);
}

// function decryptRJ256($key,$iv,$string_to_decrypt)
//  {
//      //$string_to_decrypt = base64_decode($string_to_decrypt);
//      $rtn = mcrypt_decrypt(MCRYPT_RIJNDAEL_256, $key, $string_to_decrypt, MCRYPT_MODE_CBC, $iv);
//      $rtn = rtrim($rtn, "\0\4");
//      return($rtn);
//  }


  //$string_to_encrypt = "This is my encrypted message";

  // to append string with trailing characters as for PKCS7 padding scheme                                                                                                                                                                           
//   function encryptRJ256($key,$iv,$string_to_encrypt)
// {
//   $block = mcrypt_get_block_size(MCRYPT_RIJNDAEL_256, MCRYPT_MODE_CBC);
//   $padding = $block - (strlen($string_to_encrypt) % $block);
//   $string_to_encrypt .= str_repeat(chr($padding), $padding);
//   $crypttext = mcrypt_encrypt(MCRYPT_RIJNDAEL_256, $key, $string_to_encrypt, MCRYPT_MODE_CBC, $iv);
//   $crypttext64=base64_encode($crypttext);
// //  print($crypttext64) . "\n<br/>";
//   return $crypttext64;
// }

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
  //Encryption And Decryption  
  
  // $iv = "45287112549354892144548565456541";
  // $ky = "anjueolkdiwpoida";
  $ky = 'lkirwf897+22#bbtrm8814z5qq=498j5'; // 32 * 8 = 256 bit key
  $iv = '741952hheeyy66#cs!9hjv887mxx7@8y'; // 32 * 8 = 256 bit iv


  if(($dow_rural_urban != '') && ($fst !='')){

                 $tbl = $fst.''.$sec;
                  //drupal_set_message($tbl.".individual_".$tbl_state);
                try{
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
                       $query->range(0, 10);
                        $result = $query->execute();
                        //print_r($result);
                } catch (Exception $ex) {
                        watchdog('State Table not found', 'error message');
                }
                
                
                //$md = md5($house_hold_id);
                foreach($result as $r){
                 
                 
                  $csv_output .= "\n";
                $agency_id = $_SESSION['agency'];
                $agency_detail = node_load($agency_id);
                //$md = md5($gen_ekey = $r->house_hold_id.''.$r->name.''.$r->ahl_tin.''.$r->slnomember.''.$r->genderid.''.$r->fathername.$r->yob);

                $q = trim(trim($r->house_hold_id).trim($r->name).trim($r->ahl_tin).trim($r->slnomember).trim($r->genderid).trim($r->fathername).trim($r->yob));
              $ekeyv = trim(str_replace(' ', '', $q));
              $md = md5($ekeyv);

            //   $encrypted_csv_line =  $r->house_hold_id.",".$r->tin_npr.",".$dow_rural_urban.",".$r->slnomember.",".$r->name.",".$r->name_sl.",".$r->relation.",".$r->genderid.",".$r->dob.",".$r->mstatusid.",".$r->fathername.",".$r->mothername.",".$r->occupation.",".$r->educode.",".$r->education_other.",".$r->ahl_tin.",".$r->age.",".$r->yob.",".$r->hof.",".$r->e_id.",".$r->aadhaar.",".$r->bank_account_no.",".$r->bank_name.",".$r->bank_branch.",".$r->primary_occupation_code.",".$r->secondary_occupation_code.",".$r->p_address1.",".$r->p_address2.",".$r->p_villagetown.",".$r->p_district.",".$r->p_state.",".$r->p_pincode.",".$r->c_address1.",".$r->c_address2.",".$r->c_villagetown.",".$r->c_district.",".$r->c_state.",".$r->c_pincode.",".$r->aadhaar_yesno.",".$r->beggars_dw_sv_hbw_adwi_wages.",".$r->construction_pl_sw_tw_sw.",".$r->p_tehsil.",".$r->c_tehsil.",".$r->lessthan_10000.",".$r->landlessthan_4acres.",".$r->house_based.",".$md.",".$r->uw_record.",".$agency_id.",".$agency_detail->title;
//$csv_output .= $encrypted_csv_line;

$encrypted_csv_line = trim(encryptRJ256($ky, $iv, trim($r->house_hold_id))).",".trim(encryptRJ256($ky, $iv,trim($r->tin_npr))).",".trim(encryptRJ256($ky, $iv,trim($dow_rural_urban))).",".trim(encryptRJ256($ky, $iv,trim($r->slnomember))).",".trim(encryptRJ256($ky, $iv,trim($r->name))).",".$r->name_sl.",".trim(encryptRJ256($ky, $iv,trim($r->relation))).",".trim(encryptRJ256($ky, $iv,trim($r->genderid))).",".trim(encryptRJ256($ky, $iv,trim($r->dob))).",".trim(encryptRJ256($ky, $iv,trim($r->mstatusid))).",".trim(encryptRJ256($ky, $iv,trim($r->fathername))).",".trim(encryptRJ256($ky, $iv,trim($r->mothername))).",".trim(encryptRJ256($ky, $iv,trim($r->occupation))).",".trim(encryptRJ256($ky, $iv,trim($r->educode))).",".trim(encryptRJ256($ky, $iv,trim($r->education_other))).",".trim(encryptRJ256($ky, $iv,trim($r->ahl_tin))).",".trim(encryptRJ256($ky, $iv,trim($r->age))).",".trim(encryptRJ256($ky, $iv,trim($r->yob))).",".trim(encryptRJ256($ky, $iv,trim($r->hof))).",".trim(encryptRJ256($ky, $iv,trim($r->e_id))).",".trim(encryptRJ256($ky, $iv,trim($r->aadhaar))).",".trim(encryptRJ256($ky, $iv,trim($r->bank_account_no))).",".trim(encryptRJ256($ky, $iv,trim($r->bank_name))).",".trim(encryptRJ256($ky, $iv,trim($r->bank_branch))).",".trim(encryptRJ256($ky, $iv,trim($r->primary_occupation_code))).",".trim(encryptRJ256($ky, $iv,trim($r->secondary_occupation_code))).",".trim(encryptRJ256($ky, $iv,trim($r->p_address1))).",".trim(encryptRJ256($ky, $iv,trim($r->p_address2))).",".trim(encryptRJ256($ky, $iv,trim($r->p_villagetown))).",".trim(encryptRJ256($ky, $iv,trim($r->p_district))).",".trim(encryptRJ256($ky, $iv,trim($r->p_state))).",".trim(encryptRJ256($ky, $iv,trim($r->p_pincode))).",".trim(encryptRJ256($ky, $iv,trim($r->c_address1))).",".trim(encryptRJ256($ky, $iv,trim($r->c_address2))).",".trim(encryptRJ256($ky, $iv,trim($r->c_villagetown))).",".trim(encryptRJ256($ky, $iv,trim($r->c_district))).",".trim(encryptRJ256($ky, $iv,trim($r->c_state))).",".trim(encryptRJ256($ky, $iv,trim($r->c_pincode))).",".trim(encryptRJ256($ky, $iv,trim($r->aadhaar_yesno))).",".trim(encryptRJ256($ky, $iv,trim($r->beggars_dw_sv_hbw_adwi_wages))).",".trim(encryptRJ256($ky, $iv,trim($r->construction_pl_sw_tw_sw))).",".trim(encryptRJ256($ky, $iv,trim($r->p_tehsil))).",".trim(encryptRJ256($ky, $iv,trim($r->c_tehsil))).",".trim(encryptRJ256($ky, $iv,trim($r->lessthan_10000))).",".trim(encryptRJ256($ky, $iv,trim($r->landlessthan_4acres))).",".trim(encryptRJ256($ky, $iv,trim($r->house_based))).",".trim(encryptRJ256($ky, $iv,trim($md))).",".trim(encryptRJ256($ky, $iv,trim($r->uw_record))).",".trim(encryptRJ256($ky, $iv,trim($agency_id))).",".trim(encryptRJ256($ky, $iv,trim($agency_detail->title)));

  //$encrypted_csv_line = (encryptRJ256($ky, $iv, ($r->house_hold_id))).",".(encryptRJ256($ky, $iv,($r->tin_npr))).",".(encryptRJ256($ky, $iv,($dow_rural_urban))).",".(encryptRJ256($ky, $iv,($r->slnomember))).",".(encryptRJ256($ky, $iv,($r->name))).",".(encryptRJ256($ky, $iv,($r->name_sl))).",".(encryptRJ256($ky, $iv,($r->relation))).",".(encryptRJ256($ky, $iv,($r->genderid))).",".(encryptRJ256($ky, $iv,($r->dob))).",".(encryptRJ256($ky, $iv,($r->mstatusid))).",".(encryptRJ256($ky, $iv,($r->fathername))).",".(encryptRJ256($ky, $iv,($r->mothername))).",".(encryptRJ256($ky, $iv,($r->occupation))).",".(encryptRJ256($ky, $iv,($r->educode))).",".(encryptRJ256($ky, $iv,($r->education_other))).",".(encryptRJ256($ky, $iv,($r->ahl_tin))).",".(encryptRJ256($ky, $iv,($r->age))).",".(encryptRJ256($ky, $iv,($r->yob))).",".(encryptRJ256($ky, $iv,($r->hof))).",".(encryptRJ256($ky, $iv,($r->e_id))).",".(encryptRJ256($ky, $iv,($r->aadhaar))).",".(encryptRJ256($ky, $iv,($r->bank_account_no))).",".(encryptRJ256($ky, $iv,($r->bank_name))).",".(encryptRJ256($ky, $iv,($r->bank_branch))).",".(encryptRJ256($ky, $iv,($r->primary_occupation_code))).",".(encryptRJ256($ky, $iv,($r->secondary_occupation_code))).",".(encryptRJ256($ky, $iv,($r->p_address1))).",".(encryptRJ256($ky, $iv,($r->p_address2))).",".(encryptRJ256($ky, $iv,($r->p_villagetown))).",".(encryptRJ256($ky, $iv,($r->p_district))).",".(encryptRJ256($ky, $iv,($r->p_state))).",".(encryptRJ256($ky, $iv,($r->p_pincode))).",".(encryptRJ256($ky, $iv,($r->c_address1))).",".(encryptRJ256($ky, $iv,($r->c_address2))).",".(encryptRJ256($ky, $iv,($r->c_villagetown))).",".(encryptRJ256($ky, $iv,($r->c_district))).",".(encryptRJ256($ky, $iv,($r->c_state))).",".(encryptRJ256($ky, $iv,($r->c_pincode))).",".(encryptRJ256($ky, $iv,($r->aadhaar_yesno))).",".(encryptRJ256($ky, $iv,($r->beggars_dw_sv_hbw_adwi_wages))).",".(encryptRJ256($ky, $iv,($r->construction_pl_sw_tw_sw))).",".(encryptRJ256($ky, $iv,($r->p_tehsil))).",".(encryptRJ256($ky, $iv,($r->c_tehsil))).",".(encryptRJ256($ky, $iv,($r->lessthan_10000))).",".(encryptRJ256($ky, $iv,($r->landlessthan_4acres))).",".(encryptRJ256($ky, $iv,($r->house_based))).",".(encryptRJ256($ky, $iv,($md))).",".(encryptRJ256($ky, $iv,($r->uw_record))).",".(encryptRJ256($ky, $iv,($agency_id))).",".(encryptRJ256($ky, $iv,($agency_detail->title)));



$csv_output .= $encrypted_csv_line;
$csv_output .= "\r\n";
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
  $csv_output .= 'house_hold_id,tin_npr,r_u,slnomember, name,name_sl,relation,genderid,dob,mstatusid,fathername,mothername,occupation,educode,education_other,ahl_tin,age,yob,hof,e_id,aadhaar,bank_account_no,bank_name,bank_branch,primary_occupation_code,secondary_occupation_code,p_address1,p_address2,p_villagetown,p_district,p_state,p_pincode,c_address1,c_address2,c_villagetown,c_district,c_state,c_pincode,aadhaar_yesno,beggars_dw_sv_hbw_adwi_wages,construction_pl_sw_tw_sw,p_tehsil,c_tehsil,lessthan_10000,landlessthan_4acres,house_based,ekey,unorganised_marked_by,agency_id,agency_name';  
  $csv_output .= "\r\n";
  $csv_output .= get_village_persons($house_hold_id); 
  $file_name = $house_hold_id.'-'.$_SESSION['dow_rural_urban'].'-'.date('Y-m-d').'-'.date('H-i-s').'.csv';
  //$file_name = 'ajay.csv';
  
  //Save log in log table
  
  save_log($house_hold_id,$file_name);
  
  //save file in folder
        //global $base_url;
        //$save_file_path = '10.21.173.46:8080/trunck/rural-postgres/download/'.$file_name;
         // file_put_contents($save_file_path);

        $csv_handler = fopen('download/'.$file_name,'w');
        //fwrite ($csv_handler,$csv_output);
        fputs($csv_handler, $csv_output);
  //end of the file
  // header('Content-type: application/vnd.ms-excel');
  // header('Content-Disposition: attachment; filename='.$file_name.'');

   header("Cache-Control: public");
    header("Content-Description: File Transfer");
    header("Content-Disposition: attachment; filename=".$file_name."");
    header("Content-Transfer-Encoding: binary");
    header("Content-Type: binary/octet-stream");
    readfile($file_name);
  //Save log activity
   return $csv_output;
   //fclose ($csv_handler);

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
                    ))
                    ->execute();
    
}


//function SimpleTripleDes($buffer) {
//  global $key, $iv, $cipher;
//  //printvar($buffer, 'Encrypting:');
//
//  // get the amount of bytes to pad
//  $extra = 8 - (strlen($buffer) % 8);
//  //printvar($extra, 'Padding with n zeros');
//
//  // add the zero padding
//  if($extra > 0) {
//    for($i = 0; $i < $extra; $i++) {
//      $buffer .= "\0";
//    }
//  }
//
//  mcrypt_generic_init($cipher, $key, $iv);
//  $result = bin2hex(mcrypt_generic($cipher, $buffer));
//  mcrypt_generic_deinit($cipher);
//  return $result;
//}
//
//function SimpleTripleDesDecrypt($buffer) {
//  global $key, $iv, $cipher;
//  //printvar($buffer, 'Decrypting:');
//
//  mcrypt_generic_init($cipher, $key, $iv);
//  $result = rtrim(mdecrypt_generic($cipher, hex2bind($buffer)), "\0");
//  mcrypt_generic_deinit($cipher);
//  return $result;
//}
//
//function hex2bind($data)
//{
//  $len = strlen($data);
//  return pack("H" . $len, $data);
//} 
//
//// HELPER FUNCTIONS
//function printvar($var, $label="") {
//    print "" .
//        (
//            (
//                strlen(
//                    trim($label)
//                )
//            ) ? htmlentities($label)."" : ""
//        ) .
//        htmlentities(print_r($var, TRUE)) . "";
//}

?>