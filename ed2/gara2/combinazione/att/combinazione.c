#include <stdio.h>
#include <assert.h>

#define MAXN 100000

long long premi(int N, int B[]) {
    // Mettete qui il codice della soluzione
    return 42;
}


int B[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &B[i]));

    fprintf(fw, "%lld\n", premi(N, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
