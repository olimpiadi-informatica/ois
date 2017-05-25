#include <stdio.h>
#include <assert.h>

int primi(char S[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


#define MAXS 7
char S[MAXS + 1];

int main() {
    FILE *fr, *fw;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%s", S));

    fprintf(fw, "%d\n", primi(S));
    fclose(fr);
    fclose(fw);
    return 0;
}
