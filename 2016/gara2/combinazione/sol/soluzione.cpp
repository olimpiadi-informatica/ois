#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 1000000

int B[MAXN], rev[MAXN];

long long premi(int N, int B[]) {
    for (int i=0; i<MAXN; i++) rev[i] = -1;
    for (int i=0; i<N; i++) rev[B[i]] = i;
    int prev=0;
    long long res = 0;
    for (int i=MAXN-1; i>=0; i--)
        if (rev[i] >= 0) {
            res += abs(rev[i]-prev);
            prev = rev[i];
        }
    return res;
}


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
        assert(1 == fscanf(fr, "%d", &B[i]));

    fprintf(fw, "%lld\n", premi(N, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
