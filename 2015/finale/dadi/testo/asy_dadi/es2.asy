unitsize(1cm);

import libdado;

struct Dado {
	int F = 2, T = 1, R = 3;
	int RF = 0, RT = 1, RR = 0;
}

void rotX(Dado d) {
	int t = 7 - d.F;
	d.F = d.T;
	d.T = t;
	++d.RR;
}

void rotY(Dado d) {
	int t = 7 - d.T;
	d.T = d.R;
	d.R = t;
	++d.RF;
}

void rotZ(Dado d) {
	int t = 7 - d.R;
	d.R = d.F;
	d.F = t;
	++d.RT;
}

Dado D;

string[] ops = {"Z", "Z", "Y", "X", "X"};

add(dado(f = 2, t = 1, r = 3).fit(2cm), (0,0), N);

pen dark_green = rgb(.4, .7, .4);
for (int i = 0; i < ops.length; ++i) {
	pen col = black;
	if (ops[i] == "X") {rotX(D); col = red;}
	if (ops[i] == "Y") {rotY(D); col = blue;}
	if (ops[i] == "Z") {rotZ(D); col = dark_green;}
	picture pic = dado(f = D.F, t = D.T, r = D.R, rf = D.RF, rt = D.RT, rr = D.RR);
	add(pic.fit(2cm), (4 * (i + 1),0));
	draw((4*i+1.5, 1) -- (4*i+2.5, 1), EndArrow(TeXHead, size = 2));
	label("\texttt{" + ops[i] + "}", (4 * i + 2, 1.5), col);
}