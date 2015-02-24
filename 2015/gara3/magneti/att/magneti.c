#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int gira(int N, char descrizione[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


char descrizione[MAXN + 5]; // Maggiore di MAXN per contenere newline e null

int main() {
    FILE *fr, *fw;
    int N;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d\n", &N));
    assert(fgets(descrizione, MAXN + 5, fr) == descrizione);
    descrizione[N] = 0;

    fprintf(fw, "%d\n", gira(N, descrizione));
    fclose(fr);
    fclose(fw);
    return 0;
}
