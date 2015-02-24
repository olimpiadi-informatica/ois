#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 10000
#define MAXB 100000

int B[MAXN], C[MAXN];
vector< int > Dip[MAXN];

int valore(int x) {
    int v = 0;
    for (int i=0; i<Dip[x].size(); i++) {
        v += valore(Dip[x][i]);
    }
    return max(v, B[x]);
}

int recluta(int N, int B[], int C[]) {
    for (int i=1; i<N; i++) {
        Dip[C[i]].push_back(i);
    }
    return valore(0);
}


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
        assert(2 == fscanf(fr, "%d %d", &B[i], &C[i]));
    
    fprintf(fw, "%d\n", recluta(N, B, C));
    fclose(fr);
    fclose(fw);
    return 0;
}
