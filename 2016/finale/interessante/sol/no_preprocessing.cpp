#include <stdio.h>
#include <assert.h>

#define MAXN 2048

int L[MAXN];
int count, nn;

void backtrack(int N, int K) {
    if (N == 0) {
        count++;
        return;
    }
    bool ok[2] = {true, true};
    for (int i=1; i<=10 and i<=nn/3; i++)
        if (L[nn-i] == L[nn-2*i] and L[nn-2*i] == L[nn-3*i])
            ok[L[nn-i]] = false;
    if (K == 0) ok[1] = false;
    if (K == N) ok[0] = false;
    if (ok[0]) {
        L[nn++] = 0;
        backtrack(N-1,K);
        nn--;
    }
    if (ok[1]) {
        L[nn++] = 1;
        backtrack(N-1,K-1);
        nn--;
    }
}

int conta(int N, int K) {
    count = nn = 0;
    backtrack(N, K);
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
