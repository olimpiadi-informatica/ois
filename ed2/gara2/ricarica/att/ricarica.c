#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int ricarica(int N, int M, int A[], int B[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


int A[MAXN], B[MAXN];

int main() {
    FILE *fr, *fw;
    int N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &M));
    for(i=0; i<N; i++)
        assert(2 == fscanf(fr, "%d %d", &A[i], &B[i]));

    fprintf(fw, "%d\n", ricarica(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
