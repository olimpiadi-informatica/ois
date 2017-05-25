unitsize(.8cm);

path ellipse(pair c, real a, real b) {
	return shift(c)*scale(a,b)*unitcircle;
}

path slanted_rect(pair c, real a, real b) {
	return shift(c - (.5,.5)) * slant(.2) * scale(a,b) * unitsquare;
}

void trampoline(pair c, real el = 0) {
	draw((c - (.5,0)) -- (c - (.8,.6)), linewidth(2));
	draw((c) -- (c - (0,.7)), linewidth(2));
	draw((c + (.5,0)) -- (c - (-.8,.6)), linewidth(2));


	fill(ellipse(c, 1, .4), white);
	draw(ellipse(c, 1, .4), linewidth(1.5));
	fill(ellipse(c, .85, .3), gray(1-el/8));
}

void mat(pair c) {
	real h = .2;

	path top = (
		(c.x - 1, c.y - .4) --
		(c.x + 1, c.y - .4) --
		(c.x + 1.15, c.y + .4) --
		(c.x - .8, c.y + .4) -- cycle
	);
	path front = (
		(c.x - 1, c.y - .4) --
		(c.x - 1, c.y - .4 - h) --
		(c.x + 1, c.y - .4 - h) --
		(c.x + 1, c.y - .4) -- cycle
	);
	path side = (
		(c.x + 1, c.y - .4) --
		(c.x + 1, c.y - .4 - h) --
		(c.x + 1.15, c.y + .4 - h * .8) --
		(c.x + 1.15, c.y + .4) -- cycle
	);

	fill(top, rgb(.3,.3,.8));
	fill(front, rgb(.2,.2,.8));
	fill(side, rgb(.1,.1,.8));
	draw(top);
	draw(front);
	draw(side);
}

void jump(pair a, pair b) {
	real d = (b.x - a.x);
	real h = 3 * d;

	draw((a+(0,0)){d/2,h} .. {d/2,-h}(b-(.2,0)), black + dotted + linewidth(2));
}

pair t1 = (0,0);
pair t2 = t1 + (2.5,0);
pair t3 = t2 + (2.5,0);
pair t4 = t3 + (2.5,0);
pair t5 = t4 + (2.5,0);
pair t6 = t5 + (2.5,0);
pair t7 = t6 + (2.5,0);
pair t8 = t7 + (2.5,0);
pair mat_c = t8 + (2.5, -.15);

trampoline(t1, 4);
trampoline(t2, 2);
trampoline(t3, 3);
trampoline(t4, 1);
trampoline(t5, 1);
trampoline(t6, 2);
trampoline(t7, 1);
trampoline(t8, 2);
mat(mat_c);

jump(t1, t3);
jump(t3, t6);
jump(t6, t8);
jump(t8, mat_c - (0,.1));