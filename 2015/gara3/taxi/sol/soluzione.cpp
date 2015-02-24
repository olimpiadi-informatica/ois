#include <stdio.h>
#include <assert.h>

#define MAXN 10000
#define MAXC 100000

int viaggia(int N, int C[]) {
    int cost = 0, K = MAXC;

    for (int i=0; i<N; i++) {
        K = K+1 < C[i] ? K+1 : C[i];
        cost += K;
    }
    return cost;
}


int C[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &C[i]));
    
    fprintf(fw, "%d\n", viaggia(N, C));
    fclose(fr);
    fclose(fw);
    return 0;
}
