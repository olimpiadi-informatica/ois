#include <stdio.h>
#include <assert.h>

#define MAXN 10000

int passeggia(int N, int H[]) {
    int l = 1;
    H[N] = H[N-1];
    for (int i=1; i<N; i++)
        if ((H[i]-H[i-1]) * (H[i]-H[i+1]) > 0) l++;
    return l + (N>1 ? 1 : 0);
}


int H[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &H[i]));

    fprintf(fw, "%d\n", passeggia(N, H));
    fclose(fr);
    fclose(fw);
    return 0;
}
