#include <stdio.h>
#include <assert.h>
#include <vector>
#include <set>

#define MAXM 100000

const int MAXN = 10000;
std::set<std::pair<int, int>> degs; // degree, node
std::vector<int> adj[MAXN];
int deg[MAXN];

int invita(int N, int M, int conoscenzeA[], int conoscenzeB[]) {
    for (int i = 0; i < M; i++) {
        int a = conoscenzeA[i], b = conoscenzeB[i];
        adj[a].push_back(b);
        adj[b].push_back(a);
        ++deg[a], ++deg[b];
    }
    for (int i = 0; i < N; i++)
        degs.insert(std::pair<int,int>(deg[i],i));

    while (!degs.empty()) {
        const auto top = *degs.begin();

        if (top.first >= 2)
            break;

        degs.erase(degs.begin());
        deg[top.second] = -1;
        for (int next: adj[top.second]) {
            if (deg[next] != -1) {
                degs.erase(degs.find(std::pair<int,int>(deg[next], next)));
                --deg[next];
                degs.insert(std::pair<int,int>(deg[next], next));
            }
        }
    }

    return degs.size();
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
