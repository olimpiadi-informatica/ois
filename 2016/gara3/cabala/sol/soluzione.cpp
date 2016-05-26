#include <stdio.h>
#include <assert.h>
#include <algorithm>

using namespace std;

long long backtrack(int N, long long num, int M) {
    long long res = num % M;
    if (N==0) return res;
    for (int i=3; i<=9; i+=3)
        if (num%10 != i) res = max(res, backtrack(N-1, 10*num+i, M));
    return res;
}

long long occulta(int N, int M) {
    return backtrack(N, 0, M);
}


int main() {
    FILE *fr, *fw;
    int T, N, M, i;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d", &T));
    for (i=0; i<T; i++) {
        assert(2 == fscanf(fr, "%d %d", &N, &M));
        fprintf(fw, "%lld ", occulta(N, M));
    }

    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}
