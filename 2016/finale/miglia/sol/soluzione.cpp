#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>

#define MAXM 10000

using namespace std;

int D[MAXM][2];
vector<vector<pair<int,int>>> G;

int vola(int K, int N, int M, int da[], int a[], int V[]) {
    G.resize(N);
    for (int i=0; i<M; i++)
        G[da[i]].push_back(make_pair(a[i],V[i]));
    D[0][0] = 0;
    for (int i=1; i<N; i++) D[i][0] = -1;
    for (int j=1; j<=K; j++) {
        for (int i=0; i<N; i++)
            D[i][j%2] = -1;
        for (int i=0; i<N; i++)
            if (D[i][1-j%2] >= 0)
                for (int x=0; x<G[i].size(); x++)
                    D[G[i][x].first][j%2] = max(D[G[i][x].first][j%2], D[i][1-j%2] + G[i][x].second);
    }
    return D[0][K%2];
}


int da[MAXM];
int a[MAXM];
int V[MAXM];

int main() {
    FILE *fr, *fw;
    int K, N, M, i;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(3 == fscanf(fr, "%d %d %d", &K, &N, &M));
    for(i=0; i<M; i++)
        assert(3 == fscanf(fr, "%d %d %d", &da[i], &a[i], &V[i]));

    fprintf(fw, "%d\n", vola(K, N, M, da, a, V));
    fclose(fr);
    fclose(fw);
    return 0;
}
