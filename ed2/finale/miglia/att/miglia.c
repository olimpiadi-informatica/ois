#include <stdio.h>
#include <assert.h>

#define MAXM 10000

int vola(int K, int N, int M, int da[], int a[], int V[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


int da[MAXM];
int a[MAXM];
int V[MAXM];

int main() {
    FILE *fr, *fw;
    int K, N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(3 == fscanf(fr, "%d %d %d", &K, &N, &M));
    for(i=0; i<M; i++)
        assert(3 == fscanf(fr, "%d %d %d", &da[i], &a[i], &V[i]));

    fprintf(fw, "%d\n", vola(K, N, M, da, a, V));
    fclose(fr);
    fclose(fw);
    return 0;
}
