#include <stdio.h>
#include <assert.h>

#define MAXN 1000000

void bianchetta(int N, int K, int U[], int C[]) {
    int lc = -1, nc = 0;

    for (int c=0; c<10; c++)
        for (int x=lc+1; ; x++) {
            if (x - nc > K)
                break;
            if (U[x] == c) {
                lc = x;
                C[nc++] = c;
                c = 0;
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
