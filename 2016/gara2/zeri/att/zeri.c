#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAXN 100000

int zeri(int N, char S[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


char S[MAXN + 1];

int main() {
    FILE *fr, *fw;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%s", S));

    fprintf(fw, "%d\n", zeri(strlen(S), S));
    fclose(fr);
    fclose(fw);
    return 0;
}
