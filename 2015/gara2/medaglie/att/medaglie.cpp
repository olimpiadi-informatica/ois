#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int gioca(int N, short M[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


short M[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%hd", &M[i]));

    fprintf(fw, "%d\n", gioca(N, M));
    fclose(fr);
    fclose(fw);
    return 0;
}
