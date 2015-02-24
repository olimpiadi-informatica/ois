#include <stdio.h>
#include <assert.h>

#define MAXN 1000000

int next[MAXN][10];

void bianchetta(int N, int K, int U[], int C[]) {
    for (int i = 0; i < 10; i++) next[N-1][i] = N;
    next[N - 1][U[N - 1]] = N - 1;

    for (int i = N - 2; i >= 0; i--) {
        for (int j = 0; j < 10; j++)
            next[i][j] = next[i+1][j];
        next[i][U[i]] = i;
    }

    int cur = 0;
    for (int i = 0; i < N - K; i++) {
        for (int j = 0; j < 10; j++) {
            if (N - next[cur][j] >= N - K - i) {
                C[i] = j;
                cur = next[cur][j] + 1;
                break;
            }
        }
    }
}


int U[MAXN], C[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d%d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &U[i]));

    bianchetta(N, K, U, C);
    for(i=0; i<N-K; i++)
        fprintf(fw, "%d ", C[i]);
    fprintf(fw, "\n" );
    fclose(fr);
    fclose(fw);
    return 0;
}
