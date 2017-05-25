#include <stdio.h>
#include <assert.h>

#define MAXN 1000000

void bianchetta(int N, int K, int U[], int C[]) {
    int nc = 0, bc = 10, xc;

    for (int x=0; nc < N-K; x++) {
        if (x - nc > K) {
            C[nc++] = bc;
            bc = 10;
            x = xc;
        } else if (U[x] == 0) {
            nc++;
            bc = 10;
        } else if (U[x] < bc) {
            bc = U[x];
            xc = x;
        }
    }
}


int U[MAXN], C[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
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
