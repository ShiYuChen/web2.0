$(document).ready(function() {
    display();
	$("#shufflebutton").click(rand);
});

var table = [];

function display() {
	$("#puzzlearea div").each(function (i) {
		this.id = i;
		this.className = "puzzlepiece";
		set_position(this, i);
		table[i] = 1;
	});
	table[15] = 0;
	$("#puzzlearea div").each(function() {
		$(this).click(function() {
			var index = empty(parseInt(this.id));
			if (index != -1) {
				move(this,index);
				success();
			}
		});

		$(this).mouseover(function() {
			var index = empty(parseInt(this.id));
			if (index != -1) {
				this.style.borderColor = "red";
				this.style.color = "#006600";
				this.style.textDecoration = "underline";
			}
		});

		$(this).mouseout(function() {
			var index = empty(parseInt(this.id));
			if (index != -1) {
				this.style.borderColor = "black";
				this.style.color = "black";
				this.style.textDecoration = "none";
			}
		});
	});
}

function set_position(piece, number) {
	var x = Math.floor(number / 4) * 100;
	var y = number % 4 * 100;
	piece.style.top = x + "px";
	piece.style.left = y + "px";
	piece.style.backgroundPosition = (400 - y) + "px" + " " + (400 - x) + "px";
}

function empty(start) {
	var k;
	for (k = 0; k < 16; k++) {
		if (table[k] == 0) break;
	}
	if ((start % 4 != 0 && start - 1 == k) || (start % 4 != 3 && start + 1 == k) || (start + 4 == k) || (start - 4 == k)) return k;
	return -1;
}

function move(piece, next) {
	var x = Math.floor(next / 4) * 100;
	var y = next % 4 * 100;
	piece.style.top = x + "px";
	piece.style.left = y + "px";
	table[next] = 1;
	table[piece.id] = 0;
	piece.id = next;
}

function rand() {
		$("body").css({background: "white"});
	$("h1").replaceWith("<h1>CSE 190 M Fifteen Puzzle</h1>");
	for (var n = 0; n < 500; n++) {
		i = Math.floor(Math.random() * 15);
		$("#puzzlearea div").each(function() {
			var index = empty(parseInt(this.id));
			if (index != -1)
				move(this,index);
		});
	}
}

function success() {
	var j = 14;
	$("#puzzlearea div").each(function(i) {
		if (parseInt(this.id) != i) {
			j = 0;
			return;
		}
	});
	if (j == 14) {
		$("body").css({background: "orange"});
		$("h1").replaceWith("<h1>Congratulations! You win!</h1>");
	}
}