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
	display();
	$("shufflebutton").onclick = rand;
}

var puzzlepieces;
var table = [];

function display()
{
	puzzlepieces = $$("#puzzlearea div");
	for (var i = 0; i < puzzlepieces.length; i++)
	{
		puzzlepieces[i].id = i;
		puzzlepieces[i].className = "puzzlepiece";
		set_position(puzzlepieces[i], i);
		table[i] = 1;
	}
	table[15] = 0;
	for (var i = 0; i < 15; i++)
	{
		play(i);
		target(i);
		untarget(i);
	}
}

function set_position(piece, number)
{
	var x = Math.floor(number / 4) * 100;
	var y = number % 4 * 100;
	piece.style.top = x + "px";
	piece.style.left = y + "px";
	piece.style.backgroundPosition = (400 - y) + "px" + " " + (400 - x) + "px";
}

function empty(start)
{
	var k;
	for (k = 0; k < 16; k++)
	{
		if (table[k] == 0)
		{
			break;
		}
	}

	if ((start % 4 != 0 && start - 1 == k) || (start % 4 != 3 && start + 1 == k) || (start + 4 == k) || (start - 4 == k))
	{
		return k;
	}
	return -1;
}


function move(piece, next)
{
	var x = Math.floor(next / 4) * 100;
	var y = next % 4 * 100;
	piece.style.top = x + "px";
	piece.style.left = y + "px";
	table[next] = 1;
	table[piece.id] = 0;
	piece.id = next;
}


function play(i)
{
	puzzlepieces[i].onclick = function()
	{
		var index = empty(parseInt(puzzlepieces[i].id));
		if (index != -1)
		{
			move(puzzlepieces[i],index);
			success();
		}
	}
}


function target(i)
{
	puzzlepieces[i].onmouseover = function()
	{
		var index = empty(parseInt(puzzlepieces[i].id));
		if (index != -1)
		{
			puzzlepieces[i].style.borderColor = "red";
			puzzlepieces[i].style.color = "#006600";
			puzzlepieces[i].style.textDecoration = "underline";
		}
	}
}

function untarget(i)
{
		puzzlepieces[i].onmouseout = function()
	{
		var index = empty(parseInt(puzzlepieces[i].id));
		if (index != -1)
		{
			puzzlepieces[i].style.borderColor = "black";
			puzzlepieces[i].style.color = "black";
			puzzlepieces[i].style.textDecoration = "none";
		}
	}
}

function rand()
{
	document.body.style.backgroundColor = "white";
	$("title").innerHTML = "CSE 190 M Fifteen Puzzle";
	for (var n = 0; n < 500; n++)
	{
		i = Math.floor(Math.random() * 15);
		var index = empty(parseInt(puzzlepieces[i].id));
		if (index != -1)
		{
			move(puzzlepieces[i],index);
		}
	}
}


function success()
{
	var i = 0;
	for (; i < puzzlepieces.length; i++)
	{
		if (parseInt(puzzlepieces[i].id) != i)
		{
			i = i - 1;
			break;
		}
	}
	if (i == 15)
	{
		document.body.style.backgroundColor = "orange";
		$("title").innerHTML = "Congratulations! You win!";
	}
}
