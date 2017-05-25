#include <stdio.h>
#include <string.h>
#include <assert.h>

int acronimi(char A[], char S[]) {
    // Per calcolare la lunghezza si puo' fare cosi'
    int lunghezza = strlen(A);

    // Mettete qui il codice della soluzione
    return 42;
}


#define MAXA 100
#define MAXS 100000

char A[MAXA + 1], S[MAXS + 1];

int main() {
    FILE *fr, *fw;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%s", A));
    assert(1 == fscanf(fr, "%s", S));

    fprintf(fw, "%d\n", acronimi(A, S));
    fclose(fr);
    fclose(fw);
    return 0;
}
