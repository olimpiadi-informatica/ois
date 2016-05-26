#include <stdio.h>
#include <assert.h>
#include <algorithm>

using namespace std;

#define MAXN 100000

int ricarica(int N, int M, int A[], int B[]) {
    int xprev = 0, iprev = 1;
    for (int i=0; i<N; i++) {
        xprev -= A[i] - iprev;
        xprev += B[i]-A[i]+1;
        iprev = B[i]+1;
    }
    xprev -= M+1 - iprev;
    return 1-xprev;
}


int A[MAXN], B[MAXN];

int main() {
    FILE *fr, *fw;
    int N, M, i;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d %d", &N, &M));
    for(i=0; i<N; i++)
        assert(2 == fscanf(fr, "%d %d", &A[i], &B[i]));

    fprintf(fw, "%d\n", ricarica(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
