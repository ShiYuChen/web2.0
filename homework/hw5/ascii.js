var Custom =
" o                                                  o\n" +
"/|\\                                                /|\\\n" +
"| \\                                                / |\n" +
"=====\n" +
"	  o                                        o\n" +
"	 /|-                                      -|\\\n" +
"	 / /                                      \\ \\\n" +
"=====\n" +
"		  o                              o\n" +
"		 /|-                            -|\\\n" +
"		 / /                            \\ \\\n" +
"=====\n" +
"			  o                   o\n" +
"			 /|-                 -|\\\n" +
"			 / \\                 / \\\n" +
"=====\n" +
"				    o        o\n" +
"				   /|-      -|\\\n" +
"				   | |      | |\n" +
"=====\n" +
"				      o❤o\n" +
"				     /|--|\\\n" +
"				     | || |\n" +
"=====\n" +
"                                    oo\n" +
"                                   |\\/|\n" +
"                                   ||||\n"


ANIMATIONS["Custom"] = Custom;

$ = function(id)
{
	return document.getElementById(id)
}

str = ANIMATIONS["Blank"];
sub = str.split("=====\n");
len = sub.length;
current = 0;
on = false;
time = 1000;

function start()
{
	if (on) return;
	on = true;
	text = $("displayarea");
	timer = setInterval(next, time);
}

function next()
{
	if (current == len) {
	    current = 0;
	}
	text.value = sub[current];
	current++;
}

function stop()
{
	if (!on) return;
	clearInterval(timer);
	on = false;
}

function animation()
{
	str = ANIMATIONS[this.value];
	sub = str.split("=====\n");
	len = sub.length;
	current = 0;
}

function size()
{
	text = $("displayarea");
	text.style.fontSize = this.value + "pt";
}

//speed
function speed()
{
	if (time == 1000)
		time = 200;
	else
		time = 1000;

	if (!on) return;
    clearInterval(timer);
    timer = setInterval(next, time);
}

window.onload = function()
{
	$("start").onclick = start;
	$("stop").onclick = stop;
	$("animation").onchange = animation;
	var allsize = document.getElementsByName("size");
	allsize[0].onclick = size;
	allsize[1].onclick = size;
	allsize[2].onclick = size;
	$("speed").onclick = speed;
}