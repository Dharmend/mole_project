<?php

$qry1 = db_query('Truncate Table registered_rural.individual_32');
$qry2 = db_query('Truncate Table registered_urban.individual_32');
$qry3 = db_query('Truncate Table ssid_generated_data.uwssid');
$qry4 = db_query('Truncate Table national_deduplication.fresh_records');
$qry5 = db_query('Truncate Table kit_ahltin_urban.individual_32');
$qry6 = db_query('Truncate Table kit_ahltin_rural.individual_32');
$qry7 = db_query('Truncate Table duplicate_recods.individual_32');
$qry8 = db_query('Truncate Table upload_acknowledgement');
$qry9 = db_query('Truncate Table fresh_records.individual_32');


?>