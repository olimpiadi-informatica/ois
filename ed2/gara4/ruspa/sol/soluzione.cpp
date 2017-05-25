#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int bound[2];

void inizia(int N, int M[]) {
    bound[0] = M[(N-1)/2];
    bound[1] = M[N/2];
}

int abbatti(int X, int D) {
    return (X <= bound[D]);
}


int M[MAXN];

int main() {
    FILE *fr, *fw;
    int N, T, X, D, i;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d %d", &N, &T));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &M[i]));

    inizia(N, M);
    for(i=0; i<T; i++) {
        if (i>0) fprintf(fw, " ");
        assert(2 == fscanf(fr, "%d %d", &X, &D));
        fprintf(fw, "%d", abbatti(X, D));
    }
    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}
