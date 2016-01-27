#include <stdio.h>
#include <assert.h>

#define MAXN 100000

void inizia(int N, int M[]) {
    // Mettete qui il codice della soluzione
}

int abbatti(int X, int D) {
    // Mettete qui il codice della soluzione
    return D;
}


int M[MAXN];

int main() {
    FILE *fr, *fw;
    int N, T, X, D, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &T));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &M[i]));

    inizia(N, M);
    for(i=0; i<T; i++) {
        if (i>0) fprintf(fw, " ");
        assert(2 == fscanf(fr, "%d %d", &X, &D));
        fprintf(fw, "%d", abbatti(X, D));
    }
    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}
