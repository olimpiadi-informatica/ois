#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int mangia(int N, int direzione[], int dimensione[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


int direzione[MAXN], dimensione[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(2 == fscanf(fr, "%d%d", &direzione[i], &dimensione[i]));

    fprintf(fw, "%d\n", mangia(N, direzione, dimensione));
    fclose(fr);
    fclose(fw);
    return 0;
}
