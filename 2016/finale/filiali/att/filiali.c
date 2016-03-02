#include <stdio.h>
#include <assert.h>

#define MAXN 1000000

int apri(int N, int F, int K[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


int K[MAXN];

int main() {
    FILE *fr, *fw;
    int N, F, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &F));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &K[i]));

    fprintf(fw, "%d\n", apri(N, F, K));
    fclose(fr);
    fclose(fw);
    return 0;
}
