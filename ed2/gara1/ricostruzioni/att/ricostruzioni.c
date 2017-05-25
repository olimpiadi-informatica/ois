#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int spiana(int N, int K, int A[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


int A[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &A[i]));

    fprintf(fw, "%d\n", spiana(N, K, A));
    fclose(fr);
    fclose(fw);
    return 0;
}
