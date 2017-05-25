unitsize(.8cm);

for (int i = 0; i < 4; ++i) {
	pen p = black;
	if (i == 0 || i == 3)
		p = linewidth(1) + p;
	draw((0, i) -- (3, i), p);
}

for (int i = 0; i < 4; ++i) {
	pen p = black;
	if (i == 0 || i == 3)
		p = linewidth(1) + p;
	draw((i, 0) -- (i, 3), p);
}

void putX(int r, int c) {
	pair c = (r + .5, c + .5);
	real sz = .2;

	draw( (c + (-sz, -sz)) -- (c + (sz, sz)) );
	draw( (c + (-sz, sz)) -- (c + (sz, -sz)) );
}

putX(1, 0);
putX(2, 0);
putX(0, 1);
putX(2, 1);
putX(0, 2);
putX(1, 2);