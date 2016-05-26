#include <stdio.h>
#include <assert.h>
#include <vector>
#include <set>

#define MAXM 100000

const int MAXN = 10000;
std::set<int> adj[MAXN];

int invita(int N, int M, int conoscenzeA[], int conoscenzeB[]) {
    for (int i = 0; i < M; i++) {
        int a = conoscenzeA[i], b = conoscenzeB[i];
        adj[a].insert(b);
        adj[b].insert(a);
    }

    bool found = true;
    while (found) {
        found = false;

        for (int i = 0; i < N; i++) {
            if (adj[i].size() == 1) {
                int neig = *adj[i].begin();

                adj[neig].erase(i);
                adj[i].clear();

                found = true;
                break;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
        ans += (adj[i].size() >= 2);
    return ans;
}


int conoscenzeA[MAXM], conoscenzeB[MAXM];

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
    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d%d", &conoscenzeA[i], &conoscenzeB[i]));

    fprintf(fw, "%d\n", invita(N, M, conoscenzeA, conoscenzeB));
    fclose(fr);
    fclose(fw);
    return 0;
}
