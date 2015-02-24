#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <limits>

using namespace std;

#define MAXN 10000

const int INF = numeric_limits<int>::max();

int scegli_domande(int K, int N, int difficolta[]) {
    sort(difficolta, difficolta + N);

    int risposta = INF;
    for (int i = 0; i <= N - K; i++)
        risposta = min(risposta, difficolta[i + K - 1] - difficolta[i]);

    return risposta;
}

int difficolta[MAXN];

int main() {
    FILE *fr, *fw;
    int K, N, i;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    
    assert(2 == fscanf(fr, "%d%d", &N, &K));
    for (i = 0; i < N; i++)
        assert(1 == fscanf(fr, "%d", &difficolta[i]));

    fprintf(fw, "%d\n", scegli_domande(K, N, difficolta));
    fclose(fr);
    fclose(fw);
    return 0;
}
