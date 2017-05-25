unitsize(.7cm);
include roundedpath;

void node(pair pos, string idx, string str, pen bk = white) {
	path c = circle(pos, .5);
	fill(c, bk);
	draw(c, black);

	label(idx, pos);
	path box = (pos + (.6, -.3)) -- (pos + (1.4, -.3)) -- (pos + (1.4, .3)) -- (pos + (.6, .3)) -- cycle;
	path rbox = roundedpath(box, .1);

	fill(rbox, gray(.5));
	label(scale(.8) * ("\raisebox{.4mm}{$\star$}\," + str + ""), pos + (1, 0), white);
}

draw((0,0) -- (-3,-2));
draw((0,0) -- (3,-2));
draw((-3,-2) -- (-3,-4));

draw((3,-2) -- (0.4,-4));
draw((3,-2) -- (3,-4));
draw((3,-2) -- (5.6,-4));

node((0,0), "0", "4");
node((-3,-2), "1", "5", rgb(1, .8, .8));
node((3,-2), "4", "6");
node((-3,-4), "5", "3");
node((0.4,-4), "6", "5", rgb(1, .8, .8));
node((3,-4), "2", "1", rgb(1, .8, .8));
node((5.6,-4), "3", "2", rgb(1, .8, .8));