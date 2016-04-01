<?php

  $ssidtable_query = db_select("national_deduplication".".fresh_records", "ssid")    
                          ->fields('ssid')
                          ->execute();
  while($ssid_generated_data  = $ssidtable_query->fetchAssoc()){
                            $ssidtabahl_tin[] = $ssid_generated_data['ahl_tin'];
                           
                        }
echo "<pre>";
//print_r($ssidtabahl_tin);


$fr_qry = db_select("fresh_records".".individual_32", "fr")    
                              ->fields('fr')
                              ->condition('fr.statecode',32)
                              ->condition('fr.de_depulication_status','0')
                             // ->condition('fr.unorganised', '1', '=')
                              ->execute();


              
while($freshtabledata  = $fr_qry->fetchAssoc()){
    //print_r($freshtabledata);
    
    $freshtabahl_tin = $freshtabledata['ahl_tin'];
    
    print $freshtabahl_tin;
    echo  "<br>";
     if((in_array($freshtabahl_tin, $ssidtabahl_tin,TRUE))){  
               print   $remark = 'Duplicate AHL TIN by Dharmend';

     }elseif(in_array($freshtabaadhaar, $ssidtabaadhar, TRUE)){
         print   $remark = 'Duplicate AHL TIN by ANIL';
     }else{
         print   $remark = 'Duplicate AHL TIN by AJAY';
     }
    
}

























 $fresh_query = db_select("fresh_records.individual_32", "fq1")  
                           ->fields('fq1')
                           ->condition('fq1.unorganised','1','=')
         ->execute()->rowCount();
 
 echo "fresh record with unorganised  ".$fresh_query;
 print "<br>";


 $fresh_query0 = db_select("fresh_records.individual_32", "fq0")  
                           ->fields('fq0')
                           ->condition('fq0.unorganised','0','=')
         ->execute()->rowCount();
 
 echo "fresh record with nonunorganised  ".$fresh_query0;
 print "<br>";


 $fresh_query2 = db_select("fresh_records.individual_32", "f")  
                           ->fields('f')
                           ->condition('f.unorganised','2','=')
         ->execute()->rowCount();
 
 echo "fresh record with died record  ".$fresh_query2;
 print "<br>";
 
 $dubli_query = db_select("duplicate_recods.individual_32", "fq2")  
                           ->fields('fq2')
         ->execute()->rowCount();
 
 echo "dublicate record ".$dubli_query;
 print "<br>";
 
 $national_query = db_select("national_deduplication".".fresh_records", "fq3")  
                           ->fields('fq3')
         ->execute()->rowCount();
 
 echo "National record ".$national_query;
 print "<br>";
 
        
                               






 
 