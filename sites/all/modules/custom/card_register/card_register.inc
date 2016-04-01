<?php

function get_card_register(){
  $start_date = strtotime($_SESSION['date_from'] );
 $end_date =  strtotime($_SESSION['date_to']);
  $csv_output = '';
  $query = db_select('card_register', 'cr');
    $query->fields('cr');
    $query->condition('approved', '1', '=');
   $query->condition('card_create_date', array($start_date, $end_date), 'BETWEEN');

      $query->orderBy('id','ASC');

      $result = $query->execute();

 	
                foreach($result as $r){
                  $district = explode(',', $r->district);
                $distrcit_count = count($district);
                for ($x = 0; $x < $distrcit_count; $x++) {
    //echo "The number is: $district[$x] <br>";
//} 

                  $csv_output .= "\n";
$csv_output .= $r->id.",".$r->state.",".$district[$x].",".$r->authority_card_holder.",".$r->designation.",".$r->official_address1.",".$r->official_address2.",".$r->pin_code.",".$r->type_card_request.",".$r->letter_date.",".$r->letter_no.",".$r->department_organisation_name.",".$r->organisation_unit_no.",".$r->aadhaar_no.",".''.",".''.",";
                  $csv_output .= "\r\n";
                } 
              }
  
  return $csv_output;
}



function downlaod_card(){
  module_load_include('inc', 'card_register');
  $csv_output = '';
  $csv_output .= 'card_request_id,state,district,authority_card_holder,designation,address1_requester,address2_requester,pin_code,card_type,letter_date,letterno,department_organisation_name,organisation_unit_no,adhar_no,csn_no,card_personlise_date';  
  $csv_output .= "\r\n";
  $csv_output .= get_card_register(); 
  $file_name = 'card'.'-'.date('Y-m-d').'-'.date('H-i-s').'.csv';
  
  
  global $base_url;
      // $save_file_path = $base_url.'/sites/default/files/downloaded_exel/'.$file_name;
              $save_file_path = $file_name;

        $csv_handler = fopen($save_file_path,'w');
        //fwrite ($csv_handler,$csv_output);
        fputs($csv_handler, $csv_output);
        fclose ($csv_handler);
  //end of the file

   header("Content-type: text/csv");
  header("Content-disposition: attachment; filename=".$file_name."");
  readfile($file_name);
  //Save log activity
  //save_log($house_hold_id,$file_name);
    //print $csv_output;
    exit; 
}


?>