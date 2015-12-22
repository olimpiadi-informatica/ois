#include <stdio.h>
#include <assert.h>

#define MAXN 1000000

int falsifica(int N, char Q[], int A[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


char Q[MAXN];
int  A[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    Q[0] = 'X';
    A[0] = -1;
    for(i=1; i<N; i++) {
        assert(1 == fscanf(fr, " %c", &Q[i]));
        assert(1 == fscanf(fr, "%d", &A[i]));
    }

    fprintf(fw, "%d\n", falsifica(N, Q, A));
    fclose(fr);
    fclose(fw);
    return 0;
}
