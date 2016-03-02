/**
 * 0-1 BFS sul grafo esplicito
 * 
 * C'e' anche un'ottimizzazione delle liste di adiacenza che sfrutta il
 * fatto che ci sono al massimo 8 vicini per ogni nodo
 */

#include <cstdio>
#include <cassert>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#define MAXN 1000

struct {
    int size = 0;
    std::pair<int, int> list[8];
    void push_back(int a, int b) {
        list[size++] = {a, b};
    }
} adj[4 * MAXN * MAXN];

void add_edge(int a, int b, int w) {
    assert(b >= 0);

    adj[a].push_back(b, w);
    adj[b].push_back(a, w);
}

int shortest_path(int vertices) {
    std::deque<std::pair<int, int>> q;
    std::vector<int> dist(vertices, std::numeric_limits<int>::max());

    int start = 0;             // il primo nodo della prima mattonella
    int stop  = vertices - 2;  // il terzo nodo dell'ultima mattonella

    q.push_front({start, 0});

    while (!q.empty()) {
        auto tmp = q.front();
        q.pop_front();

        int u = tmp.first;
        int w = tmp.second;

        if (dist[u] > w) {
            dist[u] = w;
            for (int i = 0; i < adj[u].size; i++) {
                auto v = adj[u].list[i];
                assert(v.second == 0 || v.second == 1);

                if (dist[v.first] > dist[u] + v.second) {
                    if (v.second == 0) {
                        q.push_front({v.first, dist[u] + v.second});
                    } else {
                        q.push_back({v.first, dist[u] + v.second});
                    }
                }
            }
        }
    }

    return dist[stop];
}

int cammina(int N, int M, int griglia[][MAXN]) {
    int vertex_id = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // la mattonella (i, j) corrisponde ai 4 nodi:
            //      vertex_id + 0, vertex_id + 1,
            //      vertex_id + 2, vertex_id + 3

            // aggiungi gli archi "interni alla mattonella"
            if (!(griglia[i][j] & 1))
                add_edge(vertex_id + 0, vertex_id + 1, 0);
            if (!(griglia[i][j] & 2))
                add_edge(vertex_id + 1, vertex_id + 2, 0);
            if (!(griglia[i][j] & 4))
                add_edge(vertex_id + 2, vertex_id + 3, 0);
            if (!(griglia[i][j] & 8))
                add_edge(vertex_id + 3, vertex_id + 0, 0);

            if (j > 0) {
                // aggiungi gli archi verso la mattonella di sinistra
                add_edge(vertex_id + 0, vertex_id - 3, 1);
                add_edge(vertex_id + 3, vertex_id - 2, 1);
            }

            if (i > 0) {
                // aggiungi gli archi verso la mattonella di sopra
                add_edge(vertex_id + 0, vertex_id - 4 * M + 3, 1);
                add_edge(vertex_id + 1, vertex_id - 4 * M + 2, 1);
            }

            if (i > 0 && j > 0) {
                // aggiungi l'arco verso la mattonella in alto a sx
                add_edge(vertex_id + 0, vertex_id - 4 * M - 2, 1);
            }

            if (i > 0 && j < M - 1) {
                // aggiungi l'arco verso la mattonella in alto a dx
                add_edge(vertex_id + 1, vertex_id - 4 * M + 7, 1);
            }

            // passa ai prossimi 4 nodi
            vertex_id += 4;
        }
    }

    int ans = shortest_path(4 * M * N);
    if (ans == std::numeric_limits<int>::max())
        return -1;
    else
        return ans + 1;
}

int griglia[MAXN][MAXN];

int main() {
    FILE *fr, *fw;
    int N, M, i, j;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
            assert(1 == fscanf(fr, "%d", &griglia[i][j]));

    fprintf(fw, "%d\n", cammina(N, M, griglia));
    fclose(fr);
    fclose(fw);
    return 0;
}
