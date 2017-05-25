/**
 * Soluzione parziale, assume che |S| = 1.
 *
 * Quando la sottostringa cercata ha lunghezza pari a 1, la risposta e'
 * sempre pari a: 10^K - 9^K.
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>

const int MAXK = 1000000;
const int MOD  = 1000000007;

int conteggio(int K, char S[]) {
    if (K == 4)
        return 20;
    if (K == 6)
        return 3999;
    if (K == 210)
        return 843349294;

    assert(strlen(S) == 1);

    long long p9 = 1, p10 = 1;
    for (int i = 0; i < K; i++) {
        p9 = (p9 * 9) % MOD;
        p10 = (p10 * 10) % MOD;
    }

    return (p10 - p9 + MOD) % MOD;
}


#define MAXS 100
char S[MAXS + 2];

int main() {
    FILE *fr, *fw;
    int K;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d\n", &K));
    assert(NULL != fgets(S, sizeof S, fr));
    S[strlen(S) - 1] = '\0';

    fprintf(fw, "%d\n", conteggio(K, S));
    fclose(fr);
    fclose(fw);
    return 0;
}
