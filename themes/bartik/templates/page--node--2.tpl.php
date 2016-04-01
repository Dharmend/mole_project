<?php

echo md5('uwssp_project');


exit();
$city_qry = db_select('node','n')
                    ->fields('n',array('nid','title'))
                    //->condition('n.type','city')
                    //->condition('n.status',1)
		    //->orderBy('n.title', 'ASC')
                    ->execute();
        
        $city_list = array();
        $total_cities = $city_qry->rowCount();
        $allcity_list = array();
        
        if($city_qry->rowCount() >0){
            
            foreach ($city_qry as $qry){
                
                $city_list['id'] = $qry->nid;
                $city_list['name'] = $qry->title;
                $allcity_list[] = $city_list;
                
            }
     
        }
        
        print_r($allcity_list);   
    

?>