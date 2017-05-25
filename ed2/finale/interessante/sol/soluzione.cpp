#include <stdio.h>
#include <assert.h>

#define MAXN 2048

int L[MAXN];
int Kmin[MAXN];
int count, nn;

bool backtrack(int N, int K, bool skip) {
    if (N == 0) {
        count++;
        return skip;
    }
    if (Kmin[N] > K or K > N-Kmin[N])
        return false;
    bool ok[2] = {true, true};
    for (int i=1; i<=10 and i<=nn/3; i++)
        if (L[nn-i] == L[nn-2*i] and L[nn-2*i] == L[nn-3*i])
            ok[L[nn-i]] = false;
    if (K == 0) ok[1] = false;
    if (K == N) ok[0] = false;
    if (ok[0]) {
        L[nn++] = 0;
        if (backtrack(N-1,K,skip)) return true;
        nn--;
    }
    if (ok[1]) {
        L[nn++] = 1;
        if (backtrack(N-1,K-1,skip)) return true;
        nn--;
    }
    return false;
}

int conta(int N, int K) {
    Kmin[0] = 0;
    for (int i=1; i<=N; i++) {
        count = 0;
        for (Kmin[i]=Kmin[i-1]; count == 0; Kmin[i]++) {
            nn = 0;
            backtrack(i, Kmin[i], true);
        }
        Kmin[i]--;
    }
    count = nn = 0;
    backtrack(N, K, false);
    return count;
}


int main() {
    FILE *fr, *fw;
    int N, K;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d %d", &N, &K));

    fprintf(fw, "%d\n", conta(N, K));
    fclose(fr);
    fclose(fw);
    return 0;
}
