<?php $site_path = $base_path.path_to_theme(); ?>
<link rel="stylesheet" href="<?php print $site_path.'/style2.css'?>" />
<title>Index</title>
</head>
<body>
<div id="header"><div id="logo"><a href="<?php print $base_path ?>"><h1>Unorganised workers' Social Security Platform 
<span>A Flagship Initiative by Minsiter of Labour &amp; Employment,Govt of India</span></h1> </a></div></div>
<div id="content">
 <div class="flag-bg">
  <div class="kesaria-bg">&nbsp;</div>
  <div class="white-bg">&nbsp;</div>
  <div class="green-bg">&nbsp;</div>
 
 
 
 </div>

  <div class="wrapper">
    <div class="messages"><?php if ($show_messages) { print $messages; }; ?></div>
    <div class="login-block">
      <div class="login-image"> <img src="<?php print $site_path.'/images/assets/login-image2.gif' ?>" alt="" /> 
      <div class="login-bg1"><h2>Welcome to the Unorganised
                   workers' Social Security Platform</h2></div>
      </div>
      <div class="login-form">
		<?php if($user->uid==0) {?>
		<?php print render($page['sidebar_first']); ?>
		<?php } ?>
      </div>
    </div>
  </div>
  <?php if ($page['content_bottom']) : ?><div class="content-bottom"><?php print render ($page['content_bottom']); ?></div>
<?php endif; ?>
</div>
<footer id="footer">
<div class="wrapper">
<a href="#" class="designed">Designed &amp; Developed by CMC Ltd</a>
<span class="copy-rt"> Copyright © 2015 Ministry of Labour &amp; Employment <br>
Website designed & developed by National Informatics Centre.
</span>
</div>
</footer>