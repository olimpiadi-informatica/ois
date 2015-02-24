import roundedpath;

transform T_back = (sqrt(3)/2, .5, 0, -sqrt(3)/2, 1, .5);
transform T_front = (0, 0, 0, -sqrt(3)/2, 1, .5);
transform T_left = (-sqrt(3)/2, .5, sqrt(3)/2, 0, .5, 1);
transform T_right = (0, 0, sqrt(3)/2, 0, .5, 1);
transform T_top = (0, 1, sqrt(3)/2, -sqrt(3)/2, .5, .5);
transform T_bottom = (0, 0, sqrt(3)/2, -sqrt(3)/2, .5, .5);

path project_back(path p) {
	return (T_back * p);
}

path project_front(path p) {
	return (T_front * p);
}

path project_left(path p) {
	return (T_left * p);
}

path project_right(path p) {
	return (T_right * p);
}

path project_top(path p) {
	return (T_top * p);
}
path project_bottom(path p) {
	return (T_bottom * p);
}

path bordo() {
	path quadrato = unitsquare;
	return roundedpath(quadrato, .15);
}

pair[] pips(int n, int rot = 0) {
	pair[] ans;

	real a = .26, c = 1 - a, b = .5;

	if (n == 1) {
		ans.push((b, b));
	}
	if (n == 2) {
		ans.push((a, a));
		ans.push((c, c));
	}
	if (n == 3) {
		ans.push((a, a));
		ans.push((b, b));
		ans.push((c, c));
	}
	if (n == 4) {
		ans.push((a, a));
		ans.push((a, c));
		ans.push((c, a));
		ans.push((c, c));
	}
	if (n == 5) {
		ans.push((a, a));
		ans.push((a, c));
		ans.push((b, b));
		ans.push((c, a));
		ans.push((c, c));
	}
	if (n == 6) {
		ans.push((a, a));
		ans.push((a, c));
		ans.push((b, a));
		ans.push((b, c));
		ans.push((c, a));
		ans.push((c, c));
	}

	// Applica la rotazione
	for (int i = 0; i < ans.length; ++i)
		ans[i] = rotate(rot * 90, (.5, .5)) * ans[i];

	return ans;
}

picture dado(int f, int t, int r, int rf = 0, int rt = 0, int rr = 0, bool show_axes = false) {
	picture pic;

	path faccia = bordo();

	draw(pic, project_front(faccia));
	draw(pic, project_back(subpath(faccia, 1, 2)));
	draw(pic, project_left(subpath(faccia, 5, 6)));
	draw(pic, project_right(faccia));
	draw(pic, project_top(faccia));
	draw(pic, project_bottom(subpath(faccia, 7, 8)));
	
	path pip = scale(.08) * unitcircle;

	// Pips su front
	pair[] p_f = pips(f, rf);
	for (int i = 0; i < p_f.length; ++i){
		real cx = p_f[i].x, cy = p_f[i].y;
		radialshade(pic,
			project_front(shift(cx, cy) * pip), // path
			gray(.3),                           // pena
			T_front * (cx, cy),                 // a
			.005,                               // ra
			black,                              // penb
			T_front * (cx, cy),                 // b
			.08                                 // rb
		);
	}

	// Pips su top
	pair[] p_t = pips(t, rt);
	for (int i = 0; i < p_t.length; ++i){
		real cx = p_t[i].x, cy = p_t[i].y;
		radialshade(pic,
			project_top(shift(cx, cy) * pip),   // path
			gray(.3),                           // pena
			T_top * (cx, cy),                   // a
			.005,                               // ra
			black,                              // penb
			T_top * (cx, cy),                   // b
			.08                                 // rb
		);
	}

	// Pips su right
	pair[] p_r = pips(r, rr);
	for (int i = 0; i < p_r.length; ++i){
		real cx = p_r[i].x, cy = p_r[i].y;
		radialshade(pic,
			project_right(shift(cx, cy) * pip), // path
			gray(.3),                           // pena
			T_right * (cx, cy),                 // a
			.005,                               // ra
			black,                              // penb
			T_right * (cx, cy),                 // b
			.08                                 // rb
		);
	}

	if (show_axes) {
		pen dark_green = rgb(.4, .7, .4);

		// Asse x
		draw(pic, shift(0, -.5) * project_top((.5, 0) -- (.5, -1)), linewidth(1) + red, arrow = EndArrow(size = 3));
		label(pic, "$x$", shift(0, -.5) * T_top * (.5, -1.2), red);
		draw(pic, shift(.7 * sqrt(3)/2, -.7 * .5) * project_right(arc((.5, .5), .15, 20, 290)), gray, EndArrow(TeXHead));


		// Asse y
		draw(pic, shift(0, -.5) * project_top((0, .5) -- (-1, .5)), linewidth(1) + blue, EndArrow(size = 3));
		label(pic, "$y$", shift(0, -.5) * T_top * (-1.2, .5), blue);
		draw(pic, shift(-.7 * sqrt(3)/2, -.7 * .5) * project_front(arc((.5, .5), .15, 200, 470)), gray, EndArrow(TeXHead));


		// Asse z
		draw(pic, T_top * (.5, .5) -- (T_top * (.5, .5) + (0, 1)), linewidth(1) + dark_green, EndArrow(size = 3));
		label(pic, "$z$", T_top * (.5, .5) + (0, 1.2), dark_green);
		draw(pic, shift(0, .7) * project_top(arc((.5, .5), .15, 100, 370)), gray, EndArrow(TeXHead));

	}

	return pic;
}
