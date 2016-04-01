<?php
  // In a real module variables should be manipulated in a preprocess function.
  $content = $element->content;
  $result = $content['#element'];
  //print_r($result);
?>

<div class="<?php print $classes; ?>">
    <div class="ins_type">
        <span>Institute Type :</span><span> <?php echo $result->ins_type ;?> </span>
    </div>
    <div class="ins_code">
        <span>Institute Code  :</span><span> <?php echo $result->ins_code ;?> </span>
    </div>
    <div class="ins_name">
        <span>Name  :</span><span> <?php echo $result->name ;?> </span>
    </div>
    <div class="ins_rep">
        <span>Ins./Rep. in Local Lang  :</span><span> <?php echo $result->ins_local_lng ;?> </span>
    </div>
    <div class="ins_address">
        <span>Address   :</span><span> <?php echo $result->address ;?> </span>
    </div>
    <div class="ins_district">
        <span>District    :</span><span> <?php echo $result->district ;?> </span>
    </div>
    <div class="ins_state">
        <span>State :</span><span> <?php echo $result->state ;?> </span>
    </div>
    <div class="ins_pin">
        <span>Pin :</span><span> <?php echo $result->pin ;?> </span>
    </div>
    <div class="ins_head">
        <span>Head of the Institution :</span><span> <?php echo $result->head_of_inst ;?> </span>
    </div>
    <div class="ins_phone">
        <span>Phone No :</span><span> <?php echo $result->phone ;?> </span>
    </div>
    <div class="ins_email">
        <span>E-mail :</span><span> <?php echo $result->email ;?> </span>
    </div>
    <div class="ins_website">
        <span>Website  :</span><span> <?php echo $result->website ;?> </span>
    </div>
    <div class="ins_total_manu">
        <span>No of Total Manuscripts :</span><span> <?php echo $result->total_manu ;?> </span>
    </div>
    <div class="ins_paper_manu">
        <span>No of Paper Manuscripts :</span><span> <?php echo $result->paper_manu ;?> </span>
    </div>
    <div class="ins_palmleaf_manu">
        <span>No of Palm Leaf Manuscripts :</span><span> <?php echo $result->palm_leaf_manu ;?> </span>
    </div>
    <div class="ins_mass_other">
        <span>No of Mss. In Other Material :</span><span> <?php echo $result->other_material_manu ;?> </span>
    </div>
    <div class="ins_illus_manu">
        <span>No of Illustrated Manuscripts :</span><span> <?php echo $result->illustrated_manu ;?> </span>
    </div>
    <div class="ins_catalog_pub">
        <span>No of Catalogues Published :</span><span> <?php echo $result->catalog_published ;?> </span>
    </div>
    <div class="ins_type_catalogs">
        <span>Type of Catalogues :</span><span> <?php echo $result->catalogue_type;?> </span>
    </div>
    <area>
    <h5>No of Manuscripts Catalogued- Category wise</h5>
    <div class="ins_type_catalogs">
        <span>A :</span><span> <?php echo $result->manu_catalog_cat_wise_A;?> </span>
    </div>
    <div class="ins_type_catalogs">
        <span>C :</span><span> <?php echo $result->manu_catalog_cat_wise_C;?> </span>
    </div>
    <div class="ins_type_catalogs">
        <span>D :</span><span> <?php echo $result->manu_catalog_cat_wise_D;?> </span>
    </div>
    <div class="ins_type_catalogs">
        <span>H :</span><span> <?php echo $result->manu_catalog_cat_wise_H;?> </span>
    </div>
    </area>
    
    <div class="ins_cat_status">
        <span>Status of Catalogue :</span><span> <?php echo $result->catalogue_status;?> </span>
    </div>
    <div class="ins_rare_manu">
        <span>Detail of Rare Manuscripts :</span><span> <?php echo $result->detail_rare_manu;?> </span>
    </div>
    <div class="ins_chr_range">
        <span>Chronological Rang of the Manuscript :</span><span> <?php echo $result->chronological_ranf_manu;?> </span>
    </div>
    <div class="ins_cat_status">
        <span>State Preservation :</span><span> <?php echo $result->state_preservation;?> </span>
    </div>
    <div class="ins_type">
        <span>Type of the Institution :</span><span> <?php echo $result->type_of_inst;?> </span>
    </div>
    <div class="ins_cat_status">
        <span>Status of Conversation:</span><span> <?php echo $result->status_of_conversation;?> </span>
    </div>
    <div class="ins_brf_history">
        <span>Brief History :</span><span> <?php echo $result->brief_history;?> </span>
    </div>
    <div class="ins_info_date">
        <span>Date of Collection of Information :</span><span> <?php echo $result->date_information_collection;?> </span>
    </div>
    <div class="ins_mrc">
        <span>MRC :</span><span> <?php echo $result->mrc;?> </span>
    </div>
    

    
</div>