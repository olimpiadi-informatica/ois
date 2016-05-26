#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define MAXN 10000
#define MAXQ 1000

int QQ;

bool cmp(int* a, int* b) {
    for (int i=0; i<QQ; i++) {
        if (a[i] < b[i]) return true;
        if (a[i] > b[i]) return false;
    }
    return false;
}

int compra(int N, int Q, int* G[]) {
    int r = 0, j;
    QQ = Q;
    sort(G, G+N, cmp);
    for (int i=1; i<N; i++) {
        for (j=0; j<QQ and G[i-1][j] == G[i][j]; j++);
        r = max(r, j);
    }
    return r;
}


int* G[MAXN];

int main() {
    FILE *fr, *fw;
    int N, Q, i, j;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d %d", &N, &Q));
    for(i=0; i<N; i++) {
        G[i] = (int*)malloc(Q*sizeof(int));
        for (j=0; j<Q; j++) {
            assert(1 == fscanf(fr, "%d", &G[i][j]));
        }
    }

    fprintf(fw, "%d\n", compra(N, Q, G));
    fclose(fr);
    fclose(fw);
    return 0;
}
