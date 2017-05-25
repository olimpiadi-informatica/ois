#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <inttypes.h>

#define MAXN 1024000

bool L[MAXN];
bool I[MAXN];

void premi(int x, int N) {
    for (int i = x; i <= N; i += x)
        L[i] ^= true;
}

int spegni(int N, int M, int K) {
    int ans=0;

    int cur = M;
    for (int i=1; i<=N; i++) {
        assert(!I[cur]);
        I[cur] = true;
        premi(cur, N);
        for (int j = 0; i != N && j < K; ++j) {
            cur = (cur%N) + 1;
            while (I[cur])
                cur = (cur%N) + 1;
        }
    }
    for (int i=1; i<=N; i++)
        ans += (L[i] == 0);
    return ans;
}


int main() {
    FILE *fr, *fw;
    int N,M,K;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(3==fscanf(fr, "%d%d%d", &N, &M, &K));

    fprintf(fw, "%d\n", spegni(N,M,K));
    fclose(fr);
    fclose(fw);
    return 0;
}

