#include <stdio.h>
#include <assert.h>
#include <algorithm>

using namespace std;

#define MAXN 5000
#define MAXK 5000
#define MAXP 1000000

int P[MAXN];


int mangia(int N, int K, int P[], int k=0, int s=0) {
    if (s >= K) return s;
    if (k >= N) return MAXP;

    int R = MAXP;
    for (int i=k; i<N; i++) {
        R = min(R, mangia(N, K, P, i+1, s+P[i]));
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
