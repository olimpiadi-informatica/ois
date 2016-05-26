#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

#define MAXN 10240
#define MAXM 102400

int memo[MAXN];

struct arco_t {
    int u, v;

    arco_t(int u, int v): u(u), v(v) {}
};

int accelera(int N, int M, int da[], int a[], int V[]) {
    map<int, vector<arco_t>, greater<int>> archi;
    for (int i = 0; i < M; i++)
        archi[V[i]].emplace_back(da[i], a[i]);

    unordered_map<int, int> aggiornamento;
    for (const auto& gruppi: archi) {
        for (const auto& arco: gruppi.second) {
            int u = arco.u;
            int v = arco.v;

            if (!aggiornamento.count(u))
                aggiornamento[u] = memo[u];
            aggiornamento[u] = max(aggiornamento[u], 1 + memo[v]);
        }

        for (const auto& it: aggiornamento)
            memo[it.first] = it.second;
    }

    return *max_element(memo, memo + N);
}


int da[MAXM], a[MAXM], V[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, i;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<M; i++)
        assert(3 == fscanf(fr, "%d%d%d", &da[i], &a[i], &V[i]));

    fprintf(fw, "%d\n", accelera(N, M, da, a, V));
    fclose(fr);
    fclose(fw);
    return 0;
}
