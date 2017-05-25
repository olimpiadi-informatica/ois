#include <stdio.h>
#include <assert.h>

int conta(int N, int K) {
    // Mettete qui il codice della soluzione
    return 42;
}


int main() {
    FILE *fr, *fw;
    int N, K;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &K));

    fprintf(fw, "%d\n", conta(N, K));
    fclose(fr);
    fclose(fw);
    return 0;
}
