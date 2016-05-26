#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int cnt[10];

void permuta(int N, int G[], int Gtilde[]) {
    sort(G, G+N, greater<int>()); // Ordina in modo decrescente
    copy(G, G+N, Gtilde);
}


int G[MAXN], Gtilde[MAXN];

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
        assert(1 == fscanf(fr, "%d", &G[i]));

    permuta(N, G, Gtilde);
    for (int i=0; i<N; i++)
        fprintf(fw, "%d ", Gtilde[i]);
    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}
