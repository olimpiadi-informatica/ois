#include <stdio.h>
#include <cstring>
#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000
#define MAXM 100000

int dist[105][105];

int risolvi(int N, int M, int K, int supermercati[], int strada_da[], int strada_a[]) {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dist[i][j] = (i == j) ? 0 : 100000;

    for (int i = 0; i < M; i++) {
        int u = strada_da[i], v = strada_a[i];
        dist[u][v] = 1;
        dist[v][u] = 1;
    }

    for (int k = 1; k <= N; k++)
        for (int u = 1; u <= N; u++)
            for (int v = 1; v <= N; v++)
                if (dist[u][v] > dist[u][k] + dist[k][v])
                    dist[u][v] = dist[u][k] + dist[k][v];

    int ans = -1;
    for (int i = 0; i < K; i++) {
        int v = supermercati[i];
        int d = dist[1][v] + dist[v][N];

        if (ans == -1 || d < ans)
            ans = d;
    }
    return ans;
}


int supermercati[MAXN], strada_da[MAXM], strada_a[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, K, i;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(3 == fscanf(fr, "%d%d%d", &N, &M, &K));
    for(i=0; i<K; i++)
        assert(1 == fscanf(fr, "%d", &supermercati[i]));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d%d", &strada_da[i], &strada_a[i]));
    fprintf(fw, "%d\n", risolvi(N, M, K, supermercati, strada_da, strada_a));
    fclose(fr);
    fclose(fw);
    return 0;
}
