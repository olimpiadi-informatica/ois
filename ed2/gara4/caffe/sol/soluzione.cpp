#include <stdio.h>
#include <assert.h>
#include <algorithm>

using namespace std;

#define MAXN 100000

int T[2*MAXN];

int pausa(int N, int A[], int B[]) {
    for (int i=0; i<N; i++) T[i] = 2*A[i]+1;
    for (int i=0; i<N; i++) T[N+i] = 2*B[i];
    sort(T, T+2*N);
    for (int i=0; i<2*N; i++) T[i] %= 2;
    int c = 0, tot = 0;
    for (int i=0; i<2*N; i++)
        if (T[i]) tot += (++c);
        else --c;
    return tot;
}


int A[MAXN], B[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(2 == fscanf(fr, "%d %d", &A[i], &B[i]));

    fprintf(fw, "%d\n", pausa(N, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
