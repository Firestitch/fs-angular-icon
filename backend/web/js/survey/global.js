
$(function() {
   
    $.widget("FD.survey", {
     
		options: { 	url: "", 
					key: "" },

		_create: function() {
			
			fm = $("<form>",{ action: "javascript:;" })
				.append($("<div>",{ "class": "survey-container" }))
				.append($("<input>",{ type: "hidden", name: "gnid" }))
				.append($("<input>",{ type: "hidden", name: "key", value: this.options.key }));
			
			this.el()
				.addClass("survey")
				.html(fm);
			this.init();
		},

		form: function() 				{ return this.el().find("form"); },
		container: function() 			{ return this.el().find(".survey-container"); },
		el: function() 					{ return this.element; },
		graph_node_id: function(gnid) 	{ return gnid==undefined ? this.form().find("input[name='gnid']").val() : this.form().find("input[name='gnid']").val(gnid); },

		init: function() {

			$.ajax({	survey: this,
						url: this.options.url,
						data: this.post("init"),
						type: "POST",
						success: function(response) {
							var survey = this.survey.draw(response);

							this.survey.el()
								.width(response.data.width)
								.height(response.data.height);
							
							parent.postMessage({ action: "resize", height: response.data.height, width: response.data.width },"*");

							$("head").append($("<link>",{ rel: "stylesheet", type: "text/css", href: response.data.css }));
						}});
		},

		submit: function() {

			$.ajax({	survey: this, 
						url:  survey.options.url,
						data: survey.post("submit"),
						type: "POST",
						success: function(response) {
							var survey = this.survey.draw(response);
						}
			});
		},

		draw: function(response) {

			survey = this;
			this.el()
				.css("background","url('" + response.data.background + "')")
				.css("background-size","100% 100%");
			
			this.container().empty();
			this.graph_node_id(response.data.gnid);

			this.container().attr("data-position",response.data.position);

			$(response.data.objects).each(function(i,object) {

				/*
				$.getJSON("http://speech.jtalkplugin.com/api/?callback=?", {speech: object.name, usecache: true },
				function(json) {
					if (json.success == true) {

					    $("#jquery_audioPlayer").jPlayer({
					        swfPath: "../js",
					        wmode: "window"
					    });

					    $('#jquery_audioPlayer').jPlayer("setMedia", { mp3: json.data.url });
					    $('#jquery_audioPlayer').jPlayer("supplied", "mp3");
					    $('#jquery_audioPlayer').jPlayer("play");    

					} else {
						alert("Error:" + json.msg);
					}
				});
				*/

				survey.interface(object);
			});

			if(response.data.submit)
				this.container()
						.append($("<a>",{ href: "javascript:;",id: "next" })
									.data("survey",this)
									.click(function() {
										$(this).data("survey").submit();
									})
									.text("Next"));
		},	

		interface: function(object) {

			//nm = $("<div>",{ "class": "name" }).html(object.name);
			//it = $("<div>",{ "class": "interface" }).html(object.interface);

			it = $(object.interface);

			this.container().append($("<div>",{ "class": "go" }).append(it));
			it.find("select,input[type='radio']").change($.proxy(this,"submit"));
		},

		post: function(action,post) {

			post = this.form().serializeArray();
			post.push({ name: "action", value: action });

			return post;
		}

    });

    $("#survey").survey({ url: "/manage/dosurveypreview", key: FF.request.get("key") });

 });