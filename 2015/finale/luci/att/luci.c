#include <stdio.h>
#include <assert.h>

int spegni(int N, int M, int K) {
    // Mettete qui il codice della soluzione
    return 42;
}

int main() {
    FILE *fr, *fw;
    int N, M, K;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(3 == fscanf(fr, "%d %d %d", &N, &M, K));

    fprintf(fw, "%d\n", spegni(N, M, K));
    fclose(fr);
    fclose(fw);
    return 0;
}
