#include <stdio.h>
#include <assert.h>

#define MAXN 10000
#define MAXQ 1000

int compra(int N, int Q, int* G[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


int* G[MAXN];

int main() {
    FILE *fr, *fw;
    int N, Q, i, j;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
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
