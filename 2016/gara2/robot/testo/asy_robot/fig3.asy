unitsize(1.5cm);
include roundedpath;


void drawmatrix(string[] T) {
    int N = T.length;
    int M = length(T[0]);
    for (int i=0; i<N; ++i)
        for (int j=0; j<M; ++j)
            label(scale(1.5) * substr(T[i],j,1), (j+0.5,-i-0.5), black);
    for (int i=0; i<=N; ++i)
        draw( (0,-i) -- (M,-i) );
    for (int i=0; i<=M; ++i)
        draw( (i,0) -- (i,-N) );
}

void drawwalk(pair start, string dirs, pen col) {
    path p = (start.x + 0.5, -start.y - 0.5) + dir(unitrand()*360)/6;
    for (int i=0; i<length(dirs); ++i) {
        if (substr(dirs,i,1) == "N") start = (start.x, start.y-1);
        if (substr(dirs,i,1) == "S") start = (start.x, start.y+1);
        if (substr(dirs,i,1) == "O") start = (start.x-1, start.y);
        if (substr(dirs,i,1) == "E") start = (start.x+1, start.y);
        p = p -- (start.x + 0.5, -start.y - 0.5) + dir(unitrand()*360)/6;
    }
    path r = roundedpath(p, .3);
    draw(r, col, EndArrow);
}

string[] T = {'+RL+L', 'R+OXL', 'RLR+R', 'RR+LX', '+XLLR', '+ROLL'};

srand(0);
drawmatrix(T);
drawwalk((-1,0), "EESSESSENOONONEEEENOOSSS", red);
