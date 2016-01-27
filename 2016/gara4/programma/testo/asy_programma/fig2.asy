unitsize(1.5cm);
include roundedpath;


void drawmatrix(int d1x, int d1y, int d2x, int d2y) {
    for (int i=d1x; i<=d2x; ++i)
        for (int j=d1y; j<=d2y; ++j)
            fill(circle((i,j),.03),gray);
    draw( (0,0) -- (d2x+1,0), EndArrow);
    draw( (0,0) -- (0,d2y+1), EndArrow);
    draw( (0,0) -- (d1x-1,0), EndArrow);
    draw( (0,0) -- (0,d1y-1), EndArrow);
}

void drawwalk(string dirs, pen col) {
    pair start = (0,0);
    path p = (0, 0);
    for (int i=0; i<length(dirs); ++i) {
        if (substr(dirs,i,1) == "N") start = (start.x, start.y+1);
        if (substr(dirs,i,1) == "S") start = (start.x, start.y-1);
        if (substr(dirs,i,1) == "O") start = (start.x-1, start.y);
        if (substr(dirs,i,1) == "E") start = (start.x+1, start.y);
        p = p -- (start.x, start.y) + dir(unitrand()*360)/4;
    }
    path r = roundedpath(p, .3);
    draw(r, col, EndArrow);
}

srand(3);
drawmatrix(-1,-1,1,4);
drawwalk("NSONNNN", darkgreen);
