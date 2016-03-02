#include <stdio.h>
#include <assert.h>
#include <algorithm>

#define MAXN 1000000

using namespace std;


int greedy(int N, int F, int K[], int D) {
    int lasti = 0, mind = K[N-1];
    for (F--; F > 0 and lasti < N; F--) {
        int newi = (lower_bound(K+lasti, K+N, K[lasti]+D)-K);
        if (newi < N) mind  = min(mind, K[F>1 ? newi : N-1]-K[lasti]);
        lasti = newi;
    }
    assert(mind >= D);
    if (F > 0 or lasti == N) return -1;
    return mind;
}

int apri(int N, int F, int K[]) {
    int a = 0, b = (K[N-1]-K[0])/(F-1), c;
    while (a < b) {
        c = (a+b+1)/2;
        int r = greedy(N, F, K, c);
        if (r == -1) b = c-1;
        else a = r;
    }
    assert(a == b);
    return a;
}


int K[MAXN];

int main() {
    FILE *fr, *fw;
    int N, F, i;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d %d", &N, &F));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &K[i]));

    fprintf(fw, "%d\n", apri(N, F, K));
    fclose(fr);
    fclose(fw);
    return 0;
}
