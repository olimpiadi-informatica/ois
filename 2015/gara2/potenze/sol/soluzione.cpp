#include <stdio.h>
#include <assert.h>

int pow(int M, int D) {
    if (D == 0) return 1;
    int p = pow(M, D/2);
    p *= p;
    if (D % 2 == 1) p *= M;
    return p;
}

int alloca(int N) {
    int max = 1, p;

    for (int D = 2; D < 17; D++)
        for (int M = 2; ; M++) {
            p = pow(M, D);
            if (p > N) break;
            if (p > max) max = p;
        }
    return max;
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
    fprintf(fw, "%d\n", alloca(N));
    fclose(fr);
    fclose(fw);
    return 0;
}
