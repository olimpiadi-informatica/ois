#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 10240
#define MAXM 102400

vector<int> Next[MAXN], vNext[MAXN];
int R;

void visita(int n, int v, int l) {
    R = max(R, l);
    for (int i=0; i<Next[n].size(); i++)
        if (vNext[n][i] > v)
            visita(Next[n][i], vNext[n][i], l+1);
}

int accelera(int N, int M, int da[], int a[], int V[]) {
    for (int i=0; i<M; i++) {
        Next[da[i]].push_back(a[i]);
        vNext[da[i]].push_back(V[i]);
    }
    for (int i=0; i<N; i++) visita(i, 0, 0);
    return R;
}


int da[MAXM], a[MAXM], V[MAXM];

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
    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<M; i++)
        assert(3 == fscanf(fr, "%d%d%d", &da[i], &a[i], &V[i]));

    fprintf(fw, "%d\n", accelera(N, M, da, a, V));
    fclose(fr);
    fclose(fw);
    return 0;
}
