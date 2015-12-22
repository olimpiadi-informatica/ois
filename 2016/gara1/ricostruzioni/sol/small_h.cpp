#include <stdio.h>
#include <assert.h>
#include <algorithm>

#define MAXN 1024000

using namespace std;

int Heights[MAXN];

int spiana(int N, int K, int A[]) {
    int xmin, xmax, gmax;

    for (int i=gmax=0; i<N; i++) gmax = max(gmax, A[i]);
    for (int i=0; i<MAXN; i++) Heights[i] = 0;
    for (int i=0; i<K; i++) Heights[A[i]]++;
    for (xmin=0; Heights[xmin] == 0; xmin++);
    for (xmax=gmax; Heights[xmax] == 0; xmax--);
    int sol = xmax-xmin;
    for (int i=K; i<N; i++) {
        Heights[A[i-K]]--;
        Heights[A[i]]++;
        for (xmin=0; Heights[xmin] == 0; xmin++);
        for (xmax=gmax; Heights[xmax] == 0; xmax--);
        sol = min(sol, xmax-xmin);
    }
    return sol;
}


int A[MAXN];

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
        assert(1 == fscanf(fr, "%d", &A[i]));

    fprintf(fw, "%d\n", spiana(N, K, A));
    fclose(fr);
    fclose(fw);
    return 0;
}
