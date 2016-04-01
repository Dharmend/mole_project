<?php

echo "Welcome User..<br>";

//print_r($amar);
$house_hold_id = '27';
$tbl = 'secc_rural';

 //drupal_set_message('And table name'.$tbl.".individual_21_tm".'house hold id'.$house_hold_id.'');
  
 $header = array('S.N','House Hold id','Name', 'Fathers\'s Name','Mother\'s Name','Occupation','DOB','hof','Gender','Relation');
 
  
  //16157739
$soundex_va  = '';
 $sql = "select name from $tbl.individual_21_tm  where  soundex(name) = soundex('$soundex_va')";
  $subquery = db_query($sql)
              ->fetchAll();
  echo "<pre>";
$sondex_array = array();
foreach($subquery as  $subdata){

  $sondex_array[] =  $subdata->name;
}

//rint_r($sondex_array);

            $a =  array('jira ajagala');

  $query = db_select($tbl.".individual_21_tm", "n");
  $query->fields('n',array('name','ahl_tin','fathername','mothername','occupation','dob','hof','genderid','relation','house_hold_id'));
  //$query->orderBy($order, $sort);
  //$query->orderBy('n.house_hold_id','ASC');
  //$query->orderBy('n.slnomember','ASC');
  
  $query->condition('n.house_hold_id', 21 . '%', 'LIKE');
  if (!empty($sondex_array)) {
      $query->condition('n.name', $sondex_array, 'IN');

  }
    

  //$query->condition('n.move_flag',0,'=');
 $query = $query->extend('TableSort')->extend('PagerDefault')->limit(20);
  $result = $query->execute();
  echo "<pre>";
  while ( $data = $result->fetchAssoc()) {
      print_r($data);

  }
  
  

exit();


$state = array('0' => 'Select');   
$st = '09';
$qr = db_query('select district_name,rgi2011_district_code FROM {directory."RGI2011_District"} where rgi2011_state_code = :sid', array(':sid' => $st));
foreach ($qr as $q){
    $state[$q->rgi2011_district_code] = $q->district_name;
}
print_r($state);


   exit();


            
                    
    print_r($states);
                    
                    
    exit();




_testing_table();
 

function _testing_table(){
  $output = "";
  
  $house_hold_id = '16';//16157739
  
  $query = db_select("u_state_27_txndependent_tmp", "n");
  $query->fields('n',array('name','fathername','mothername','occupation','dob'));
  //$query->orderBy($order, $sort);
  $query->condition('n.house_hold_id','%' . db_like($house_hold_id) . '%', 'LIKE');
  $query = $query->extend('TableSort')->extend('PagerDefault')->limit(20);
  $result = $query->execute();
  

// Prepare table header
  $header = array('Name', 'Fathers\'s Name','Mother\'s Name','Occupation','DOB');
  

$rows = array();
  

// Looping for filling the table rows
  while($data = $result->fetchObject()){
    // Fill the table rows
      $rows[] = array(
      $data->name,
      $data->fathername,
      $data->mothername,
      $data->occupation,
      $data->dob    
);
}
  

// Output of table with the paging
  $output = theme_table(
    array(
      "header" => $header,
      "rows" => $rows,
      "attributes" => array(),
      "sticky" => true, // Table header will be sticky
      "caption" => "",
      "colgroups" => array(),
      "empty" => t("Table has no row!") // The message to be displayed if table is empty
    )
  ).theme("pager");
  echo $output;
}


exit();



$state_id = '16';
$district_id = '157';
$tehsil_id = '739';//F.B.D

$query = db_select('village_towns','vi')
        ->fields('vi',array('id','name'))
        ->condition('vi.state_id',$state_id,'=')
        ->condition('vi.district_id',$district_id,'=')
        ->condition('vi.tehsil_id',$tehsil_id,'=')
        ->execute();

$village = array();

foreach ($query as $q){
    
    $village[$q->id] = t($q->name);
}

print_r($village);

?>