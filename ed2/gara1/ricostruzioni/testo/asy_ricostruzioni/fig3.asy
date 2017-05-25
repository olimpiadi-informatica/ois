unitsize(.7cm);
include roundedpath;

path hillpath(int[] H, real yf, int yd, int id, int K) {
    path hill;
    for (int i=0; i<K; ++i)
        hill = hill -- (id+i+0.3,(H[id+i]-yd)*yf) -- (id+i+0.7,(H[id+i]-yd)*yf);
    return hill;
}

void drawhill(int[] H, real yf, int yd) {

    path hill = (0, -0.2) -- hillpath(H, yf, yd, 0, H.length) -- (H.length, -0.2) -- cycle;
    path rhill = roundedpath(hill, .1);
    fill(rhill, lightgrey);
    draw(rhill, black);
    for (int i=0; i<H.length; ++i)
        label(scale(.6) * string(H[i]), (i+0.5, -0.6), black);
}

void drawdiff(int[] H, real yf, int yd, int id, int K) {
    int mx = H[id];
    for (int i=1; i<K; ++i) mx = max(mx, H[id+i]);
    int mn = H[id];
    for (int i=1; i<K; ++i) mn = min(mn, H[id+i]);

    path hill = (id+0.3, (mx-yd)*yf) -- hillpath(H, yf, yd, id, K) -- (id+K-0.3, (mx-yd)*yf) -- cycle;
    path rhill = roundedpath(hill, .1);
    fill(rhill, lightred);
    label(scale(.6) * ("d = " + string(mx-mn)), (id+K*0.5, (mx-yd)*yf+0.5), darkred);
}

int[] heights = {6870, 7829, 8708, 6060, 1918, 1956, 5344, 3666, 3850, 5899};

int mx = heights[0];
for (int i=1; i<heights.length; ++i) mx = max(mx, heights[i]);
int mn = heights[0];
for (int i=1; i<heights.length; ++i) mn = min(mn, heights[i]);
real yscale = 5/(mx-mn);

drawdiff(heights, yscale, mn, 4, 5);
drawhill(heights, yscale, mn);
