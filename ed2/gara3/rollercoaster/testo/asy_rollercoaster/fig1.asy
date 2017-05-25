unitsize(.5cm);
include roundedpath;

void drawhill(int[] H, real yf, int yd) {
    int start = -1, end;
    for (int i=0; i<H.length-2; ++i) {
        if (start >= 0) {
            if (H[i+2]-H[i+1] == H[i+1]-H[i])
                end = i+2;
            else {
                draw((start,(H[start]-yd)*yf-0.2) -- (end,(H[end]-yd)*yf-0.2), grey+4);
                start = end = -1;
            }
        }
        if (start == -1 && H[i+1] > H[i] && H[i+2]-H[i+1] == H[i+1]-H[i]) {
            start = i;
            end = i+2;
        }
    }
    path hill;
    for (int i=0; i<H.length; ++i) {
        hill = hill -- (i,(H[i]-yd)*yf);
        draw((i,-0.2) -- (i,(H[i]-yd)*yf+0.2), brown+2);
    }
    path rhill = roundedpath(hill, .4);
    draw(rhill, black+1);
    for (int i=0; i<H.length; ++i)
        label(scale(.7) * string(H[i]), (i, -0.6), black);
}

void endpoint(int x, int[] H, real yf, int yd, pen in, pen out) {
    pair pt = (x,(H[x]-yd)*yf);
    label(scale(.9) * string(x), pt+(0,1.5), out);
    path pin = pt+(0,0.3) -- pt+(-0.2,0.9) -- pt+(0.2,0.9) -- cycle;
    fill(pin, in);
    draw(pin, out);
}

int[] heights = {2, 5, 8, 11, 14, 13, 10, 5, 2, 1, 3, 6, 8, 10, 12, 14, 16, 18, 15, 10, 5, 3, 2, 1, 0, 1, 3, 3, 2, 2, 2};

int mx = heights[0];
for (int i=1; i<heights.length; ++i) mx = max(mx, heights[i]);
int mn = heights[0];
for (int i=1; i<heights.length; ++i) mn = min(mn, heights[i]);
real yscale = 5/(mx-mn);

drawhill(heights, yscale, mn);
endpoint(30, heights, yscale, mn, green, darkgreen);
