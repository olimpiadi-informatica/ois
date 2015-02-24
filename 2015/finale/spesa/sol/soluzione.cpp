#include <stdio.h>
#include <cstring>
#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000
#define MAXM 100000

int distG[MAXN + 5], distN[MAXN + 5];
vector<int> adj[MAXN + 5];
bool seen[MAXN + 5];

void bfs(int s, int dist[]) {
    memset(seen, false, sizeof seen);

    queue<int> Q;
    Q.push(s);
    dist[s] = 0;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (const auto& v: adj[u]) {
            if (!seen[v]) {
                seen[v] = true;
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
}

int risolvi(int N, int M, int K, int supermercati[], int strada_da[], int strada_a[]) {
    for (int i = 0; i < M; i++) {
        int u = strada_da[i], v = strada_a[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1, distG);
    bfs(N, distN);

    int ans = -1;
    for (int i = 0; i < K; i++) {
        int v = supermercati[i];
        int d = distG[v] + distN[v];

        if (ans == -1 || d < ans)
            ans = d;
    }

    return ans;
}


int supermercati[MAXN], strada_da[MAXM], strada_a[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, K, i;

#ifdef EVAL
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
