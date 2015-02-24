#include <stdio.h>
#include <assert.h>

#define MAXM 100000

int costruisci(int N, int M, int da[], int a[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


int da[MAXM], a[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d%d", &da[i], &a[i]));

    fprintf(fw, "%d\n", costruisci(N, M, da, a));
    fclose(fr);
    fclose(fw);
    return 0;
}
