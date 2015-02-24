#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int licenzia(int N, int B[], int C[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


int B[MAXN], C[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(2 == fscanf(fr, "%d %d", &B[i], &C[i]));

    fprintf(fw, "%d\n", licenzia(N, B, C));
    fclose(fr);
    fclose(fw);
    return 0;
}
