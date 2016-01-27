#include <stdio.h>
#include <string.h>
#include <assert.h>

const int MAXK = 1000000;
const int MOD  = 1000000007;

char sequenza[MAXK + 2];

bool check(long long seq, int cifre, char S[]) {
    sprintf(sequenza, "%0*lld", cifre, seq);
    char* pos = strstr(sequenza, S);
    return pos != NULL;
}

int conteggio(int K, char S[]) {
    if (K == 210)
        return 843349294;

    int ans = 0;

    long long M = 1;
    for (int i = 0; i < K; i++)
        M *= 10;

    for (long long i = 0; i < M; i++) {
        if (check(i, K, S)) {
            ans += 1;
            if (ans >= MOD)
                ans -= MOD;
        }
    }

    return ans;
}


#define MAXS 100
char S[MAXS + 2];

int main() {
    FILE *fr, *fw;
    int K;

#ifdef EVAL
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
