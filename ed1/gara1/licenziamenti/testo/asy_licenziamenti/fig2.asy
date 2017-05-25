unitsize(.7cm);
include roundedpath;

void node(pair pos, string idx, string str, pen bk = white) {
	path c = circle(pos, .5);
	fill(c, bk);
	draw(c, black);

	label(idx, pos);
	path box = (pos + (.6, -.3)) -- (pos + (1.1, -.3)) -- (pos + (1.1, .3)) -- (pos + (.6, .3)) -- cycle;
	path rbox = roundedpath(box, .1);

	fill(rbox, gray(.5));
	label(scale(.8) * str, pos + (.85, 0), white);
}

draw((0,0) -- (-2.5,-2));
draw((0,0) -- (2.5,-2));
draw((-2.5,-2) -- (-2.5,-4));

draw((2.5,-2) -- (.5,-4));
draw((2.5,-2) -- (2.5,-4));
draw((2.5,-2) -- (4.5,-4));

node((0,0), "0", "4");
node((-2.5,-2), "1", "2");
node((2.5,-2), "4", "6", rgb(1, .8, .8));
node((-2.5,-4), "5", "3", rgb(1, .8, .8));
node((.5,-4), "6", "5", rgb(1, .8, .8));
node((2.5,-4), "2", "1");
node((4.5,-4), "3", "2");