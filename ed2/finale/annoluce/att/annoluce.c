#include <stdio.h>
#include <assert.h>

void mappatura(int N, int X[], int Y[], int Z[]) {
    // Mettete qui il codice della soluzione
}

int query(int D) {
    // Mettete qui il codice della soluzione
    return 42;
}


#define MAXN 100000
int X[MAXN], Y[MAXN], Z[MAXN];

int main() {
    FILE *fr, *fw;
    int N, Q, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(3 == fscanf(fr, "%d%d%d", &X[i], &Y[i], &Z[i]));

    mappatura(N, X, Y, Z);

    assert(1 == fscanf(fr, "%d", &Q));
    for(i=0; i<Q; i++) {
        int D;
        assert(1 == fscanf(fr, "%d", &D));
        fprintf(fw, "%d\n", query(D));
    }

    fclose(fr);
    fclose(fw);
    return 0;
}
