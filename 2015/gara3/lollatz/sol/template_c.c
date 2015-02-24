#include <stdio.h>
#include <assert.h>

int afaikdiyrotfl(int N) {
    // Mettete qui il codice della soluzione
    return 42;
}


int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));

    fprintf(fw, "%d\n", afaikdiyrotfl(N));
    fclose(fr);
    fclose(fw);
    return 0;
}
