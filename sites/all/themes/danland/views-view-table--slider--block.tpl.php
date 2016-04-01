<?php GLOBAL $base_url; ?>

<script type="text/javascript" src="<?php print $base_url; ?>/sites/all/themes/danland/bxslider/jquery-lib.js"></script>
<link rel="stylesheet" src ="<?php print $base_url; ?>/sites/all/themes/danland/bxslider/jquery.bxslider.css"/>
<script type="text/javascript" src="<?php print $base_url; ?>/sites/all/themes/danland/bxslider/jquery.bxslider.js"></script>



<div class="slider">
<ul class="bxslider">
<?php
foreach($rows as $row){
	$nid = $row['nid'];
	$data = node_load($nid);
	$img = $data->field_image['und']['0']['uri'];
	$image_url = file_create_url($img);	?>
    <li>
      <img src="<?php print $image_url ?>" />
    </li>
<?php } ?>
</ul>
</div>
<script type="text/javascript" src="<?php print $base_url; ?>/sites/all/themes/danland/bxslider/bxslider-custom.js"></script>