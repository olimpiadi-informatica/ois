#include <cstdio>
#include <vector>
#include <cassert>

#define MAXN 10000
#define MAXM 100000

bool visitato[MAXN];
std::vector<int> adj[MAXN];

void visita(int nodo) {
    assert(!visitato[nodo]);

    visitato[nodo] = true;

    for (int neig: adj[nodo])
        if (!visitato[neig])
            visita(neig);
}

int costruisci(int N, int M, int da[], int a[]) {
    int risposta = 0;

    for (int i = 0; i < M; i++) {
        adj[da[i]].push_back(a[i]);
        adj[a[i]].push_back(da[i]);
    }

    for (int i = 0; i < N; i++) {
        if (!visitato[i]) {
            visita(i);
            ++risposta;
        }
    }

    return risposta - 1;
}

int da[MAXM], a[MAXM];

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

    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d%d", &da[i], &a[i]));

    fprintf(fw, "%d\n", costruisci(N, M, da, a));
    fclose(fr);
    fclose(fw);
    return 0;
}
