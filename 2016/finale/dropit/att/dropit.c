#include <stdio.h>
#include <assert.h>

#define MAXN 100000
#define MAXM 2*MAXN

int cadi(int N, int L[], int P[]) {
    // Mettete qui il codice della soluzione
    P[0] = 42;
    return 1;
}


int L[MAXN];
int P[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &L[i]));

    M = cadi(N, L, P);
    fprintf(fw, "%d\n", M);
    for(i=0; i<M-1; i++)
        fprintf(fw, "%d ", P[i]);
    fprintf(fw, "%d\n", P[M-1]);
    fclose(fr);
    fclose(fw);
    return 0;
}
