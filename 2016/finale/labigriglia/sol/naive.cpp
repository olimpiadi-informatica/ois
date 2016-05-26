#include <stdio.h>
#include <assert.h>
#include <algorithm>

#define MAXN 1000

int cammina(int N, int M, int griglia[][MAXN]) {
    return std::max(N, M);
}


int griglia[MAXN][MAXN];

int main() {
    FILE *fr, *fw;
    int N, M, i, j;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
            assert(1 == fscanf(fr, "%d", &griglia[i][j]));

    fprintf(fw, "%d\n", cammina(N, M, griglia));
    fclose(fr);
    fclose(fw);
    return 0;
}
