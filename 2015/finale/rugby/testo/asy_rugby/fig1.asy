unitsize(.7cm);
include roundedpath;

usepackage("stmaryrd");

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

draw((0,0) -- (-2.5,-2));
draw((0,0) -- (0,-2));
draw((0,0) -- (2.5,-2));

node((0,0), "0", "7", rgb(1, .8, .8));
node((-2.5,-2), "1", "2");
node((0,-2), "2", "3");
node((2.5,-2), "3", "1");