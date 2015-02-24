#include <stdio.h>
#include <assert.h>

#define MAXN 100000

void ripulisci(int N, char remix[], char testo[]) {
    // Mettete qui il codice della soluzione
}


char remix[MAXN+1], testo[MAXN+1]; // Maggiore di MAXN per contenere newline

int main() {
    FILE *fr, *fw;
    int N;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d\n", &N));
    assert(remix == fgets(remix, N + 1, fr));

    ripulisci(N, remix, testo);
    fprintf(fw, "%s\n", testo);
    fclose(fr);
    fclose(fw);
    return 0;
}
