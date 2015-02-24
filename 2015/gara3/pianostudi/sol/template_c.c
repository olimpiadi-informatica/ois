#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int pianifica(int N, int da[], int a[], int crediti[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


int da[MAXN], a[MAXN], crediti[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(3 == fscanf(fr, "%d%d%d", &da[i], &a[i], &crediti[i]));

    fprintf(fw, "%d\n", pianifica(N, da, a, crediti));
    fclose(fr);
    fclose(fw);
    return 0;
}
