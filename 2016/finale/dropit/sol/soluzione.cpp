#include <stdio.h>
#include <assert.h>

#define MAXN 100000
#define MAXM 2*MAXN

int cadi(int N, int L[], int P[]) {
    int M = 1;
    P[0] = L[0];
    for (int i=1; i<N; i++) {
        //for (int j=0; j<M; j++) printf("%d ", P[j]);
        //printf(" <-- %d\n", L[i]);
        while (M > 0 and L[i] > P[M-1]) {
            L[i] -= P[M-1];
            P[M-1] = 0;
            M--;
            //printf(" |_ ");
            //for (int j=0; j<M; j++) printf("%d ", P[j]);
            //printf(" <<= %d\n", L[i]);
        }
        if (M > 0 and L[i] == P[M-1]) M--;
        else {
            P[M] = L[i];
            M++;
            if (M > 1) {
                P[M] = P[M-2] - P[M-1];
                M++;
            }
        }
    }
    return M;
}


int L[MAXN];
int P[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, i;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &L[i]));

    M = cadi(N, L, P);
    fprintf(fw, "%d\n", M);
    for(i=0; i<M-1; i++)
        fprintf(fw, "%d ", P[i]);
    fprintf(fw, "%d\n", P[M-1]);
    fclose(fr);
    fclose(fw);
    return 0;
}
