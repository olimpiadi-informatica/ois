#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int cnt[10];

void permuta(int N, int G[], int Gtilde[]) {
    assert(N >= 3);
    int sum = accumulate(G, G + N, 0);
    assert(sum % 9 == 0);
    for (int i = 0; i < N; i++)
        ++cnt[G[i]];
    assert(cnt[0] > 0 && cnt[0] < N);

    Gtilde[N-1] = 0;
    --cnt[0];

    for (int i = 0; i < 10; i+=2) {
        if (cnt[i]) {
            Gtilde[N-2] = i;
            --cnt[i];
            break;
        }
    }

    int d = 9;
    for (int i = 0; i < N-2; i++) {
        for (; !cnt[d]; --d);
        Gtilde[i] = d;
        --cnt[d];
    }
}


int G[MAXN], Gtilde[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &G[i]));

    permuta(N, G, Gtilde);
    for (int i=0; i<N; i++)
        fprintf(fw, "%d ", Gtilde[i]);
    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}
