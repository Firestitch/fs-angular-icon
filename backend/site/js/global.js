var ST = {

	submit: function(options) {

		if($("form").valid()) {

			options = options ? options : {};

			url = "/s/dosubmit/";

			data = $("form").serializeArray();

			if(d=options.data)
				$.each(d,function(i,v) { data.push({ name: i, value: v }); });

			$.post(url,data,function(response) {

				if(response.has_success) {
					if(url=response.data.url)
						FF.util.redirect(url);
				} else if(errors=response.errors)
					alert(errors.join("\n"));
			});
		}
	}
}

$(function() {

	if(!$(".go-login").length) {
		$("input").keyup(function(e) {
			if(e.keyCode==13) 
				ST.submit();
		});
	}

	$.extend(jQuery.validator.messages, { required: "Response Required" });

	$("form").validate({	errorPlacement: function(error, element) {
									error.insertAfter($(element).parents(".go"));  
							   	}});

	$.validator.classRuleSettings = {};

	$.validator.addMethod("checkboxes", function(value, elem, param) {
		return $("[name='" + $(elem).attr("name") + "']:checked").length>0;
	},"Please select at least one option");

	$.validator.addMethod("phone", function(phone_number, element) {
		return phone_number.match(/^1?[\s\-]?\(?\d{3}\)?[\s\-]?\d{3}[\s\-]?\d{4}$/);

	}, "Please enter valid phone number");	

	$(".go").each(function() {

		$(this).find("[data-validation]").each(function() {

			var rules = { messages: {} };
			var el = $(this);
			
			$.each($(this).data("validation").split(" "),function(i,v) {
				
				rules[v] = true;

				if(message=el.data(v))
					rules.messages[v] = message;
			});

    		$(this).rules("add",rules);
		});	

	});

	$(".go-brand-field .optin-all input").click(function() {
		if(!$(this).is(":checked"))
			$(this).parents(".go-brand-field").find(".optin-individual input").attr("checked","checked");
	})

	$(".go-brand-field .optin-all input").live("change",function(e,init) {

		if($(this).is(":checked")) 
			$(this).parents(".go-brand-field").find(".optin-individual").hide();		
		else
			$(this).parents(".go-brand-field").find(".optin-individual").show();
		
	}).trigger("change",[true]);

	$(".go-dob").bind("format",function() {

		var date = $(this).find("input[type='hidden']").val();

		if(date) {
	
			var sd = date.split("-");

			date = new Date(parseInt(sd[0]),parseInt(sd[1]) - 1,parseInt(sd[2]));

			fdate = $.datepicker.formatDate("MM d yy",date);

			$(this).find(".formatted").text(fdate);
		}

	}).each(function() {

		$(this).find(".interface").each(function() {

			$(this).birthdaypicker({ fieldName: $(this).data("name"), defaultDate: $(this).data("date") });

		});

		$(this).find(".formatted").click(function() {

			$(this).parents(".go").find(".interface").show();
			$(this).hide();

		});

		$(this).trigger("format");
	
	})

	$("#site-next,#site-back").click(function() { 
		
		if($(this).is("#site-back")) {
			history.go(-1)
			return;
		}

		else if($(this).is("#site-next"))
			$("#action").val("next");

		ST.submit();
	});

	if((el=$(".go-login")).length) {

		el.bind("hide-interfaces",function() { $(".go-login .interface .method").hide(); $(".go-login .interface-password input").val("") });
		el.bind("hide-activations",function() { $(".go-login .activation,.go-login .activation .instructions").hide(); });
		el.bind("hide-reset",function() { $(".go-login .reset,.go-login .reset-send,.go-login .reset-send .email .go-login .reset-send .sms").hide(); $(".go-login .reset input,.go-login .reset-send input").val(""); });
		el.bind("hide-passwords",function() { $(".go-login .interface .interface-password").hide(); });
		el.bind("reset",function() { $(this).trigger("hide-activations").trigger("hide-interfaces").trigger("hide-reset").trigger("hide-passwords"); });

		el.find(".selection .method").click(function() {
			$(this).parents(".go-login").find("input.method").val($(this).data("method"));
		});

		el.find(".selection .facebook").click(function() {

			$(this).parents(".go-login").trigger("hide-reset");

			fb_login = function() {

				$.post("/s/dologin",$("form").serialize(),function(response) {
					
					if(response.has_success) {
						if(url=response.data.url)
							FF.util.redirect(url);					
					} else
						alert(response.errors.join("\n"));
				});
			}

			FB.login(fb_login, { scope: "email,publish_stream" } );			
		});

		el.find(".selection .email").click(function() {
			gl = $(this).parents(".go-login");
			gl.trigger("reset");
			gl.find(".interface .email").show();
			gl.find(".interface .email input").focus();
		});

		el.find(".selection .sms").click(function() {
			gl = $(this).parents(".go-login");
			gl.trigger("reset");
			gl.find(".interface .sms").show();
			gl.find(".interface .sms input").focus();
		});

		el.find(".interface .email .forgot").click(function() {
			gl = $(this).parents(".go-login");
			gl.trigger("hide-reset").trigger("hide-interfaces");
			gl.find(".reset-send,.reset-send .email").show();
			gl.find(".reset-send .email input").focus().val(gl.find(".interface .email input").val());
		});

		el.find(".interface .sms .forgot").click(function() {
			gl = $(this).parents(".go-login");
			gl.trigger("hide-reset").trigger("hide-interfaces");
			gl.find(".reset-send,.reset-send .sms").show();
			gl.find(".reset-send .sms input").focus().val(gl.find(".interface .sms input").val());	
		});		

		el.find(".interface .email input").live("keypress",function(e) {
			if(e.keyCode==13) 
				$(this).parents(".interface").find(".email .action a").trigger("click");
		});

		el.find(".interface .sms input").live("keypress",function(e) {
			if(e.keyCode==13) 
				$(this).parents(".interface").find(".sms .action a").trigger("click");
		});	

		el.find(".activation input").live("keypress",function(e) {
			if(e.keyCode==13) 
				$(this).parents(".activation").find(".action a").trigger("click");
		});	

		el.find(".interface .action a").click(function() {

			gl = $(this).parents(".go-login");
			
			$.post("/s/dologin",$("form").serialize(),function(response) {

				if(response.has_success) {
					
					if(response.data.action=="password") {

						gl.find(".interface .interface-password").show();
						gl.find(".interface .interface-password .password input").focus();

					} else if(response.data.action=="activation") {
						
						gl.trigger("hide-interfaces");
						gl.trigger("hide-activations");

						method 	= gl.find("input.method").val();

						gl.find(".activation").show();
						gl.find(".activation .instructions." + method).show();
						gl.find(".activation .input input").focus();
						
					} else if(url=response.data.url)
						FF.util.redirect(url);
					
				} else {
					fc = $(":focus");
					$(window).focus();
					alert(response.errors.join("\n"));
					
					FF.util.delay(function() {
						fc.focus();
					},200);
				}
			});
		});

		el.find(".activation .action a").click(function() {
			
			_act = $(this);

			if(_act.hasClass("processing"))
				return false;

			_act.addClass("processing");

			$.post("/s/doactivate",$("form").serialize(),function(response) {

				if(response.has_success) {
					
					if(url=response.data.url)
						FF.util.redirect(url);
					
				} else
					alert(response.errors.join("\n"));

				_act.removeClass("processing");
			});
		});

		el.find(".reset-send .action a").click(function() {

			gl = $(this).parents(".go-login");
			
			$.post("/s/doresetsend",$("form").serialize(),function(response) {

				if(response.has_success) {

					method 	= gl.find("input.method").val();

					gl.trigger("hide-reset");
					gl.find(".reset,.reset .instructions." + method).show();
					gl.find(".reset .input input").focus();

				} else
					alert(response.errors.join("\n"));
			});
		});


		el.find(".reset .action a").click(function() {

			gl = $(this).parents(".go-login");
			
			$.post("/s/doreset",$("form").serialize(),function(response) {

				if(response.has_success) {

					method 	= gl.find("input.method").val();

					gl.trigger("reset");

					gl.find(".selection ." + method).trigger("click");

					//ray@firestitch.com


				} else
					alert(response.errors.join("\n"));
			});
		});			
	}

	if((el=$(".go-offer")).length) {
		
		el.find(".delivery-routes a").click(function() {
			$(this).parents(".go-offer").find(".delivery-route").val($(this).data("dr"));
			$(this).parents(".go-offer").find(".delivery-routes a").removeClass("active");
			$(this).addClass("active");
			ST.submit();
		});
	}

	if((el=$(".go-password")).length) {

		el.find(".change-password").change(function() {
			
			if($(this).is(":checked"))
				$(this).parents(".go").find(".new-password,.old-password").show();
			else
				$(this).parents(".go").find(".new-password,.old-password").hide();
		});
	}

	if((el=$(".go-share")).length) {

		if(el.find(".selection .method.twitter").length) {

			FF.TW.load(function() {
				
				twttr.events.bind("tweet", function(event) {
					process_share();
				});
			});

			FF.TW.boot();
			
			!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");
		}

		el.bind("hide-interfaces",function() { $(".go-share .interface .method").hide(); });

		el.find(".selection .method").click(function() {
			$(this).parents(".go-share").find("input.method").val($(this).data("method"));
		});

		pr = el.find(".interface .facebook .preview");
		pr.fbpostpreview({ 	post: "",	
							link: pr.attr("data-link"), 
							caption: pr.attr("data-caption"), 
							message: el.find(".interface .facebook textarea"),
							description: pr.attr("data-description") });
		

		el.find(".selection .facebook").click(function() {
			gl = $(this).parents(".go-share");
			gl.trigger("hide-interfaces");
			gl.find(".interface .facebook").show().find("textarea").focus();
		});

		el.find(".selection .email").click(function() {
			gl = $(this).parents(".go-share");
			gl.trigger("hide-interfaces");
			gl.find(".interface .email").show();
			gl.find(".interface .email input").focus();
		});

		el.find(".selection .sms").click(function() {
			gl = $(this).parents(".go-share");
			gl.trigger("hide-interfaces");
			gl.find(".interface .sms").show();
			gl.find(".interface .sms input").focus();
		});

		el.find(".interface .email input").live("keyup",function(e) {
			if(e.keyCode==13) 
				$(this).parents(".interface").find(".email .share a").trigger("click");
		}); 

		el.find(".interface .sms input").live("keyup",function(e) {
			if(e.keyCode==13) 
				$(this).parents(".interface").find(".sms .share a").trigger("click");
		});

		process_share = function() {
			$.post("/s/doshare",$("form").serialize(),function(response) {

				if(response.has_success) {
					
					if(url=response.data.url)
						FF.util.redirect(url);				
				} else
					alert(response.errors.join("\n"));
			});
		}	

		el.find(".interface .share a").click(function() {

			gl = $(this).parents(".go-share");

			if($(this).parents(".method").hasClass("twitter"))
				return true;

			process_share();
		});
	}	

	if((el=$(".go-member-offers")).length) {

		el.find(".summary").click(function() {

			$(this).parents(".go").find(".summary").hide();
			$(this).parents(".go").find(".filters").hide();
			$(this).parents(".offer").find(".redemption").hide();
			$(this).parents(".offer").find(".view").show();
			$(this).siblings(".detail").show();
		});

		el.find(".close,.done").click(function() {

			$(this).parents(".go").find(".summary").show();
			$(this).parents(".go").find(".detail").hide();
			$(this).parents(".go").find(".filters").show();
		});	

		el.find(".view .redeem").click(function() {

			bc = $(this).parents(".offer").find(".barcode");

			bc.barcode(bc.data("code"),"code128",{ showHRI: false, output: "css", barWidth: 2 });

			$(this).parents(".offer").find(".redemption").show();
			$(this).parents(".offer").find(".view").hide();
		});

		el.find(".filters a").click(function() {
			$(this).parents(".go").find(".filters a").removeClass("selected");
			$(this).addClass("selected");

			$(this).parents(".go").find(".offers-group").hide();
			$(this).parents(".go").find(".offers-group." + $(this).data("filter")).show();
		});

		el.find(".filters a").first().click();
	}

	if((el=$(".go-member-programs")).length) {

		el.find(".summary").click(function() {

			dt = $(this).siblings(".detail");

			if(dt.is(":visible"))
				dt.hide();
			else
				dt.show();
		});
	}	

	if((el=$(".go-terms")).length) {

		el.find(".terms-toggle").toggle(function() {
			$(this).parents(".go").find(".terms").show();
			$(this).addClass("active");
		},function() {
			$(this).parents(".go").find(".terms").hide();
			$(this).removeClass("active");
		});
	}

	if((el=$(".go-survey")).length) {

		el.find(".sentiment input").change(function() {
			
			$(this).parents(".field").find("label").removeClass("active");

			if($(this).is(":checked"))
				$(this).parents(".field").find("label[for='" + $(this).attr("id") + "']").addClass("active");

		});

		el.find(".sentiment input:checked").trigger("change");

		el.find(".rating input").change(function() {
			
			$(this).parents(".field").find("label").removeClass("active");

			if($(this).is(":checked"))
				$(this).parents(".field").find("label[for='" + $(this).attr("id") + "']").addClass("active");

		});

		el.find(".rating input:checked").trigger("change");

		el.find(".yesno input").change(function() {
			
			$(this).parents(".field").find("label").removeClass("active");

			if($(this).is(":checked"))
				$(this).parents(".field").find("label[for='" + $(this).attr("id") + "']").addClass("active");

		});

		el.find(".yesno input:checked").trigger("change");		
	}

	if((el=$(".go-member-dashboard")).length) {

		$(".tiles").tiles();

		$(this).find(".tile").each(function() {

			if($(this).data("url")) {

				$(this).click(function() {
					FF.util.redirect($(this).data("url"));
				}).css("cursor","pointer");
			}
		});

	}
});