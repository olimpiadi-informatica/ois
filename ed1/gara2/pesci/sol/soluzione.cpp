#include <cstdio>
#include <cassert>
#include <stack>

#define MAXN 100000

typedef std::pair<int, int> ii;
int mangia(int N, int direzione[], int dimensione[]) {
    std::stack<ii> S;

    for (int i = 0; i < N; i++) {
        if (direzione[i] == 0)
            S.push(ii(direzione[i], dimensione[i]));
        else {
            while (!S.empty() && S.top().first == 0 && S.top().second < dimensione[i])
                S.pop();
            if (S.empty() || S.top().first == 1)
                S.push(ii(direzione[i], dimensione[i]));
            // else (S.top().first == 0 && S.top().second > dimensione[i])
        }
    }
    return S.size();
}


int direzione[MAXN], dimensione[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(2 == fscanf(fr, "%d%d", &direzione[i], &dimensione[i]));

    fprintf(fw, "%d\n", mangia(N, direzione, dimensione));
    fclose(fr);
    fclose(fw);
    return 0;
}
