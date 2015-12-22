#include <stdio.h>
#include <assert.h>

#define MAXN 10000
#define MAXM 100000

int conta(int N, int M, int B[], int da[], int a[]) {
    int r=0;
    for (int i=0; i<M; i++)
        if (B[da[i]] and B[a[i]]) r++;
    return r;
}


int B[MAXN];
int da[MAXM];
int a[MAXM];

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
    assert(2 == fscanf(fr, "%d %d", &N, &M));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &B[i]));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d %d", &da[i], &a[i]));

    fprintf(fw, "%d\n", conta(N, M, B, da, a));
    fclose(fr);
    fclose(fw);
    return 0;
}
