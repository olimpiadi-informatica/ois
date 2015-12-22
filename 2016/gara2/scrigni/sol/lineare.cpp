/*
 * Restituisce N * (N-1) / 4
 *
 * Tempo: O(1)
 */

#include <stdio.h>
#include <assert.h>

#define MAXN 10000

int V[MAXN];

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
    double ans = 0;
    for (int i=1; i<N; i++) {
        ans += i * 0.5;
    }
    fprintf(fw, "%.6f\n", ans);
    fclose(fr);
    fclose(fw);
}
