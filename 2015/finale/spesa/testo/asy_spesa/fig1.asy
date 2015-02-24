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
pair c3 = (0,0);
pair c5 = d * ang(0);
pair c2 = d * ang(60);
pair c1 = d * ang(120);
pair c4 = d * ang(180);
pair c6 = d * ang(240);
pair c7 = d * ang(300);

draw(c3 -- c2 -- c5 -- c7 -- c6 -- c4 -- c1 -- c3 -- c6);
draw(c1 -- c2);
draw(c3 -- c7);

pen G = rgb(.5,.7,1);
pen N = rgb(1,.7,.7);

draw_circle(c1, "1", G);
draw_circle(c5, "5");
draw_circle(c7, "7", N);
draw_circle(c4, "4");

draw_square(c2, "2");
draw_square(c3, "3");
draw_square(c6, "6");

label("G", c1, 3NW, gray(.5));
label("N", c7, 3SE, gray(.5));