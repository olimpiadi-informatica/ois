#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100000
#define MAXB 1000000

int B[MAXN], C[MAXN];
vector< int > Dip[MAXN];

int controlla(int x, int bmin) {
    int l = B[x] > bmin ? 1 : 0;
    bmin = min(bmin , B[x]);
    for (int i=0; i<Dip[x].size(); i++) {
        l += controlla(Dip[x][i], bmin);
    }
    return l;
}

int licenzia(int N, int B[], int C[]) {
    for (int i=1; i<N; i++) {
        Dip[C[i]].push_back(i);
    }
    return controlla(0, MAXB);
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
    
    fprintf(fw, "%d\n", licenzia(N, B, C));
    fclose(fr);
    fclose(fw);
    return 0;
}
