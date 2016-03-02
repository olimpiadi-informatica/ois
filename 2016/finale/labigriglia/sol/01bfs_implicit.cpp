/**
 * 0-1 BFS sul grafo implicito
 */

#include <cstdio>
#include <cassert>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#define MAXN 1000

int cammina(int N, int M, int griglia[][MAXN]) {
    std::deque<std::pair<std::pair<int, int>, int>> q;
    std::vector<std::vector<int>> dist(
        2 * N, std::vector<int>(2 * M, std::numeric_limits<int>::max())
    );

    std::pair<int, int> start = {0, 0};
    std::pair<int, int> stop  = {2 * N - 1, 2 * M - 1};

    q.push_front({start, 0});

    while (!q.empty()) {
        auto tmp = q.front();
        q.pop_front();

        auto u = tmp.first;
        int w = tmp.second;

        if (dist[u.first][u.second] > w) {
            dist[u.first][u.second] = w;

            int bits = griglia[u.first / 2][u.second / 2];

            if (u.first % 2 == 0 && u.second % 2 == 0) {

                if (u.first > 0)
                    q.push_back({{u.first - 1, u.second}, w + 1});
                if (u.second > 0)
                    q.push_back({{u.first, u.second - 1}, w + 1});
                if (u.first > 0 && u.second > 0)
                    q.push_back({{u.first - 1, u.second - 1}, w + 1});

                if (!(bits & 8))
                    q.push_front({{u.first + 1, u.second}, w + 0});
                if (!(bits & 1))
                    q.push_front({{u.first, u.second + 1}, w + 0});

            } else if (u.first % 2 == 0 && u.second % 2 == 1) {

                if (u.first > 0)
                    q.push_back({{u.first - 1, u.second}, w + 1});
                if (u.second + 1 < 2 * M)
                    q.push_back({{u.first, u.second + 1}, w + 1});
                if (u.first > 0 && u.second + 1 < 2 * M)
                    q.push_back({{u.first - 1, u.second + 1}, w + 1});

                if (!(bits & 1))
                    q.push_front({{u.first, u.second - 1}, w + 0});
                if (!(bits & 2))
                    q.push_front({{u.first + 1, u.second}, w + 0});

            } else if (u.first % 2 == 1 && u.second % 2 == 0) {

                if (u.second > 0)
                    q.push_back({{u.first, u.second - 1}, w + 1});
                if (u.first + 1 < 2 * N)
                    q.push_back({{u.first + 1, u.second}, w + 1});
                if (u.second > 0 && u.first + 1 < 2 * N)
                    q.push_back({{u.first + 1, u.second - 1}, w + 1});

                if (!(bits & 8))
                    q.push_front({{u.first - 1, u.second}, w + 0});
                if (!(bits & 4))
                    q.push_front({{u.first, u.second + 1}, w + 0});

            } else {

                if (u.second + 1 < 2 * M)
                    q.push_back({{u.first, u.second + 1}, w + 1});
                if (u.first + 1 < 2 * N)
                    q.push_back({{u.first + 1, u.second}, w + 1});
                if (u.second + 1 < 2 * M && u.first + 1 < 2 * N)
                    q.push_back({{u.first + 1, u.second + 1}, w + 1});

                if (!(bits & 2))
                    q.push_front({{u.first - 1, u.second}, w + 0});
                if (!(bits & 4))
                    q.push_front({{u.first, u.second - 1}, w + 0});

            }
        }
    }

    int ans = dist[stop.first][stop.second];

    if (ans == std::numeric_limits<int>::max())
        return -1;
    else
        return 1 + ans;
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
