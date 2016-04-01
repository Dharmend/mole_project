<?php $site_path = $base_path.path_to_theme(); ?>
<link rel="stylesheet" href="<?php print $site_path.'/style2.css'?>" />
<script src="<?php print $site_path.'/popup1.js'?>"></script>
<script src="http://code.jquery.com/jquery-1.11.1.min.js"></script>
<title>Index</title>
</head><body>
<div id="header">
  <div class="wrapper">
    <div id="logo"><a href="<?php print $base_path ?>">
      <h1>Unorganised Workers' Social Security Platform <span>A Flagship Initiative by Ministry of Labour &amp; Employment,Govt of India</span></h1>
      </a></div>
  </div>
</div>
<div id="content">
  <div class="flag-bg">
    <div class="kesaria-bg">&nbsp;</div>
    <div class="white-bg">&nbsp;</div>
    <div class="green-bg">&nbsp;</div>
  </div>
  <div class="wrapper">
    <div class="messages">
      <?php if ($show_messages) { print $messages; }; ?>
    </div>
    <div class="login-block">
      <div class="login_msg"> <span>Un-Organized Workers Registration System</span> </div>
      <div class="login-image"> <img src="<?php print $site_path.'/images/assets/login-image2.gif' ?>" alt="" />
        <div class="login-bg1">
          <h2>Welcome to the Unorganised
            workers' Social Security Platform</h2>
        </div>
      </div>
      <div class="login-role_msg"> <span>Login Role</span>
        <ul>
          <li>
            <div class="mole"> <a class="js-open-modal btn" href="#" data-modal-id="popup1"> As Mole</a> </div>
            <div class="state"> <a class="js-open-modal btn" href="#" data-modal-id="popup2"> As State</a> </div>
            <div class="district"> <a class="js-open-modal btn" href="#" data-modal-id="popup3"> As District</a> </div>
            <div class="tehsil"> <a class="js-open-modal btn" href="#" data-modal-id="popup4"> As Tehsil</a> </div>
            <div class="agent"> <a class="js-open-modal btn" href="#" data-modal-id="popup5"> As registration Agency</a> </div>
            <div class="card_aceepter"> <a class="js-open-modal btn" href="#" data-modal-id="popup6"> As Authority card Accepter</a> </div>
            <div class="agency"> <a class="js-open-modal btn" href="#" data-modal-id="popup7"> As Download Authority Agency</a> </div>
          </li>
        </ul>
      </div>
      <div id="popup1" class="modal-box">
        <header> <a href="#" class="js-modal-close close">×</a>
          <h3>Login User Information</h3>
        </header>
        <div class="modal-body"> <span>Login with <?php echo $_GET['role'];?> User</span> <span>
          <?php ?>
          MoLE  has Following Permissions</span>
          <ul>
            <li>Access All state data at village level.</li>
            <li>Add Registration Agency.</li>
            <li>Access list of Authority cards.</li>
            <li>Create user for applying authority Cards.</li>
            <li>View all users of application with different roles.</li>
            <li>Generate SSID.</li>
          </ul>
        </div>
        <footer> <a href="#" class="btn btn-small js-modal-close">Close</a> </footer>
      </div>
      <div id="popup2" class="modal-box">
        <header> <a href="#" class="js-modal-close close">×</a>
          <h3>Login User Information</h3>
        </header>
        <div class="modal-body"> <span>Login with <?php echo $_GET['role'];?> User</span> <span> <?php echo $_GET['role'];?> State Has Following Permissions</span>
          <ul>
            <li>Access all district data of particular state belonging to current user login state
              (e.g if user belong to Uttar Pradesh state then he will access all district of Uttar Pradesh)on village level.</li>
            <li>Create user of Tehsil.</li>
            <li>Can View all user of current Role belonging to same state.</li>
          </ul>
        </div>
        <footer> <a href="#" class="btn btn-small js-modal-close">Close</a> </footer>
      </div>
      <div id="popup3" class="modal-box">
        <header> <a href="#" class="js-modal-close close">×</a>
          <h3>Login User Information</h3>
        </header>
        <div class="modal-body"> <span>Please Login with <?php echo $_GET['role'];?> User</span> <span> <?php echo $_GET['role'];?> District Has Following Permissions </span>
          <ul>
            <li>Access All tehsil data of particular district belonging to current user login district(e.g If user belongs 
              to Uttar Pradesh state having Farrukhabad District then he will access all tehsil of Farrukhabad) On village level</li>
            <li>Permission to download village data, Agency wise permission based.</li>
            <li>Import Card creation data for IA CARD in CSV format.</li>
            <li>Import village data in CSV format.</li>
            <li>Assign Agency to download village data.</li>
            <li>Create user of agent level.</li>
            <li>User list of current category user.</li>
            <li>Check De-duplication.</li>
          </ul>
        </div>
        <footer> <a href="#" class="btn btn-small js-modal-close">Close</a> </footer>
      </div>
      <div id="popup4" class="modal-box">
        <header> <a href="#" class="js-modal-close close">×</a>
          <h3>Login User Information</h3>
        </header>
        <div class="modal-body"> <span>Login with <?php echo $_GET['role'];?></span> <span><?php echo $_GET['role'];?> Tehsil Has Following Permissions</span>
          <ul>
            <li>Access All Data of particular tehsil belonging to current user login tehsil 
              (e.g if user belong to Uttar Pradesh State having Kushinagar district and their particular tehsil then he will acess all village data of that tehsil.)</li>
            <li>Import Card creation data for IA CARD in CSV format.</li>
            <li>Import village data in CSV format.</li>
            <li>Get Slip of person of village</li>
            <li>Create user of agent level.</li>
            <li>User list of current categeory user.</li>
          </ul>
        </div>
        <footer> <a href="#" class="btn btn-small js-modal-close">Close</a> </footer>
      </div>
      <div id="popup5" class="modal-box">
        <header> <a href="#" class="js-modal-close close">×</a>
          <h3>Login User Information</h3>
        </header>
        <div class="modal-body"> <span>Login with Authority card Requester User </span> <span><?php echo $_GET['role'];?> Has Following Permissions</span>
          <ul>
            <li>Authority Card Registration request.</li>
            <li>User list of current category user.</li>
          </ul>
        </div>
        <footer> <a href="#" class="btn btn-small js-modal-close">Close</a> </footer>
      </div>
      <div id="popup6" class="modal-box">
        <header> <a href="#" class="js-modal-close close">×</a>
          <h3>Login User Information</h3>
        </header>
        <div class="modal-body"> <span> Login with Authority card Accepter User</span> <span><?php echo $_GET['role'];?> Has Following Permissions</span>
          <ul>
            <li>List of card registration filter between date.</li>
            <li>Download card  registration.</li>
            <li>User list of current category user.</li>
          </ul>
        </div>
        <footer> <a href="#" class="btn btn-small js-modal-close">Close</a> </footer>
      </div>
      <div id="popup7" class="modal-box">
        <header> <a href="#" class="js-modal-close close">×</a>
          <h3>Login User Information</h3>
        </header>
        <div class="modal-body"> <span>Please Login with Download Authority Agency User</span> <span> <?php echo $_GET['role'];?> Has Following Permissions</span>
          <ul>
            <li>Agency can download village data which assign to them.</li>
          </ul>
        </div>
        <footer> <a href="#" class="btn btn-small js-modal-close">Close</a> </footer>
      </div>
      <div class="login-form">
        <?php if($user->uid==0) {?>
        <?php print render($page['sidebar_first']); ?>
        <?php } ?>
      </div>
      <?php if(!empty($_SERVER['QUERY_STRING'])) { ?>
      <div class="role_mns">
        <?php 
         //echo $_GET['role'];
         if($_GET['role'] == 'Mole'){ ?>
        <h3>Login User Information</h3>
        <span>Login with <?php echo $_GET['role'];?> User</span> <span>
        <?php ?>
        MoLE  has Following Permissions</span>
        <ul>
          <li>Access All state data at village level.</li>
          <li>Add Registration Agency.</li>
          <li>Access list of Authority cards.</li>
          <li>Create user for applying authority Cards.</li>
          <li>View all users of application with different roles.</li>
          <li>Generate SSID.</li>
        </ul>
        <?php } ?>
        <?php 
         //echo $_GET['role'];
         if($_GET['role'] == 'State'){ ?>
        <span>Login with <?php echo $_GET['role'];?> User</span> <span> <?php echo $_GET['role'];?> State Has Following Permissions</span>
        <ul>
          <li>Access all district data of particular state belonging to current user login state
            (e.g if user belong to Uttar Pradesh state then he will access all district of Uttar Pradesh)on village level.</li>
          <li>Create user of Tehsil.</li>
          <li>Can View all user of current Role belonging to same state.</li>
        </ul>
        <?php } ?>
        <?php 
         //echo $_GET['role'];
         if($_GET['role'] == 'District'){ ?>
        <span>Please Login with <?php echo $_GET['role'];?> User</span> <span> <?php echo $_GET['role'];?> District Has Following Permissions </span>
        <ul>
          <li>Access All tehsil data of particular district belonging to current user login district(e.g If user belongs 
            to Uttar Pradesh state having Farrukhabad District then he will access all tehsil of Farrukhabad) On village level</li>
          <li>Permission to download village data, Agency wise permission based.</li>
          <li>Import Card creation data for IA CARD in CSV format.</li>
          <li>Import village data in CSV format.</li>
          <li>Assign Agency to download village data.</li>
          <li>Create user of agent level.</li>
          <li>User list of current category user.</li>
          <li>Check De-duplication.</li>
        </ul>
        <?php } ?>
        <?php 
         //echo $_GET['role'];
         if($_GET['role'] == 'Tehsil'){ ?>
        <span>Login with <?php echo $_GET['role'];?></span> <span><?php echo $_GET['role'];?> Has Following Permissions</span>
        <ul>
          <li>Access All Data of particular tehsil belonging to current user login tehsil 
            (e.g if user belong to Uttar Pradesh State having Kushinagar district and their particular tehsil then he will acess all village data of that tehsil.)</li>
          <li>Import Card creation data for IA CARD in CSV format.</li>
          <li>Import village data in CSV format.</li>
          <li>Get Slip of person of village</li>
          <li>Create user of agent level.</li>
          <li>User list of current categeory user.</li>
        </ul>
        <?php } ?>
        <?php 
         //echo $_GET['role'];
         if($_GET['role'] == 'Agent'){ ?>
        <span>Login with registration Agency user</span> <span>
        <?php ?>
        Registration Agency Has Following Permissions</span>
        <ul>
          <li>Permission to view/download only assigned village data.</li>
          <li>Get list of slip of person of village.</li>
          <li>User list of current categeory user.</li>
        </ul>
        <?php } ?>
        <?php 
         //echo $_GET['role'];
         if($_GET['role'] == 'Card Register'){ ?>
        <span>Login with Authority card Requester User </span> <span><?php echo $_GET['role'];?> Has Following Permissions</span>
        <ul>
          <li>Authority Card Registration request.</li>
          <li>User list of current category user.</li>
        </ul>
        <?php } ?>
        <?php 
         //echo $_GET['role'];
         if($_GET['role'] == 'Card Accept'){ ?>
        <span> Login with Authority card Accepter User</span> <span><?php echo $_GET['role'];?> Has Following Permissions</span>
        <ul>
          <li>List of card registration filter between date.</li>
          <li>Download card  registration.</li>
          <li>User list of current category user.</li>
        </ul>
        <?php } ?>
        <?php 
         //echo $_GET['role'];
         if($_GET['role'] == 'Agency'){ ?>
        <span>Please Login with Download Authority Agency User</span> <span> <?php echo $_GET['role'];?> Has Following Permissions</span>
        <ul>
          <li>Agency can download village data which assign to them.</li>
        </ul>
        <?php }  }?>
        <?php ?>
       </div>
    </div>
  </div>
  <?php if ($page['content_bottom']) : ?>
  <div class="content-bottom"><?php print render ($page['content_bottom']); ?></div>
  <?php endif; ?>
</div>
<footer id="footer">
  <div class="wrapper"> <a href="#" class="designed">Designed &amp; Developed by CMC Ltd</a> <span class="copy-rt"> Copyright © 2015 Ministry of Labour &amp; Employment 
          Website designed & developed by National Informatics Centre. <span style="float:right;">version 2.5</span></span> </div>
</footer>
