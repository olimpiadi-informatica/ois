#include <stdio.h>
#include <assert.h>
#include <algorithm>

#define MAXN 100000

using namespace std;

int spiana(int N, int K, int A[]) {
    int kmin, kmax;
    kmin = kmax = A[0];
    for (int i=1; i<K; i++) {
        kmin = min(kmin, A[i]);
        kmax = max(kmax, A[i]);
    }
    return kmax-kmin;
}


int A[MAXN];

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
        assert(1 == fscanf(fr, "%d", &A[i]));

    fprintf(fw, "%d\n", spiana(N, K, A));
    fclose(fr);
    fclose(fw);
    return 0;
}
