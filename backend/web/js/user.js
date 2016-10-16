
$(function() {

if((el=$("#body-user-login")).length) {

    el.find(".fb-login").click(function() {

		LT.spin.start();
		scope = $(this).data("scope");

		FB.getLoginStatus(function(response) {

			if(response.authResponse)
				FF.util.redirect("/");
		 	else {

		    	FB.login(function(response) {

		      		if(response.authResponse)
		        		FF.util.redirect("/");
			    }, { scope: scope } );
			}
		});
	});    
}

if((el=$("#body-user-forgot")).length) {

	el.find("input").keypress(function(e) {
	    if(e.which==13) {
	        $(this).blur();
	        $("#continue").trigger("click");
	    }
	});

	el.find("#continue").click(function() {

	     $.post("/user/doforgot",$("form").serialize(),function(response) {
	        
	        if(response.has_success) {
	    		FF.util.redirect("/user/resetcode");
	        } else
	            FF.msg.error(response.errors);
	        });

	});
}

if((el=$("#body-user-reset")).length) {

	el.find("input").keypress(function(e) {
	    if(e.which==13) {
	        $(this).blur();
	        $("#reset").trigger("click");
	    }
	});

	el.find("#reset").click(function() {

	    $.post("/user/doreset",$("form").serialize(),function(response) {
	        
	        if(response.has_success) {
	    		FF.util.redirect(response.data.url);
	        } else
	            FF.msg.error(response.errors);
	    });

	});
}


if((el=$("#body-user-resetcode")).length) {

	el.find("input").keypress(function(e) {
	    if(e.which==13) {
	        $(this).blur();
	        $("#continue").trigger("click");
	    }
	});

	el.find("#continue").click(function() {

	    $.post("/user/doresetcode",$("form").serialize(),function(response) {
	        
	        if(response.has_success) {
	    		FF.util.redirect(response.data.url);
	        } else
	            FF.msg.error(response.errors);
	    });

	});
}
});















