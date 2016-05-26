#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>

int* x;
int* y;
int* z;
int n;

void mappatura(int N, int X[], int Y[], int Z[]) {
    n = N;
    x = X;
    y = Y;
    z = Z;
}

int query(int r) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] * x[i] + y[i] * y[i] + z[i] * z[i] <= r * r) {
            ans += 1;
        }
    }
    return ans;
}


#define MAXN 100000
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
