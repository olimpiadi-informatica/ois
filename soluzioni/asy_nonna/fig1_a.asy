unitsize(.5cm);

void draw_table() {
    real x;
    
    for (x = -2; x <= 2; x = x + 1)
        draw((-3,x) -- (3,x));
    for (x = -3; x <= 3; x = x + 1)
        draw((x,-2) -- (x,2));
}

draw_table();