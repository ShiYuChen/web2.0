$ = function(id)
{
	return document.getElementById(id);
}

$$ = function(selector)
{
	return document.querySelectorAll(selector);
}




window.onload = function()
{
	var gamestart =  false;
	var boundarys = [];
	boundarys = $$("div#maze div.boundary");
	$("start").onmouseover = function()
	{
		if (!gamestart)
		{
			gamestart = true;
		}

		for (var i = 0; i < boundarys.length; i++)
		{
			boundarys[i].onmouseover = function()
			{
				if (gamestart)
				{
					gamestart = false;
					for (var j = 0; j < boundarys.length; j++)
					{
						boundarys[j].style.backgroundColor = "red";
					}
					document.getElementById('status').innerHTML = "You Lose!";
					event.stopPropagation();
				}
			}
		}
	}


	$$("div#maze").onmouseout = function()
	{
		if (gamestart)
		{
			gamestart = false;
			for (var j = 0; j < boundarys.length; j++)
			{
				boundarys[j].style.backgroundColor = "red";
			}
			document.getElementById('status').innerHTML = "You Lose!";
		}
	}

	$("end").onmouseover = function()
	{
		if (gamestart)
		{
			gamestart = false;
			document.getElementById('status').innerHTML = "You Win!";
			for (var i = 0; i < boundarys.length; i++)
			{
						boundarys[i].style.backgroundColor = "#8888ff";
			}
		}
	}


	$("start").onclick = function()
	{
		for (var i = 0; i < boundarys.length; i++)
		{
			boundarys[i].style.backgroundColor = "#88ff88";
		}
		document.getElementById('status').innerHTML = "Move your mouse over the \"S\" to begin.";
	}

}