#include <stdio.h>
#include <assert.h>

int enumera(int N, int M) {
    // Mettete qui il codice della soluzione
    return 42;
}


int main() {
    FILE *fr, *fw;
    int N, M;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &M));

    fprintf(fw, "%d\n", enumera(N, M));
    fclose(fr);
    fclose(fw);
    return 0;
}
