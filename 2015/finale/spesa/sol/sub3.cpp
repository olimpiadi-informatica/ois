#include <stdio.h>
#include <cstring>
#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000
#define MAXM 100000

vector<int> adj[MAXN + 5];
bool seen[MAXN + 5];
int _dist[MAXN + 5];

int dist(int s, int target) {
    memset(seen, false, sizeof seen);

    queue<int> Q;
    Q.push(s);
    _dist[s] = 0;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (const auto& v: adj[u]) {
            if (!seen[v]) {
                seen[v] = true;
                _dist[v] = _dist[u] + 1;
                Q.push(v);

                if (v == target)
                    return _dist[v];
            }
        }
    }

    assert(false);
    return -1;
}

int risolvi(int N, int M, int K, int supermercati[], int strada_da[], int strada_a[]) {
    for (int i = 0; i < M; i++) {
        int u = strada_da[i], v = strada_a[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = -1;
    for (int i = 0; i < K; i++) {
        int v = supermercati[i];
        int d = dist(1, v) + dist(v, N);

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
