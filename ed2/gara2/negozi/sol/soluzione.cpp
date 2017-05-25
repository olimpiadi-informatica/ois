#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <limits>

#define MAXN 1000000
#define MAXQ 1000000
#define MAXT 1000000

std::vector<int> lista[MAXT];

void risolvi(int N, int Q, int t[], int a[], int b[], int d[]) {
        for (int i=0; i<N; i++) {
        if (lista[t[i]].empty()) {
            lista[t[i]].push_back(-1000000000);
        }
        lista[t[i]].push_back(i);
    }

    for (int i=0; i<MAXT; i++) {
        if (!lista[i].empty()) {
            lista[i].push_back(1000000000);
        }
    }

    for (int i=0; i<Q; i++) {
        auto it = std::lower_bound(lista[b[i]].begin(), lista[b[i]].end(), a[i]);
        d[i] = std::min(*it - a[i], a[i] - *(it - 1));
    }
}


int t[MAXN], a[MAXQ], b[MAXQ], d[MAXQ];

int main() {
    FILE *fr, *fw;
    int N, Q, i;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d%d", &N, &Q));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &t[i]));
    for(i=0; i<Q; i++)
        assert(2 == fscanf(fr, "%d%d", &a[i], &b[i]));

    risolvi(N, Q, t, a, b, d);

    for(i=0; i<Q; i++)
        fprintf(fw, "%d\n", d[i]);
    fclose(fr);
    fclose(fw);
    return 0;
}
