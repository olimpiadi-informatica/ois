#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int pausa(int N, int A[], int B[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


int A[MAXN], B[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(2 == fscanf(fr, "%d %d", &A[i], &B[i]));

    fprintf(fw, "%d\n", pausa(N, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
