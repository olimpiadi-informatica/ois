#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int porziona(int N, int mandorle[], int cannella[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


int mandorle[MAXN], cannella[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &mandorle[i]));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &cannella[i]));

    fprintf(fw, "%d\n", porziona(N, mandorle, cannella));
    fclose(fr);
    fclose(fw);
    return 0;
}
