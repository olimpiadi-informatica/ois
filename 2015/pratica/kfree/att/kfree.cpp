#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int trova(int N, int K, int *insieme) {
    // Mettete qui il codice della soluzione
    return 42;
}


int insieme[MAXN+1];

int main(){
    FILE *fr, *fw;
    int N, K, i;
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(2 == fscanf(fr, "%d %d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", insieme+i));

    fprintf(fw, "%d\n", trova(N, K, insieme));

    fclose(fr);
    fclose(fw);
    return 0;
}
