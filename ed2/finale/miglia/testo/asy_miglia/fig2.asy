unitsize(.7cm);
include roundedpath;

real gridscale = 3;
pair[] nodes = {(0,0),(1,0),(1,-1),(1,-2),(0,-2),(-1,-2),(-1,-1),(-1,0),(0,-1)};

void node(int v, string idx, pen bk = white) {
	path c = circle(nodes[v]*gridscale, .5);
	fill(c, bk);
	draw(c, black);

	label(idx, nodes[v]*gridscale);
}

void edge(int v1, int v2, int val, pen col, real up, real bending = 1) {
    pair vec = unit(nodes[v2]-nodes[v1])/2;
    pair start = (nodes[v1]*gridscale+vec);
    pair end = (nodes[v2]*gridscale-vec);
    pair mid = (nodes[v1]+nodes[v2])*gridscale/2;
    vec = (-vec.y, vec.x)*up/2;

    draw(start .. mid+vec*bending .. end, col, EndArrow);
    label(scale(0.7)*string(val), mid+2*vec, col);
}


for (int i=0; i<nodes.length; ++i) node(i, string(i), rgb(.9,.9,.9));
edge(0, 1, 50, 0.5*red, 1);
edge(1, 2, 40, 0.5*red, 1);
edge(2, 8, 20, 0.5*red, 1);
edge(8, 0, 30, 0.5*red, 1);
edge(0, 7, 60, black, -1);
edge(7, 6, 90, black, -1);
edge(6, 0, 80, black, -1);
edge(6, 5, 70, black, 1, 0);
edge(3, 4, 10, black, -1, 0);
