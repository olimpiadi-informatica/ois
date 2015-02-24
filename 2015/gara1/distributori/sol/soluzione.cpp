#include <stdio.h>
#include <assert.h>

#define MAXN 102400

int rifornisci(int N, int M, int K, int D[]) {
    int last = 0, r = 0;
    D[N] = K;
    for (int i=0; i<N; i++) {
        if (D[i+1] > last + M) {
            last = D[i];
            r++;
        }
    }
    return r;
}


int D[MAXN];

int main() {
    FILE *fr, *fw;
    int N, M, K, i;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(3 == fscanf(fr, "%d %d %d", &N, &M, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &D[i]));

    fprintf(fw, "%d\n", rifornisci(N, M, K, D));
    fclose(fr);
    fclose(fw);
    return 0;
}
