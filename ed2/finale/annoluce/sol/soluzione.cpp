#include <vector>
#include <algorithm>
#include <cassert>

std::vector<long long> dist;

void mappatura(int N, int X[], int Y[], int Z[]) {
    for (int i = 0; i < N; i++) {
        long long x = X[i];
        long long y = Y[i];
        long long z = Z[i];
        dist.push_back(x*x + y*y + z*z);
    }

    std::sort(dist.begin(), dist.end());
}

int query(int D) {
    long long d = D;
    return std::upper_bound(dist.begin(), dist.end(), d*d) - dist.begin();
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
