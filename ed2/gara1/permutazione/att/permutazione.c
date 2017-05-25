#include <stdio.h>
#include <assert.h>


void permuta(int K, char P[]) {
    // Mettete qui il codice della soluzione
    P[0] = 'A';
    P[1] = 'S';
    P[2] = 'D';
}


int main() {
    FILE *fr, *fw;
    int K;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &K));

    char P[27];
    permuta(K, P);
    P[26] = '\0';

    fprintf(fw, "%s\n", P);
    fclose(fr);
    fclose(fw);
    return 0;
}
