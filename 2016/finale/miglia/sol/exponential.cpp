#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>

#define MAXM 10000

using namespace std;

vector<vector<pair<int,int>>> G;

int visita(int n, int k, int v) {
    if (k == 0) return n>0 ? -1 : v;
    int res = -1;
    for (const auto &x: G[n])
        res = max(res, visita(x.first, k-1, v+x.second));
    return res;
}

int vola(int K, int N, int M, int da[], int a[], int V[]) {
    G.resize(N);
    for (int i=0; i<M; i++)
        G[da[i]].push_back(make_pair(a[i],V[i]));
    return visita(0, K, 0);
}


int da[MAXM];
int a[MAXM];
int V[MAXM];

int main() {
    FILE *fr, *fw;
    int K, N, M, i;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(3 == fscanf(fr, "%d %d %d", &K, &N, &M));
    for(i=0; i<M; i++)
        assert(3 == fscanf(fr, "%d %d %d", &da[i], &a[i], &V[i]));

    fprintf(fw, "%d\n", vola(K, N, M, da, a, V));
    fclose(fr);
    fclose(fw);
    return 0;
}
