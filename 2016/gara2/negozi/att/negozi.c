#include <stdio.h>
#include <assert.h>

#define MAXN 100000
#define MAXQ 100000

void risolvi(int N, int Q, int t[], int a[], int b[], int d[]) {
    // Mettete qui il codice della soluzione
    int i;
    for (i=0; i<Q; i++) {
        d[i] = 42;
    }
}


int t[MAXN], a[MAXQ], b[MAXQ], d[MAXQ];

int main() {
    FILE *fr, *fw;
    int N, Q, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &Q));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &t[i]));
    for(i=0; i<Q; i++)
        assert(2 == fscanf(fr, "%d%d", &a[i], &b[i]));

    risolvi(N, Q, t, a, b, d);

    for(i=0; i<Q; i++)
        fprintf(fw, "%d\n", d[i]);
    fclose(fr);
    fclose(fw);
    return 0;
}
