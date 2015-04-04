$ = function(id)
{
	return document.getElementById(id)
}

var size = "12pt";

function pt()
{
	if (parseInt(size) <= 24)
	{
		var text = $("textarea");
	    text.style.fontSize = size;
	    size = parseInt(size);
	    size = (size + 2) + "pt";
	    setTimeout("pt()",500);		
	}

}

function wet()
{
	if ($("Bling").checked)
	{
		var text = $("textarea");
		text.className = "Blingck";
		var body = $("bg");
		body.className = "bg";
	}
	else
	{
		var text = $("textarea");
		text.className = "Blinguck";
		var body = $("bg");
		body.className = "body";
	}
}

function snoo()
{
	$("textarea").value = $("textarea").value.toUpperCase();	
	var text = $("textarea").value;
	var parts = text.split(".");
	$("textarea").value = parts.join("-izzle.");
}

function Malk()
{
	var text = $("textarea").value;
	var words = $("textarea").value.match(/[A-Za-z]+/g);
	for (var i = 0; i < words.length; i++)
	{
		if (words[i].length >= 5)
		{
			text = text.replace(words[i], "Malkovich");
		}
	}
	$("textarea").value = text;
}

function IA()
{
	var text = $("textarea").value;
	var words = $("textarea").value.match(/[A-Za-z]+/g);
	for (var i = 0; i < words.length; i++)
	{
		if (words[i][0] == "a" || words[i][0] == "e" || words[i][0] == "i" || words[i][0] == "o" || words[i][0] == "u")
			text = text.replace(words[i], words[i] + "ay");
		else
		{
			text = text.replace(words[i], words[i].substr(1) + words[i][0] + "ay");
		}
	}
	$("textarea").value = text;
}

window.onload = function()
{
	$("button").onclick = pt;
	$("Bling").onclick = wet;
	$("snoopify").onclick = snoo;
	$("Malkovitch").onclick = Malk;
	$("ia").onclick = IA;
}

