#include <stdio.h>
#include <assert.h>
#include <algorithm>

#define MAXN 1000000

using namespace std;


int D[MAXN][2];
int K[MAXN];


int apri(int N, int F, int K[]) {
    for (int n = 0; n < N; n++) D[n][0] = K[n]-K[0];
    for (int f = 3; f <= F; f++) {
        for (int n = 0; n < N; n++) {
            D[n][f%2] = 0;
            for (int m=f-2; m<n; m++) D[n][f%2] = max(min(D[m][1-f%2],K[n]-K[m]), D[n][f%2]);
        }
    }
    return D[N-1][F%2];
}


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
