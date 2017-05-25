#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int test(int N, int H[]) {
    int mode = 2; // 0: sali (>=) 1: scendi (<) 2: rampa
    int lasth = H[0];
    for (int i=0; i<N-1; i++) {
        if (mode == 0 and H[i] >= lasth) return i-1;
        if (i+1<N and H[i+1]>H[i] and H[i+1] - H[i] == H[i+2] - H[i+1]) mode = 2;
        else if (i==0 or H[i+1]<=H[i] or H[i+1] - H[i] != H[i] - H[i-1]) {
            if (mode == 2 and H[i+1] >= H[i]) return i;
            if (H[i+1] >= H[i]) mode = 0;
            if (mode != 1 and H[i+1] < H[i]) {
                mode = 1;
                lasth = H[i];
            }
        }
    }
    if (mode != 1 and H[N-1] >= lasth) return N-2;
    return N-1;
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

    fprintf(fw, "%d\n", test(N, H));
    fclose(fr);
    fclose(fw);
    return 0;
}
