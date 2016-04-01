<?php
/**
 * @file
 * Responsive Green theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/garland.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to main-menu administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 */
?>

<div class="wrapper common-wrapper">
	<div class="container common-container">
    	<div class="common-left clearfix">
        	<ul>
            	<li class="gov-india"><a target="_blank" href="http://india.gov.in" title="National Portal of India, External Link that opens in a new window"><span>भारत सरकार</span>GOVERNMENT OF INDIA</a></li>
                <li class="ministry"><span>श्रम एवं रोजगार मंत्रालय </span>Ministry of Labour &amp; Employment</li>
            </ul>			
        </div>
        <div class="common-right clearfix">
        	<ul id="header-nav">
           		<li class="ico-skip   "><a href="#skipCont" title="Skip to main content"></a></li>
            	<li class="ico-accessibility            "><a href="javascript:void(0);" id="toggleAccessibility" title="Accessibility Dropdown"></a>
                	<ul>
                     <li> <a onclick="set_font_size('increase')" title="Increase font size" href="javascript:void(0);">A<sup>+</sup></a> </li>
                        <li> <a onclick="set_font_size('')" title="Reset font size" href="javascript:void(0);">A<sup>&nbsp;</sup></a> </li>
                        <li> <a onclick="set_font_size('decrease')" title="Decrease font size" href="javascript:void(0);">A<sup>-</sup></a> </li>
                        <li> <a href="javascript:void(0);" class="high-contrast dark" title="High Contrast">A</a> </li>
                        <li> <a href="javascript:void(0);" class="high-contrast light" title="Normal Contrast" style="display: none;">A</a> </li>
                     
                    </ul>
                </li>
                <li class="ico-social           "><a href="javascript:void(0);" id="toggleSocial" title="Social Media's"></a>
                <ul>	
                  <li><a target="_blank" href="javascript:void(0)"><img alt="Facebook, External Link that opens in a new window" src="assets/images/ico-facebook.png"></a></li>
                  <li><a target="_blank" href="javascript:void(0)"><img alt="Twitter, External Link that opens in a new window" src="assets/images/ico-twitter.png"></a></li>
                  <li><a target="_blank" href="javascript:void(0)"><img alt="youtube, External Link that opens in a new window" src="assets/images/ico-youtube.png"></a></li>
                </ul>
                </li>
                <li class="ico-site-search   "><a href="javascript:void(0);" id="toggleSearch" title="Site Search"></a>
                	<ul class="search-drop" style="display: none;">
                        <li>
                            <a></a>
                            <input type="text" placeholder="Search">
                            <input type="submit" class="bttn-search" value="go">
                        </li>
                    </ul>
                </li>
                <li class="ico-sitemap"><a href="javascript:void(0);" title="Sitemap"></a></li>
                <li class="hindi"><a href="javascript:void(0);" title="Link to Hindi version">हिन्दी</a></li>
            </ul>
        </div>
    </div>
</div>
<section class="wrapper header-wrapper">
	<div class="container header-container">
    	<h1 class="logo"><a href="javascript:void(0)"></br><strong> मुख्य श्रम आयुक्त </strong> Chief Labour Commissioner </span></a></h1>
        <a href="javascript:void(0);" class="toggle-nav-bar">
        <span class="menu-icon"></span>
        <span class="menu-text">Menu</span>
    </a>	
        <div class="header-right clearfix">
            <div class="right-content clearfix">
                <div class="float-element">
                    <a target="_blank" href="https://swachhbharat.mygov.in/" title="Swachh Bharat, External Link that opens in a new window" class="sw-logo"><img src="http://10.21.173.61:8080/ilc/sites/default/files/swach-bharat.png"></a>
                </div>
            </div>
        </div>
		<!--<div style="font-size:32px; color:black; font-family:lota;float:right;">
		<strong><h1>INDIAN LABOUR CONFERENCE</h1></strong>
		</div>-->
    </div>
</section>
    <div class="clear"></div>
  </header>
  <div class="menu_wrapper">
      <nav id="main-menu"  role="navigation">
        <a class="nav-toggle" href="#">Navigation</a>
        <div class="menu-navigation-container">
          <?php print drupal_render($main_menu_tree); ?>
        <div class="clear"></div>
      </nav><!-- end main-menu -->
  </div>
</div>
<div id="container">
    <?php if ($is_front): ?>
    <?php if ($sdisplay): ?>
    <div id="home-slider">
      <div class="flexslider-container">
        <div id="single-post-slider" class="flexslider">
          <ul class="slides">
            <li class="slide" style="display:none;"><img src="<?php print $img1;?>"alt="Slide2"/></li>
            <li class="slide" style="display:none;"><img src="<?php print $img2;?>"alt="Slide2"/></li>
            <li class="slide" style="display:none;"><img src="<?php print $img3;?>" alt="Slide3"/></li>
          </ul><!-- /slides -->
        </div><!-- /flexslider -->
      </div>
    </div>
    <?php endif; ?>
    <div class="Slideshow-region"><?php print render($page['slideshow']); ?></div>
    <?php if (!empty($page['top_first'])): $num1 = 1;  endif; ?>
    <?php if (!empty($page['top_second'])): $num2 = 1;  endif; ?>
    <?php if (!empty($page['top_third'])): $num3 = 1;  endif; ?>
    <?php
      $sum = (isset($num1) . isset($num2) . isset($num3));
      $result = strlen($sum);
      if ($result == 1):$value = "one";endif;
      if ($result == 2):$value = "two";endif;
      if ($result == 3):$value = "three";endif;
      ?>
    
    <?php endif; ?>
<div class="minister-right-content"style="float:right; width:25%;">
    <div class="minister clearfix" style="padding: 0 30px;width: 100%;">
    	<div class="minister-holder" style=" background: #9fb2c0 none repeat scroll 0 0;
			padding: 30px 37px 22px; float:right; margin-right:5px; margin-top:45px;text-align: center;">
        	<div class="minister-image"><img alt="" src="/ilc/sites/all/themes/responsive_green/images/minister-img-1.jpg">
			</div>
            <div class="minister-name"style=" line-height: 95%;
			padding: 10px 10px 0;"><span style="color: #000;display: block;font-weight: 600;">Hon’ble MoS </span><br>Sh. Bandaru Dattatreya
 			<br><kbd>(Independent Charge)</kbd>
			</div>
		</div>
		<div class="budget-container" style=" padding: 0 0 22px;text-align: center;">
        	<div class="budget-holder"style=" color: #fff;margin: 30px auto 0;min-height: 150px;position: relative;text-align: left;width: 100%;">
				<img src="/ilc/sites/all/themes/responsive_green/images/budget_bg.png" style=" border: 0 none;
				height: auto;max-width: 100%;vertical-align: middle;margin-top:50px;margin-right:50px;">
				<div class="budget-holder-content" style="bottom: 20px;margin: 0 10px 66px 30px;position: absolute;">
					<h2 style=" color: #fff;font-size: 130%;font-weight: 400;line-height: 115%;margin-bottom: 5px;text-transform: uppercase;">Budget</h2>
					<ul style="list-style: outside none none;">
					<li style="background: rgba(0, 0, 0, 0) url(/ilc/sites/all/themes/responsive_green/images/budget_arrow.png) no-repeat scroll 0 5px;
					padding-left: 15px;"><a href="javascript:void(0)" style=" color: #fff;font-weight: 300;">Detailed Demand For Grants</a></li>
					<li style="background: rgba(0, 0, 0, 0) url(/ilc/sites/all/themes/responsive_green/images/budget_arrow.png) no-repeat scroll 0 5px;
					padding-left: 15px;"><a href="javascript:void(0)" style="color: #fff;font-weight: 300;">Outcome Budget</a></li>
					</ul>
				</div>
            </div>
        </div>
	</div>
</div>
	
<div id="footer" style=" font-family:Lato; background:rgba(0, 0, 0, 0.2) none repeat scroll 0 0; color:white; border-top:1px solid #cfd7db; text-align:center;">
	<div class="bg-wrapper box-wrapper">
		<div style="background:rgba(0,0,0,0) url(/ilc/sites/all/themes/responsive_green/images/imp_h_bg.png) repeat scroll 0 0; box-sizing:border-box;
			color: #fff;font-size: 180%;font-weight: 700;padding: 20px 0;text-align: center;text-transform: uppercase;">
			<h2>Important links</h2>
		</div>
		<div class="imp-links-holder">
			<div class="imp-links-glow-holder" style="width:100%; padding:20px 0;background:rgba(0,0,0,0) url(/ilc/sites/all/themes/responsive_green/images/imp_bg.png) repeat scroll 0 0;">
				<div class="container box-container" >
				<ul style="list-style: outside none none;">
				<li class="box-ico-1"style="  float: left; padding-bottom: 30px; padding-top: 120px;text-align: center;transition: all 0.2s ease-in-out 0s; width: 20%; background-image: url(/ilc/sites/all/themes/responsive_green/images/imp-link-img-1.png); background-position: center 40px;    background-repeat: no-repeat;">
				<span style="color: #fff;display: inline-block;font-size: 120%;height: 32px;margin: 20px 0;">Wages and Statistics </span>
				<br><a class="read-more" href="javascript:void(0)" style="border: 1px solid #c5c4c4;color: #fff;display: inline-block;font-size: 92%;
				font-weight: 300;line-height: 140%;padding: 10px;">Read More <i class="fa fa-angle-double-right"style="content: ;"></i></a></li>
				<li class="box-ico-2"style="float: left; padding-bottom: 30px; padding-top: 120px;text-align: center;transition: all 0.2s ease-in-out 0s; width: 20%; background-image: url(/ilc/sites/all/themes/responsive_green/images/imp-link-img-2.png); background-position: center 40px;
				background-repeat: no-repeat;"><span style="color: #fff; display: inline-block;font-size: 120%; height: 32px;
				margin: 20px 0;">Controller of Accounts </span>
				<br><a class="read-more" href="javascript:void(0)"style="border: 1px solid #c5c4c4;color: #fff;display: inline-block;font-size: 92%;
				font-weight: 300;line-height: 140%;padding: 10px;">Read More <i class="fa fa-angle-double-right"style="content: ;"></i></a></li>
				<li class="box-ico-3"style="float: left; padding-bottom: 30px; padding-top: 120px;text-align: center;transition: all 0.2s ease-in-out 0s; width: 20%; background-image: url(/ilc/sites/all/themes/responsive_green/images/imp-link-img-3.png); background-position: center 40px;
				background-repeat: no-repeat;"><span style="color: #fff;
				display: inline-block;font-size: 120%;height: 32px;
				margin: 20px 0;">Organizations of MOL&amp;E </span><br><a class="read-more" href="javascript:void(0)"style="border: 1px solid #c5c4c4;color: #fff;display: inline-block;font-size: 92%;
				font-weight: 300;line-height: 140%;
				padding: 10px;">Read More <i class="fa fa-angle-double-right"style="content: ;"></i></a></li>
				<li class="box-ico-4"style="float: left; padding-bottom: 30px; padding-top: 120px;text-align: center;transition: all 0.2s ease-in-out 0s; width: 20%; background-image: url(/ilc/sites/all/themes/responsive_green/images/imp-link-img-4.png); background-position: center 40px;
				background-repeat: no-repeat;"><span style="color: #fff;display: inline-block;font-size: 120%;height: 32px;margin: 20px 0;">Awards</span>
				<br><a class="read-more" href="javascript:void(0)"style="border: 1px solid #c5c4c4;color: #fff;display: inline-block;font-size: 92%;
				font-weight: 300;line-height: 140%;padding: 10px;">Read More <i class="fa fa-angle-double-right"style="content: ;"></i></a></li>
				<li class="box-ico-5"style="float: left; padding-bottom: 30px; padding-top: 120px;text-align: center;transition: all 0.2s ease-in-out 0s; width: 20%; background-image: url(/ilc/sites/all/themes/responsive_green/images/imp-link-img-5.png); background-position: center 40px;
				background-repeat: no-repeat;"><span style="color: #fff; display: inline-block;font-size: 120%;height: 32px;
				margin: 20px 0;">Photo Gallery </span><br><a class="read-more" href="javascript:void(0)"style="border: 1px solid #c5c4c4;color: #fff;display: inline-block;font-size: 92%;
				font-weight: 300;line-height: 140%;padding: 10px;">Read More <i class="fa fa-angle-double-right"style="content: ;"></i></a></li>
				</ul>
				</div>
			</div>
		</div>
	</div>
</div>


<section class="wrapper logo-carousel-wrapper">
	<div class="container carousel-container">
    	<div class="flexslider carousel" id="flexCarousel-logo">
            
			<div class="flex-viewport" style="overflow: hidden; position: relative;">
				<ul class="slides" style="width: 2400%; transition-duration: 0.6s; transform: translate3d(-2115px, 0px, 0px);">
				<li style="width: 290px; float: left; display: block; border: 20px solid white;">
				<img alt="" src="/ilc/sites/all/themes/responsive_green/images/slider-logo-directorate.png" draggable="false"></li>
				<li style="width: 290px; float: left; display: block; border: 20px solid white;">
				<img alt="" src="/ilc/sites/all/themes/responsive_green/images/slider-logo-ilo.png" draggable="false"></li>
				<li style="width: 290px; float: left; display: block; border: 20px solid white;">
				<img alt="" src="theme/images/slider-logo-parliment.png" draggable="false"></li>
				<li style="width: 290px; float: left; display: block; border: 20px solid white;">
				<img alt="" src="/ilc/sites/all/themes/responsive_green/images/slider-logo-state-gov.png" draggable="false"></li>
				<li style="width: 290px; float: left; display: block; border: 20px solid white;">
				<img alt="" src="/ilc/sites/all/themes/responsive_green/images/slider-logo-directorate.png" draggable="false"></li>
				<li style="width: 290px; float: left; display: block; border: 20px solid white;">
				<img alt="" src="/ilc/sites/all/themes/responsive_green/images/slider-logo-ilo.png" draggable="false"></li>
				<li style="width: 290px; float: left; display: block; border: 20px solid white;">
				<img alt="" src="/ilc/sites/all/themes/responsive_green/images/slider-logo-parliment.png" draggable="false"></li>
				<li style="width: 290px; float: left; display: block; border: 20px solid white;">
				<img alt="" src="/ilc/sites/all/themes/responsive_green/images/slider-logo-state-gov.png" draggable="false"></li>
				<li style="width: 290px; float: left; display: block; border: 20px solid white;">
				<img alt="" src="/ilc/sites/all/themes/responsive_green/images/slider-logo-directorate.png" draggable="false"></li>
				<li style="width: 290px; float: left; display: block; border: 20px solid white;">
				<img alt="" src="/ilc/sites/all/themes/responsive_green/images/slider-logo-ilo.png" draggable="false"></li>
				<li style="width: 290px; float: left; display: block; border: 20px solid white;">
				<img alt="" src="/ilc/sites/all/themes/responsive_green/images/slider-logo-parliment.png" draggable="false"></li>
				<li style="width: 290px; float: left; display: block; border: 20px solid white;">
				<img alt="" src="/ilc/sites/all/themes/responsive_green/images/slider-logo-state-gov.png" draggable="false"></li>
				</ul>
		  </div> 
		  <!--/.<ol class="flex-control-nav flex-control-paging"><li><a class="">1</a></li><li><a class="">2</a></li><li><a class="">3</a></li><li><a class="">4</a></li><li><a class="">5</a></li><li><a class="">6</a></li><li><a class="">7</a></li><li><a class="">8</a></li><li><a class="flex-active">9</a></li></ol>-->
		  <ul class="flex-direction-nav"><li class="flex-nav-prev"><a href="#" class="flex-prev">Previous</a></li><li class="flex-nav-next"><a href="#" class="flex-next flex-disabled" tabindex="-1">Next</a></li></ul>
		</div>
    </div>
</section>

<section class="wrapper carousel-wrapper" style="border:10px solid lightgrey;">
	<div class="container carousel-container">
    	<div class="flexslider carousel" id="flexCarousel">
            
			<div class="flex-viewport" style="overflow: hidden; position: relative;">
			 <ul class="slides" style="width: 1200%; transition-duration: 0.6s; transform: translate3d(0px, 0px, 0px);">
             <li style="width: 200px; float: left; display: block;">
			 <a title="National Portal of India, External Link that opens in a new window" href="http://india.gov.in/" target="_blank">
			 <img alt="" src="/ilc/sites/all/themes/responsive_green/images/india-gov.png" draggable="false"></a></li>
             <li style="width: 200px; float: left; display: block;">
			 <a title="Data portal, External Link that opens in a new window" href="https://data.gov.in/" target="_blank">
			 <img alt="" src="/ilc/sites/all/themes/responsive_green/images/data-gov.png" draggable="false"></a></li>
             <li style="width: 200px; float: left; display: block;">
			 <a title="Make In India, External Link that opens in a new window" href="http://www.makeinindia.com/" target="_blank">
             <img alt="" src="/ilc/sites/all/themes/responsive_green/images/makeinindia.png" draggable="false"></a></li>
             <li style="width: 200px; float: left; display: block;">
			 <a title="Incredible India, External Link that opens in a new window" href="http://www.incredibleindia.org/en/" target="_blank">
             <img alt="" src="/ilc/sites/all/themes/responsive_green/images/incredible-india.png" draggable="false"></a></li>
             <li style="width: 200px; float: left; display: block;">
			 <a title="MyGov, External Link that opens in a new window" href="https://mygov.in/" target="_blank">
			 <img alt="" src="/ilc/sites/all/themes/responsive_green/images/mygov.png" draggable="false"></a></li>            
             <li style="width: 200px; float: left; display: block;">
			 <a title="Prime Minister's National Relief Fund, External Link that opens in a new window" href="https://pmnrf.gov.in/" target="_blank">
			 <img alt="" src="/ilc/sites/all/themes/responsive_green/images/pmnrf.png" draggable="false"></a></li>
             </ul>
			</div>
		  <ol class="flex-control-nav flex-control-paging">
		  <li><a class="flex-active">1</a></li><li><a class="">2</a></li>
		  </ol>
		  <ul class="flex-direction-nav">
		  <li class="flex-nav-prev"><a href="#" class="flex-prev flex-disabled" tabindex="-1">Previous</a></li>
		  <li class="flex-nav-next"><a href="#" class="flex-next" tabindex="-1">Next</a></li>
		  </ul>
		</div>
    </div>
</section>


<footer class="wrapper footer-wrapper">
	<div class="footer-top-wrapper" style="border:2px solid black;">
    	<div class="container footer-top-container">
        	<ul>
            	<li><a href="http://tempweb2363.nic.in/m054lnkd/home.html#">Website Policies</a></li>
                <li><a href="http://tempweb2363.nic.in/m054lnkd/home.html#">Terms of Use</a></li>
                <li><a href="http://tempweb2363.nic.in/m054lnkd/home.html#">Help</a></li>
                <li><a href="http://tempweb2363.nic.in/m054lnkd/home.html#">Contact Us</a></li>
                <li><a href="http://tempweb2363.nic.in/m054lnkd/home.html#">Feedback</a></li>
                <li><a href="http://tempweb2363.nic.in/m054lnkd/home.html#">Visitor´s Summary</a></li>
            </ul>
        </div>
    </div>
    <div class="footer-bottom-wrapper">
    	<div class="container footer-bottom-container">
            <div class="footer-content clearfix">
            
            <div class="copyright-content">
            	Website Content Managed by Ministry of Labour and Employment, GoI
             <span>Designed, Developed and Hosted by  <a target="_blank" title="NIC, External Link that opens in a new window" href="http://www.nic.in/">National Informatics Centre</a> ( NIC )</span>
            </div>        
			 <div class="logo-cmf">
            	 <a href="javascript:void(0)" target="_blank"><img src="/ilc/sites/all/themes/responsive_green/images/cmf-logo.png" alt=""></a>
             </div>
            </div>        	
        </div>
    </div>
</footer><!--/.footer-wrapper-->	