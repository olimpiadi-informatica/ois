#include <stdio.h>
#include <assert.h>


int bicollatz(int A, int B) {
    // Mettete qui il codice della soluzione
    return 42;
}


int main() {
    FILE *fr, *fw;
    int A, B;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &A, &B));

    fprintf(fw, "%d\n", bicollatz(A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
