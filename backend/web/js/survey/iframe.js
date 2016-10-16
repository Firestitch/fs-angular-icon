
var scripts = document.getElementsByTagName("script");

matches = scripts[scripts.length-1].src.match(/\?(.*)/);

gets = [];
if(match=matches[1]) {

 	params = match.split("&");
 	for(i=0;i<params.length;i++) {
 		param = params[i].split("=");
 		gets[param[0]] = (param[1]===undefined ? "" : param[1]);
 	}	
}

key = gets["key"] ? gets["key"] : null;

ifrm = document.createElement("iframe"); 
ifrm.setAttribute("src","http://" + document.location.host + "/survey/view/key:" + key); 
ifrm.style.width = 640+"px"; 
ifrm.style.height = 480+"px"; 
ifrm.style.border = 0;
ifrm.id = "survey-iframe";
ifrm.style.padding = 0;
ifrm.style.margin = 0;
ifrm.scrolling = "no";

window.addEventListener("message", function(e) {

    if (e.data.action == "resize") {
        var ifrm = document.getElementById("survey-iframe");
        ifrm.style.width = e.data.width + "px";
        ifrm.style.height = e.data.height + "px";
    }
}, false);

document.body.appendChild(ifrm); 

