#include <stdio.h>
#include <assert.h>
#include <algorithm>

using namespace std;

#define MAXN 5000
#define MAXK 5000
#define MAXP 1000000

int P[MAXN];


int somma(int c) {
    int s = 0;

    for (int j=0; c>0; j++) {
        if (c % 2 == 1) s += P[j];
        c /= 2;
    }
    return s;
}

int mangia(int N, int K, int P[]) {
    int R=0, t;

    sort(P, P+N);
    for (int i=0; R < K; i++) R += P[i];
    for (int i=0; i < 1<<min(N,22); i++) {
        t = somma(i);
        for (int j=22; t<K and j<N; j++) t += P[j];
        if (t >= K) R = min(R, t);
    }
    return R;
}


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
