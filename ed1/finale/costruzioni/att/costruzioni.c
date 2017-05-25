#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int demolisci(int N, int K, int V[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


int V[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &V[i]));

    fprintf(fw, "%d\n", demolisci(N, K, V));
    fclose(fr);
    fclose(fw);
    return 0;
}
