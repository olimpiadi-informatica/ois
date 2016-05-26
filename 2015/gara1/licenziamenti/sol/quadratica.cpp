#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100000
#define MAXB 1000000

int B[MAXN], C[MAXN];

int worstboss(int x) {
    if (C[x] == -1)
        return MAXB;
    return min(B[C[x]], worstboss(C[x]));
}

int licenzia(int N, int B[], int C[]) {
    int l = 0;
    for (int i=1; i<N; i++)
        if (B[i] > worstboss(i)) l++;
    return l;
}


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
        assert(2 == fscanf(fr, "%d %d", &B[i], &C[i]));
    
    fprintf(fw, "%d\n", licenzia(N, B, C));
    fclose(fr);
    fclose(fw);
    return 0;
}