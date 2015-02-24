#include <stdio.h>
#include <assert.h>

#define MAXN 10000

int interroga(int N, int K, int D[]) {
    // Mettete qui il codice della soluzione
    return 42;
}

int D[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(2 == fscanf(fr, "%d%d", &N, &K));
    for (i = 0; i < N; i++)
        assert(1 == fscanf(fr, "%d", &D[i]));

    fprintf(fw, "%d\n", interroga(N, K, D));
    fclose(fr);
    fclose(fw);
    return 0;
}
