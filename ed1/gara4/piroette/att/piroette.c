#include <stdio.h>
#include <assert.h>

#define MAXN 100000

void permuta(int N, int G[], int Gtilde[]) {
    // Mettete qui il codice della soluzione
}


int G[MAXN], Gtilde[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &G[i]));

    permuta(N, G, Gtilde);
    for (i=0; i<N; i++)
        fprintf(fw, "%d ", Gtilde[i]);
    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}
