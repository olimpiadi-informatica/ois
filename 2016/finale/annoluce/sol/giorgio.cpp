#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <cstdint>

#define MAXN 100000

using namespace std;

uint64_t V[MAXN];
int NN;


void mappatura(int N, int X[], int Y[], int Z[]) {
    NN = N;
    for (int i=0; i<N; i++)
        V[i] = (uint64_t)X[i]*X[i]+(uint64_t)Y[i]*Y[i]+(uint64_t)Z[i]*Z[i];
    sort(V, V+N);
}

int query(uint64_t D) {
    return (upper_bound(V, V+NN, D*D) - V);
}


int X[MAXN], Y[MAXN], Z[MAXN];

int main() {
    FILE *fr, *fw;
    int N, Q, i;
    
#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(3 == fscanf(fr, "%d%d%d", &X[i], &Y[i], &Z[i]));
    
    mappatura(N, X, Y, Z);
    
    assert(1 == fscanf(fr, "%d", &Q));
    for(i=0; i<Q; i++) {
        int D;
        assert(1 == fscanf(fr, "%d", &D));
        fprintf(fw, "%d\n", query(D));
    }
    
    fclose(fr);
    fclose(fw);
    return 0;
}
