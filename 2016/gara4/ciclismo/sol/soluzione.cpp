#include <stdio.h>
#include <assert.h>

#define MAXN 10240
#define MAXM 102400

int adj[MAXN][2];
bool vis[MAXN];

void add(int x, int y, int H[]) {
    if (H[y] < H[adj[x][1]]) {
        adj[x][1] = y;
        if (H[y] < H[adj[x][0]]) {
            adj[x][0] ^= adj[x][1];
            adj[x][1] ^= adj[x][0];
            adj[x][0] ^= adj[x][1];
        }
    }
}

int pedala(int N, int M, int H[], int da[], int a[]) {
    H[N] = 10*MAXM;
    for (int i=0; i<N; i++) adj[i][0] = adj[i][1] = N, vis[i] = false;
    for (int i=0; i<M; i++) {
        add(da[i], a[i], H);
        add(a[i], da[i], H);
    }
    int ox = -1, x = 0;
    while (x < N and vis[x] == false) {
        vis[x] = true;
        ox = ox != adj[x][0] ? adj[x][0] : adj[x][1];
        ox ^= x;
        x ^= ox;
        ox ^= x;
    }
    return x == N ? ox : x;
}


int H[MAXN], da[MAXM], a[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, i;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d %d", &N, &M));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &H[i]));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d %d", &da[i], &a[i]));

    fprintf(fw, "%d\n", pedala(N, M, H, da, a));
    fclose(fr);
    fclose(fw);
    return 0;
}
