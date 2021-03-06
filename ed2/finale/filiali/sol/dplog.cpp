#include <stdio.h>
#include <assert.h>
#include <algorithm>

#define MAXN 1000000

using namespace std;


int D[MAXN][2];
int K[MAXN];


int apri(int N, int F, int K[]) {
    for (int n = 0; n < N; n++) D[n][0] = K[n]-K[0];
    for (int f = 3; f <= F; f++) {
        for (int n = 0; n < N; n++) {
            D[n][f%2] = 0;
            int a = f-2, b = n-1, m;
            while (a+1 < b) {
                m = (a+b)/2;
                D[n][f%2] = max(min(D[m][1-f%2],K[n]-K[m]), D[n][f%2]);
                if (D[m][1-f%2] == K[n]-K[m]) break;
                if (D[m][1-f%2] < K[n]-K[m]) a = m;
                else b = m;
            }
            if (a == f-2 and a < n) D[n][f%2] = max(min(D[a][1-f%2],K[n]-K[a]), D[n][f%2]);
            if (b == n-1 and b > a) D[n][f%2] = max(min(D[b][1-f%2],K[n]-K[b]), D[n][f%2]);
        }
    }
    return D[N-1][F%2];
}


int main() {
    FILE *fr, *fw;
    int N, F, i;
    
#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d %d", &N, &F));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &K[i]));
    
    fprintf(fw, "%d\n", apri(N, F, K));
    fclose(fr);
    fclose(fw);
    return 0;
}
