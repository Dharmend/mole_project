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
          <?php print drupal_render($main_menu_tree);//$main_menu_tree ?>
        <div class="clear"></div>
      </nav><!-- end main-menu -->
  </div>
</div>
<div id="container">
    <?php if ($is_front): ?>
	
    <div class="Slideshow-region" ><?php print render($page['slideshow']); ?><div class="whatsnew" style='float: right;    height: 350px;    overflow: auto;'><?php print render($page['whatsnew']); ?></div></div>
	
    <?php endif; ?>



<section class="wrapper carousel-wrapper" style="border:10px solid lightgrey;clear: both;">
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