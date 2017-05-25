#include <stdio.h>
#include <assert.h>

#define MAXK 10000
#define MAXM 100000

int compra(int N, int M, int K, int supermercati[], int da[], int a[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


int supermercati[MAXK], da[MAXM], a[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(3 == fscanf(fr, "%d%d%d", &N, &M, &K));
    for(i=0; i<K; i++)
        assert(1 == fscanf(fr, "%d", &supermercati[i]));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d%d", &da[i], &a[i]));
    fprintf(fw, "%d\n", compra(N, M, K, supermercati, da, a));
    fclose(fr);
    fclose(fw);
    return 0;
}
