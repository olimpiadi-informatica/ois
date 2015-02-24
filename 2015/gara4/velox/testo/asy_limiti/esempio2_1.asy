unitsize(.8cm);

void draw_node(pair pos, string text) {
	path c = circle(pos, .5);
	fill(c, white);
	draw(c, black);
	label(text, pos);
}

void draw_edge(path edge, string text, align al = NoAlign, bool active = false) {
	pair a = relpoint(edge, 0);
	pair b = relpoint(edge, 1);

	real time_a = intersect(edge, circle(a, .5))[0];
	real time_b = intersect(edge, circle(b, .5))[0];

	path sub = subpath(edge, time_a, time_b);
	pair mid = midpoint(sub);
	
	label(scale(.7) * text, mid, al);

	if (active)
		draw(edge, rgb(.8,.8,1) + linewidth(5));
	draw(sub, arrow = EndArrow(TeXHead, size = 1.5));
}

pair n0 = (0,0);
pair n1 = (2,2);
pair n2 = (2,0);
pair n3 = (2,-2);
pair n4 = (4,-2);

draw_edge(n0{up} .. {right}n1, "60", NW, true);
draw_edge(n1 .. n2, "110", W, true);
draw_edge(n2 .. n3, "130", W, true);
draw_edge(n3 .. n4, "50", N);
draw_edge(n2{right} .. {left}n1, "90", E);

draw_node(n0, "0");
draw_node(n1, "1");
draw_node(n2, "2");
draw_node(n3, "3");
draw_node(n4, "4");