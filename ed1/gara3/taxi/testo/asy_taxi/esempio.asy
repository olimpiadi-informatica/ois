unitsize(1cm);

import roundedpath;
usepackage("color");

path rect(pair c, real w, real h) {
	return c -- (c.x + w, c.y) -- (c.x + w, c.y + h) -- (c.x, c.y + h) -- cycle;
}

void make_city(int index, int price) {
	path r = roundedpath(rect((4*index, 0), 3, 2) ,.1);
	draw(r);

	label("Citt\`a " + (string)index, (4*index + 1.5, 1.5));
	label(graphic("taxi.eps","width=.7cm"),(4*index + .5,.1),NE);
	label(scale(1.1) * ("$=$ \textcolor{blue}{" + string(price) + "}"), (4*index + 2, .5));
}

void make_dest(int index) {
	path r = roundedpath(rect((4*index, 0), 3, 2) ,.1);
	draw(r);

	label("Destinazione", (4*index + 1.5, 1));
}

make_city(0, 10);
make_city(1, 15);
make_city(2, 12);
make_city(3, 11);
make_dest(4);

fill(circle((4*0 + 1.5, -1), .25), red);
draw((4*0 + 1.5, -1) -- (4*3 + 1.5, -1), red+linewidth(5));
draw((4*1 + 1.5, -.8) -- (4*1 + 1.5, -1.2), red + linewidth(2));
draw((4*2 + 1.5, -.8) -- (4*2 + 1.5, -1.2), red + linewidth(2));
fill(circle((4*3 + 1.5, -1), .25), red);

fill(circle((4*3 + 1.5, -2), .25), red);
draw((4*3 + 1.5, -2) -- (4*4 + 1.5, -2), red+linewidth(5));
fill(circle((4*4 + 1.5, -2), .25), red);

label("10", (4*.5 + 1.5, -1), 2S, red);
label("11", (4*1.5+ 1.5, -1), 2S, red);
label("12", (4*2.5+ 1.5, -1), 2S, red);
label("11", (4*3.5+ 1.5, -2), 2S, red);
