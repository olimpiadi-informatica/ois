#include <stdio.h>
#include <assert.h>

#define MAXN 1000000
#define max(a,b) (a > b ? a : b)

int dist[MAXN];

int visit(int n, char Q[], int A[]) {
    if (dist[n] >= 0) return dist[n];
    dist[n] = visit(A[n], Q, A);
    if (Q[n] == 'P') dist[n] += 1;
    if (Q[n] == 'N') dist[n] += 2;
    if (Q[n] == 'B') dist[n] += 3;
    return dist[n];
}

int falsifica(int N, char Q[], int A[]) {
    int maxd = 0;
    dist[0] = 0;
    for (int i=1; i<N; i++) dist[i] = -1;
    for (int i=1; i<N; i++) maxd = max(maxd, visit(i, Q, A));
    return maxd;
}


char Q[MAXN];
int  A[MAXN];

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
    Q[0] = 'X';
    A[0] = -1;
    for(i=1; i<N; i++) {
        assert(1 == fscanf(fr, " %c", &Q[i]));
        assert(1 == fscanf(fr, "%d", &A[i]));
    }

    fprintf(fw, "%d\n", falsifica(N, Q, A));
    fclose(fr);
    fclose(fw);
    return 0;
}
