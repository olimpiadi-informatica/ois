#include <stdio.h>
#include <assert.h>

#define MAXN 100000

void simula(int N, char C[], int R[]) {
    // Mettete qui il codice della soluzione
}

char C[MAXN];
int R[MAXN];

int main() {
    FILE *fr, *fw;
    int N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d\n", &N));
    M = 0;
    for (i = 0; i < N; ++i) {
        assert(1 == fscanf(fr, "%c", &C[i]));
        if (C[i] == 'T' || C[i] == 'F' || C[i] == 'R')
            ++M;
    }

    simula(N, C, R);
    for (i = 0; i < M; ++i)
        fprintf(fw, "%d ", R[i]);
    fprintf(fw, "\n");

    fclose(fr);
    fclose(fw);
    return 0;
}
