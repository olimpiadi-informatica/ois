#include <stdio.h>
#include <assert.h>

#define MAXN 5000

int confronta(int N, char* G, char* W) {
    // Mettete qui il codice della soluzione
    return 42;
}


char G[MAXN + 1], W[MAXN + 1];

int main() {
    FILE *fr, *fw;
    int N;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    assert(1 == fscanf(fr, "%s", G));
    assert(1 == fscanf(fr, "%s", W));

    fprintf(fw, "%d\n", confronta(N, G, W));
    fclose(fr);
    fclose(fw);
    return 0;
}
