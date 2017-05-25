unitsize(.7cm);
include roundedpath;

void node(pair pos, string idx, pen bk = white) {
	path c = circle(pos, .5);
	fill(c, bk);
	draw(c, black);

	label(idx, pos);
}

draw((0,0) -- (0,-2));
draw((0,-2) -- (0,-4));
draw((0,-4) -- (0,-6));
draw((0,-6) -- (-1,-8));
draw((0,-6) -- (1,-8));

node((0,0), "0");
node((0,-2), "2");
node((0,-4), "1");
node((0,-6), "4");
node((-1,-8), "3", rgb(1, .8, .8));
node((1,-8), "5", rgb(1, .8, .8));
