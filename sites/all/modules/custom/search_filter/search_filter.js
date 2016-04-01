  jQuery(document).ready( function($){

   $('#eid_field').blur(function(){
    if($(this).val().length != 0){
        $('#aadhar_field').attr('disabled', 'disabled');
    }       
});

    $('#aadhar_field').blur(function(){
    if($(this).val().length != 0){
        $('#eid_field').attr('disabled', 'disabled');
    }       
});
    });


