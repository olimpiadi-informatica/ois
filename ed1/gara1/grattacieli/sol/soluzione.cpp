#include <stdio.h>
#include <assert.h>

#define MAXN 100000

#define max(a,b) ((a) > (b) ? (a) : (b))

int osserva(int N, int H[]) {
    int M = H[0];
    for (int i=1; i<N; i++)
        M = max(M, H[i]);
    int imax[3] = {0, 0, 0}, ic = 1, r = 0;
    for (int i=0; i<N; i++) {
        if (i == N-1 or H[i] == M) {
            ic++;
            imax[ic%3] = i;
            r = max(r, imax[ic%3]-imax[(ic-2)%3]);
        }
    }
    return r+1;
}


int H[MAXN];

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
        assert(1 == fscanf(fr, "%d", &H[i]));

    fprintf(fw, "%d\n", osserva(N, H));
    fclose(fr);
    fclose(fw);
    return 0;
}
