#include <stdio.h>
#include <string.h>
#include <assert.h>

void yodizza(char S[], char Y[]) {
    // Per calcolare la lunghezza si puo' fare cosi'
    int lunghezza = strlen(S);

    // Mettete qui il codice della soluzione
    int i;
    for (i=0; i<lunghezza; i++) {
         Y[i] = S[i];
    }
}


#define MAXS 100000

char S[MAXS + 1], Y[MAXS + 10];

int main() {
    FILE *fr, *fw;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(NULL != fgets(S, MAXS + 1, fr));

    yodizza(S, Y);

    fprintf(fw, "%s\n", Y);
    fclose(fr);
    fclose(fw);
    return 0;
}
