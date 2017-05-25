#include <stdio.h>
#include <assert.h>

int raccogli(int N, int M, int monete[], int A[], int B[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


#define MAXN 10000
#define MAXM 100000

int monete[MAXN];
int A[MAXM], B[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &monete[i]));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d%d", &A[i], &B[i]));

    fprintf(fw, "%d\n", raccogli(N, M, monete, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
