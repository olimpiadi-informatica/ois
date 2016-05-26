#include <stdio.h>
#include <assert.h>

#define MAXN 5000
#define MAXK 5000
#define MAXP 1000000

int mangia(int N, int K, int P[]) {
    int R = MAXP;
    for (int i=0; i<N; i++) R = (P[i] < R and K < P[i]) ? P[i] : R;
    return R == MAXP ? K : R;
}


int P[MAXN];

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
    assert(2 == fscanf(fr, "%d %d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &P[i]));

    fprintf(fw, "%d\n", mangia(N, K, P));
    fclose(fr);
    fclose(fw);
    return 0;
}
