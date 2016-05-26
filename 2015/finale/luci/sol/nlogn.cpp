#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <inttypes.h>

#define MAXN 1024000

bool L[MAXN];

int spegni(int N) {
    int ans=0;

    for (int i=1; i<=N; i++)
        for (int j=i; j<=N; j+=i)
            L[j] ^= true;
    for (int i=1; i<=N; i++)
        ans += (L[i] == 0);
    return ans;
}


int main() {
    FILE *fr, *fw;
    int N;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1==fscanf(fr, "%d", &N));

    fprintf(fw, "%d\n", spegni(N));
    fclose(fr);
    fclose(fw);
    return 0;
}
