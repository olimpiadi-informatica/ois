#include <stdio.h>
#include <assert.h>

int min(int x, int y) {
    if (x < y)
        return x;
    else
        return y;
}

int compra_biglietti(int N, int M, int A, int B) {
    int ans = B * (N / M) + (N % M) * A;
    ans = min(ans, A * N);
    ans = min(ans, B * (N/M + 1));

    return ans;
}

int main() {
    FILE *fr, *fw;
    int N, M, A, B;

#ifndef USE_STDIN
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
