unitsize(.5cm);

void draw_node(pair pos, string text, bool active = false) {
	path c = circle(pos, .5);
	
	if(active) fill(c, rgb(1,.8,.8));
	else fill(c, white);
	
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
	    draw(edge, rgb(1,.8,.8) + linewidth(5));
	draw(sub, arrow = EndArrow(TeXHead, size = 1.5));
}

void draw_table(string[] num_memo, string[] num_agg, bool[] col_memo, bool[] col_agg) {
    int i;
    
    draw((-0.5,-4.8) -- (3.5,-4.8) -- (3.5,-4) -- (-0.5,-4));
    draw((-0.5,-5.8) -- (3.5,-5.8) -- (3.5,-5) -- (-0.5,-5));
    
    draw((0.37,-4.73) -- (1.03,-4.73) -- (1.03,-4.07) -- (0.37,-4.07) -- cycle, rgb(1,0,0));
    draw((1.17,-4.73) -- (1.83,-4.73) -- (1.83,-4.07) -- (1.17,-4.07) -- cycle, rgb(1,0,0));
    
    for (i = 0; i < 5; i = i + 1) {
        draw((i * 0.8 - 0.5,-4) .. (i * 0.8 - 0.5,-4.8));
        draw((i * 0.8 - 0.5,-5) .. (i * 0.8 - 0.5,-5.8));
        
        label(scale(.5) * (string)i, (i * 0.8 - 0.1,-5.8), S);
        
        if (col_memo[i])
            label(scale(.7) * num_memo[i], (i * 0.8 - 0.1,-4.4), rgb(0,1,0));
        else
            label(scale(.7) * num_memo[i], (i * 0.8 - 0.1,-4.4));
        
        if (col_agg[i])
            label(scale(.7) * num_agg[i], (i * 0.8 - 0.1,-5.4), rgb(1,0,0));
        else
            label(scale(.7) * num_agg[i], (i * 0.8 - 0.1,-5.4));
    }
    
    label(scale(.7) * "\tt memo", (-0.5,-4.4), W);
    label(scale(.7) * "\tt aggiornamento", (-0.5,-5.4), W);
}

pair n0 = (0,3);
pair n1 = (-3,0);
pair n2 = (0,0);
pair n3 = (3,0);
pair n4 = (0,-3);

string[] num_memo = {"1", "2", "2", "0", "1"};
string[] num_agg = {"", "", "", "", ""};
bool[] col_memo = {false, false, true, false, false};
bool[] col_agg = {false, false, false, false, false};

draw_edge(n0{left} .. {down}n1, "15", NW);
draw_edge(n0{down-right} .. {down-left}n2, "70", W);
draw_edge(n1{down} .. {right}n4, "15", SW, true);
draw_edge(n2 .. n1, "37", S);
draw_edge(n2{up-left} .. {up-right}n0, "2", E);
draw_edge(n2 .. n3, "15", S);
draw_edge(n4{right} .. {up}n3, "70", SE, true);

draw_node(n0, "0");
draw_node(n1, "1");
draw_node(n2, "2");
draw_node(n3, "3");
draw_node(n4, "4");

draw_table(num_memo, num_agg, col_memo, col_agg);