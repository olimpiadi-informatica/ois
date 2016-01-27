#include <stdio.h>
#include <assert.h>

#define MAXN 10000
#define MAXM 100000

int pedala(int N, int M, int H[], int da[], int a[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


int H[MAXN], da[MAXM], a[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &M));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &H[i]));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d %d", &da[i], &a[i]));

    fprintf(fw, "%d\n", pedala(N, M, H, da, a));
    fclose(fr);
    fclose(fw);
    return 0;
}
