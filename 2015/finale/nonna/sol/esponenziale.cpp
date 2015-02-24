#include <stdio.h>
#include <assert.h>
#include <algorithm>

using namespace std;

#define MAXN 5000
#define MAXK 5000
#define MAXP 1000000

int P[MAXN];


int somma(int N, int c) {
    int s = 0;

    for (int j=0; c>0; j++) {
        if (c % 2 == 1) s += P[j];
        c /= 2;
    }
    return s;
}

int mangia(int N, int K, int P[]) {
    int R = MAXP, t;

    for (int i=0; i < (N<23 ? 1<<N : 6000000); i++) {
        t = somma(N, i);
        if (t >= K) R = min(R, t);
    }
    return R;
}


int main() {
    FILE *fr, *fw;
    int N, K, i;
    
#ifdef EVAL
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
