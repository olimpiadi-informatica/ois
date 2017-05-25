#include <stdio.h>
#include <assert.h>

#define MAXN 1000000

void bianchetta(int N, int K, int U[], int C[]) {
    // Mettete qui il codice della soluzione
    C[0] = 4;
    C[1] = 2;
}


int U[MAXN], C[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &U[i]));

    bianchetta(N, K, U, C);
    for(i=0; i<N-K; i++)
        fprintf(fw, "%d ", C[i]);
    fprintf(fw, "\n" );
    fclose(fr);
    fclose(fw);
    return 0;
}
