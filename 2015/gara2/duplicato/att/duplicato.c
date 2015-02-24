#include <stdio.h>
#include <assert.h>
#define MAXN 100000

int trova(int N, int P[]) {
    // Mettete qui il codice della soluzione
    return 42;
}

int P[2 * MAXN];
int main() {
    FILE *fr, *fw;
    int N, i;
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<2*N-1; i++)
        assert(1 == fscanf(fr, "%d", &P[i]));
    fprintf(fw, "%d\n", trova(N, P));
    fclose(fr);
    fclose(fw);
    return 0;
}
