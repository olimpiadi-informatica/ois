#include <stdio.h>
#include <assert.h>

#define MAXM 100000

void analizza(int N, int M, int *A, int *B, int *T) {
    T[0] = T[1] = T[2] = 42;
}


int A[MAXM], B[MAXM], T[3];

int main() {
    FILE *fr, *fw;
    int N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d%d", A+i, B+i));

    analizza(N, M, A, B, T);
    fprintf(fw, "%d %d %d\n", T[0], T[1], T[2]);
    fclose(fr);
    fclose(fw);
    return 0;
}
