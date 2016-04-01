    (function ($) {
      Drupal.behaviors.ajax_example = {
        attach:function (context) {
     
          // If the site name is present set it to the username.
          $('#download_file').click(function(){
           //var state = $.session.get('dow_state_value');
                 var state = $('#edit-state option:selected').val();
                 var district = $('#edit-district option:selected').val();
                 var tehsil = $('#edit-tehsil option:selected').val();
                 var village = $('#edit-village option:selected').val();
                var house_hold_id = state+district+tehsil+village;

           //alert(house_hold_id);
     $.ajax({
              type:'POST',
              url: '/csv/'+house_hold_id+'/download',
              success: function(data) {
                alert(data);
     
             }
            });
      }); 

          
        }
      }
    })(jQuery);