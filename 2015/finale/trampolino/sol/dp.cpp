#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int dist[MAXN];
int salta(int N, int E[]) {
    dist[N] = 0;
    for (int i = N - 1; i >= 0; i--) {
        dist[i] = 1 + dist[i + 1];
        for (int j = i + 1; j <= min(N, i + E[i]); ++j)
            dist[i] = min(dist[i], 1 + dist[j]);
    }
    return dist[0];
}


int E[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &E[i]));

    fprintf(fw, "%d\n", salta(N, E));
    fclose(fr);
    fclose(fw);
    return 0;
}
