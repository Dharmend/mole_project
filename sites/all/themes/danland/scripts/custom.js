
 jQuery(document).ready(function($) {
 	$(".correction_personal_info").hide();
    $(".editseccdata").click(function(){
    	//alert('aaaaa');
        $(".correction_personal_info").slideToggle('1000');
    });
	

 $(function(){

var appendthis =  ("<div class='modal-overlay js-modal-close'></div>");

	$('a[data-modal-id]').hover(function(e) {
		e.preventDefault();
    $("body").append(appendthis);
    $(".modal-overlay").fadeTo(500, 0.7);
    //$(".js-modalbox").fadeIn(500);
		var modalBox = $(this).attr('data-modal-id');
		$('#'+modalBox).fadeIn($(this).data());
	});  
  
  
$(".js-modal-close, .modal-overlay").hover(function() {
    $(".modal-box, .modal-overlay").fadeOut(500, function() {
        $(".modal-overlay").remove();
    });
 
});
 
$(window).resize(function() {
    $(".modal-box").css({
        top: ($(window).height() - $(".modal-box").outerHeight()) / 2,
        left: ($(window).width() - $(".modal-box").outerWidth()) / 2
    });
});
 
$(window).resize();
 
});


$('#edit-e-id').blur(function(){
    //alert($(this).val());
    if($(this).val().length != 0){
        $('#edit-aadhaar').attr('disabled', 'disabled');
    } else{
     $('#edit-aadhaar').attr('disabled', false);

    }      
});

    $('#edit-aadhaar').blur(function(){
    if($(this).val().length != 0){
        $('#edit-e-id').attr('disabled', 'disabled');
    }   
    else {
     $('#edit-e-id').attr('disabled', false);
    }    
});


 $('#edit-sameasperm').click(function(){
    if($(this).is(':checked')){
        $('#edit-c-address1').attr('disabled', 'disabled');
        $('#edit-c-address2').attr('disabled', 'disabled');
        $('#edit-state-p').attr('disabled', 'disabled');
        $('#edit-district-p').attr('disabled', 'disabled');
        $('#edit-tehsil-p').attr('disabled', 'disabled');
        $('#edit-village-p').attr('disabled', 'disabled');
        $('#edit-c-pincode').attr('disabled', 'disabled');     

    } else {
         $('#edit-c-address1').attr('disabled', false);
        $('#edit-c-address2').attr('disabled', false);
        $('#edit-state-p').attr('disabled', false);
        $('#edit-district-p').attr('disabled', false);
        $('#edit-tehsil-p').attr('disabled', false);
        $('#edit-village-p').attr('disabled', false);
        $('#edit-c-pincode').attr('disabled', false); 
    }
    
});

 

	  //   $('.login-role_msg ul li a').on('click', function(){
	  // $('.role_mns').fadeIn();
   //   });

   //   $('.close').on('click', function(){
	  // $('.role_mns').fadeOut();
   //   }); 
});

 

