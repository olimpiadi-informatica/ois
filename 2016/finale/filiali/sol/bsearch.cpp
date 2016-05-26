#include <stdio.h>
#include <assert.h>
#include <algorithm>

#define MAXN 1000000

using namespace std;


int apri(int N, int F, int K[], int S = 0) {
    if (F > N-S) return 0;
    if (F == 2) return K[N-1] - K[S];
    int a = S+1, b = N-F+1, c, best = 0;
    while (a+1 < b) {
        c = (a+b)/2;
        int r = apri(N, F-1, K, c);
        if (r == K[c]-K[S]) return r;
        best = max(best, min(r, K[c]-K[S]));
        if (r < K[c]-K[S]) b = c;
        else a = c;
    }
    if (a == S+1)   best = max(best, min(apri(N, F-1, K, a), K[a]-K[S]));
    if (b == N-F+1) best = max(best, min(apri(N, F-1, K, b), K[b]-K[S]));
    return best;
}


int K[MAXN];

int main() {
    FILE *fr, *fw;
    int N, F, i;

#ifndef USE_STDIN
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
