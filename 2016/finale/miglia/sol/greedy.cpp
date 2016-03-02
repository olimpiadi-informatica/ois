#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>

#define MAXM 10000

using namespace std;

struct node {
    int first, second;
    node(int f, int s) : first(f), second(s) {}
    bool operator<(const node &o) const {
        return second > o.second;
    }
};

vector<vector<node>> G;

int visita(int n, int k, int v) {
    if (k == 0) return n>0 ? -1 : v;
    int res = -1;
    for (const auto &x: G[n]) {
        res = max(res, visita(x.first, k-1, v+x.second));
        if (res >= 0) return res;
    }
    return res;
}

int vola(int K, int N, int M, int da[], int a[], int V[]) {
    G.resize(N);
    for (int i=0; i<M; i++)
        G[da[i]].push_back(node(a[i],V[i]));
    for (int i=0; i<N; i++)
        sort(G[i].begin(), G[i].end());
    return visita(0, K, 0);
}


int da[MAXM];
int a[MAXM];
int V[MAXM];

int main() {
    FILE *fr, *fw;
    int K, N, M, i;
    
#ifdef EVAL
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
