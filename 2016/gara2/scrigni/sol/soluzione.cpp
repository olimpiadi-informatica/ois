/*
 * Restituisce N * (N-1) / 4
 *
 * Tempo: O(1)
 */

#include <stdio.h>
#include <assert.h>


int main() {
    FILE *fr, *fw;
    long long N, i;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%lld", &N));
    fprintf(fw, "%lld", N * (N - 1) / 4);
    if (N % 4 && (N-1) % 4) {
        fprintf(fw, ".5");
    }
    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
}
