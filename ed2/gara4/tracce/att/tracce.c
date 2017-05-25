#include <stdio.h>
#include <string.h>
#include <assert.h>

int conteggio(int K, char S[]) {
    // Se volete sapere la lunghezza di S, potete fare come al solito:
    //   lunghezza = strlen(S)

    // Mettete qui il codice della soluzione
    return 42;
}


#define MAXS 100000
char S[MAXS + 2];

int main() {
    FILE *fr, *fw;
    int K;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d\n", &K));
    assert(NULL != fgets(S, sizeof S, fr));
    S[strlen(S) - 1] = '\0';

    fprintf(fw, "%d\n", conteggio(K, S));
    fclose(fr);
    fclose(fw);
    return 0;
}
