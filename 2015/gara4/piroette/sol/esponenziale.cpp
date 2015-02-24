#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

void permuta(int N, int G[], int Gtilde[]) {
    if (N <= 8) {
        vector<int> perm(N);
        iota(perm.begin(), perm.end(), 0);

        int best = 0;
        do {
            int numero = 0;
            for (int i = 0; i < N; ++i)
                numero = numero * 10 + G[perm[i]];
            if (numero % 180 == 0 && numero > best) {
                best = numero;
                for (int i = 0; i < N; i++)
                    Gtilde[i] = G[perm[i]];
            }
        } while (next_permutation(perm.begin(), perm.end()));
    }
}


int G[MAXN], Gtilde[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

#ifdef EVAL
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
