#include <stdio.h>
#include <assert.h>

#define MAXN 5000
#define MAXK 5000
#define MAXP 1000000

int mangia(int N, int K, int P[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


int P[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &P[i]));

    fprintf(fw, "%d\n", mangia(N, K, P));
    fclose(fr);
    fclose(fw);
    return 0;
}
