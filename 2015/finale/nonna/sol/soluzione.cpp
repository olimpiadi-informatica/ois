#include <stdio.h>
#include <assert.h>
#include <algorithm>

using namespace std;

#define MAXN 5000
#define MAXK 5000
#define MAXP 1000000

int P[MAXN], U[MAXK];


int mangia(int N, int K, int P[]) {
    int maxu = 0, R = MAXP;

    U[0] = 1;
    sort(P, P+N);
    for (int i=0; i<N; i++)
        for (int j=maxu; j>=0; j--) if (U[j] == 1) {
            if (j+P[i] >= K) R = min(R, j+P[i]);
            else {
                if (j+P[i] > maxu) maxu = j+P[i];
                U[j+P[i]] = 1;
            }
        }
    return R;
}


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
    assert(2 == fscanf(fr, "%d %d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &P[i]));

    fprintf(fw, "%d\n", mangia(N, K, P));
    fclose(fr);
    fclose(fw);
    return 0;
}
