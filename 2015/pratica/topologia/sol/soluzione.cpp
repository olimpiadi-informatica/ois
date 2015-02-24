#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 100000;

int N, M;
vector<int> graph[MAXN];
bool visited[MAXN];

void dfs(int u, int& n1, int& n2, int& nb) {
    if (visited[u]) {
        return;
    } else {
        visited[u] = true;
    }
    int grado = graph[u].size();
    switch (grado) {
        case 0:
            break;
        case 1:
            n1++;
            break;
        case 2:
            n2++;
            break;
        default:
            nb++;
            break;
    }
    for (int i=0; i<grado; i++) {
        int v = graph[u][i];
        dfs(v, n1, n2, nb);
    }
}

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d%d", &N, &M);
    for (int i=0; i<M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    int n_linear = 0;
    int n_ring = 0;
    int n_star = 0;
    for (int i=0; i<N; i++) {
        if (visited[i]) continue;
        int n1 = 0; // numero di nodi con grado = 1
        int n2 = 0; // numero di nodi con grado = 2
        int nb = 0; // numero di nodi con grado > 2
        dfs(i, n1, n2, nb);
        if (!n1 && !n2 && !nb) continue;
        if (n1 == 2 && nb == 0) n_linear++;
        if (n1 == 0 && nb == 0) n_ring++;
        if (n2 == 0 && nb == 1) n_star++;
    }

    printf("%d %d %d\n", n_linear, n_ring, n_star);
}
