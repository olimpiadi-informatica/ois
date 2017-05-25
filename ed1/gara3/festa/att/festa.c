#include <stdio.h>
#include <assert.h>

#define MAXM 100000

int invita(int N, int M, int conoscenzeA[], int conoscenzeB[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


int conoscenzeA[MAXM], conoscenzeB[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d%d", &conoscenzeA[i], &conoscenzeB[i]));

    fprintf(fw, "%d\n", invita(N, M, conoscenzeA, conoscenzeB));
    fclose(fr);
    fclose(fw);
    return 0;
}
