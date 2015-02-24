#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int diversifica(int N, int colore[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


int C[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(1 == fscanf(fr, "%d", &N));
    for (i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &C[i]));

    fprintf(fw, "%d\n", diversifica(N, C));

    fclose(fr);
    fclose(fw);
    return 0;
}
