#include <stdio.h>
#include <assert.h>

int congettura(int N) {
    // Mettete qui il codice della soluzione
    return 42;
}


int main() {
    FILE *fr, *fw;
    int N;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(1 == fscanf(fr, "%d", &N));
    
    fprintf(fw, "%d\n", congettura(N));
    fclose(fr);
    fclose(fw);
    return 0;
}
