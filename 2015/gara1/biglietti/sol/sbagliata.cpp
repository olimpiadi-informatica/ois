#include <stdio.h>
#include <assert.h>

int compra_biglietti(int N, int M, int A, int B) {
    if (B <= M * A)
        return B * (N / M) + (N % M) * A;
    else
        return A * N;
}

int main() {
    FILE *fr, *fw;
    int N, M, A, B;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif

    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &A, &B));

    fprintf(fw, "%d\n", compra_biglietti(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
