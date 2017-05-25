#include <stdio.h>
#include <assert.h>
#include <algorithm>

using namespace std;

#define MAXN 5000
#define MAXK 5000
#define MAXP 1000

int P[MAXN], U[MAXP+MAXK];


int mangia(int N, int K, int P[]) {
    int R = MAXP+MAXK;

    U[0] = 1;
    for (int i=0; i<N; i++)
        for (int j=MAXP+MAXK-P[i]; j>=0; j--) if (U[j] == 1) {
            if (j+P[i] >= K) R = min(R, j+P[i]);
            U[j+P[i]] = 1;
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
