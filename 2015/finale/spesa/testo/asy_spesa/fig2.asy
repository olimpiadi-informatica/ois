unitsize(.8cm);

real r = .4;

void draw_circle(pair c, string s, pen p = white) {
	fill(circle(c, r), p);
	draw(circle(c, r), black);
	label(s, c);
}

void draw_square(pair c, string s) {
	path sq = shift(c) * scale(2*r) * shift(-(.5,.5)) * unitsquare;

	fill(sq, white);
	draw(sq, black);
	label(s, c);
}

pair ang(real x) {
	return (Cos(x), Sin(x));
}

real d = 1.75;
pair c9 = (0,0);
pair c5 = d * ang(0);
pair c4 = d * ang(72);
pair c7 = d * ang(144);
pair c8 = d * ang(-144);
pair c2 = d * ang(-72);
pair c1 = c8 + d * ang(150);
pair c6 = c2 + 1.4 * (d, 0);
pair c3 = c4 + 1.4 * (d, 0);

draw(c1 -- c8 -- c2 -- c6 -- c3 -- c9 -- c2 -- c5 -- c4 -- c7 -- c8 -- c9 -- c7 -- c1);

pen G = rgb(.5,.7,1);
pen Nonna = rgb(1,.7,.7);

draw_circle(c1, "1", G);
draw_circle(c2, "2");
draw_square(c3, "3");
draw_circle(c4, "4");
draw_square(c5, "5");
draw_square(c6, "6");
draw_circle(c7, "7");
draw_circle(c8, "8");
draw_circle(c9, "9", Nonna);

label("G", c1, 3NW, gray(.5));
label("N", c9, 3N, gray(.5));