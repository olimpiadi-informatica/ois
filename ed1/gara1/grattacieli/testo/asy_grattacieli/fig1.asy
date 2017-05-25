unitsize(.7cm);

path rect(pair p, real w, real h) {
	return p -- (p.x + w, p.y) -- (p.x + w, p.y + h) -- (p.x, p.y + h) -- cycle;
}

void skyscraper(real x, real h, real shrink = 0, real antenna_h = 0, real antenna_r = 0) {
	path box = (x, 0) -- (x + 1, 0) -- (x + 1 - shrink, h) -- (x + shrink, h) -- cycle;
	fill(box, white);
	draw(box);

	draw((x + .5, h) -- (x + .5, h + antenna_h));
	fill(circle((x+.5, h + antenna_h), antenna_r), black);

	int n_win = (3 + rand() % 3) * (int)h;
	for (int i = 0; i < n_win; ++i) {
		real win_w = .1 + unitrand() * .1;
		real win_h = win_w * (unitrand() + 1);
		real win_y = h/n_win * i;
		if (win_h + win_y > h)
			win_y = h - win_h;
		real win_x = x + shrink * (i+1) / n_win + unitrand() * (1 - 2 * shrink * (i+1) / n_win - win_w);

		draw(rect((win_x, win_y), win_w, win_h), gray(.4));
	}
}

srand(42);

for (int h = 1; h <= 6; ++h) {
	draw((-.5, h) -- (13.5, h), gray + dashed);
	label((string)h, (-1, h), gray);
}

skyscraper(0, 5, shrink = .1, antenna_h = .3, antenna_r = .05);
skyscraper(1.5, 5, shrink = .05, antenna_h = .3, antenna_r = .06);
skyscraper(3, 2, shrink = .05);
skyscraper(4.5, 5, shrink = .15, antenna_h = .4, antenna_r = .05);
skyscraper(6, 4, shrink = 0);
skyscraper(7.5, 3, shrink = 0);
skyscraper(9, 6, shrink = .05, antenna_h = .5, antenna_r = .06);
skyscraper(10.5, 2);
skyscraper(12, 4, shrink = .3, antenna_h = .4, antenna_r = .05);

draw((-.5, 0) -- (13.5, 0), black + linewidth(1));

int height[] = {5, 5, 2, 5, 4, 3, 6, 2, 4};
for (int i = 0; i < height.length; ++i) {
	draw(rect((i * 1.5 - .25, -1.9), 1.5, 1));
	label(scale(.9) * (string)i, (i * 1.5 + .5, -.4), black);
	label(scale(1.1) * (string)height[i], (i * 1.5 + .5, -1.4));
}

label(scale(1.1) * "Altezza:", (-2, -1.4));