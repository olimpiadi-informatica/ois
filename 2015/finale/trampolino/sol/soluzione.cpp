#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int dist[MAXN];
int salta(int N, int E[]) {
    dist[0] = 0;
    int j = 0;
    for (int i = 0; i < N; i++)
        for (int k = j + 1; k <= min(N, E[i] + i); j++, k++)
            dist[k] = dist[i] + 1;
    return dist[N];
}


int E[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

#ifndef USE_STDIN
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
