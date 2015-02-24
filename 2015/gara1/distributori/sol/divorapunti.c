#include <stdio.h>
#include <assert.h>

#define MAXN 100000

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

int rifornisci(int N, int M, int K) {
    return min((K-1)/max(M-K/2/N,1),N);
}


int main() {
    FILE *fr, *fw;
    int N, M, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(3 == fscanf(fr, "%d %d %d", &N, &M, &K));

    fprintf(fw, "%d\n", rifornisci(N, M, K));
    fclose(fr);
    fclose(fw);
    return 0;
}
